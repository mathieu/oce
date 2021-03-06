// File:	FairCurve_MinimalVariation.cxx
// Created:	Mon Feb 26 13:54:16 1996
// Author:	Philippe MANGIN


#ifndef DEB
#define No_Standard_RangeError
#define No_Standard_OutOfRange
#endif

#include <FairCurve_MinimalVariation.ixx>

#include <BSplCLib.hxx>
#include <PLib.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <FairCurve_BattenLaw.hxx>
#include <FairCurve_EnergyOfMVC.hxx>
#include <FairCurve_Newton.hxx>
#include <math_Matrix.hxx>
#include <Precision.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>

//======================================================================================
FairCurve_MinimalVariation::FairCurve_MinimalVariation(const gp_Pnt2d& P1,
						       const gp_Pnt2d& P2, 
						       const Standard_Real Heigth,
						       const Standard_Real Slope,
						       const Standard_Real PhysicalRatio)
//======================================================================================
                                       :FairCurve_Batten(P1, P2, Heigth, Slope),
					OldCurvature1(0), OldCurvature2(0),
                                        OldPhysicalRatio(PhysicalRatio),
					NewCurvature1(0),  NewCurvature2(0),  
					NewPhysicalRatio(PhysicalRatio)
{
}

//======================================================================================
Standard_Boolean FairCurve_MinimalVariation::Compute(FairCurve_AnalysisCode& ACode,
						     const Standard_Integer NbIterations,
						     const Standard_Real Tolerance)
//======================================================================================
{
  Standard_Boolean Ok=Standard_True, End=Standard_False;
  Standard_Real AngleMax = 0.7;      // parametre reglant la fonction d'increment 
                                     // ( 40 degrees )
  Standard_Real AngleMin = 2*PI/100; // parametre reglant la fonction d'increment 
                                     // un tour complet ne doit pas couter plus de 
                                     // 100 pas.
  Standard_Real DAngle1, DAngle2,  DRho1, DRho2, Ratio, Fraction, Toler;
  Standard_Real OldDist, NewDist;

//  Boucle d'Homotopie : calcul du pas et optimisation 

  while (Ok && !End) {
     DAngle1 = NewAngle1-OldAngle1;
     DAngle2 = NewAngle2-OldAngle2;
     DRho1 = NewCurvature1 - OldCurvature1;
     DRho2 = NewCurvature2 - OldCurvature2;
     Ratio = 1;

     if (NewConstraintOrder1>0) {
        Fraction = Abs(DAngle1) / (AngleMax * Exp (-Abs(OldAngle1)/AngleMax) + AngleMin);
        if (Fraction > 1) Ratio = 1 / Fraction;
     }
     if (NewConstraintOrder2>0) {
        Fraction = Abs(DAngle2) / (AngleMax * Exp (-Abs(OldAngle2)/AngleMax) + AngleMin);
        if (Fraction > 1)  Ratio = (Ratio < 1 / Fraction ? Ratio : 1 / Fraction);
     }
     
     OldDist = OldP1.Distance(OldP2);
     NewDist = NewP1.Distance(NewP2);
     Fraction = Abs(OldDist-NewDist) / (OldDist/3);
     if ( Fraction > 1) Ratio = (Ratio < 1 / Fraction ? Ratio : 1 / Fraction); 

     if (NewConstraintOrder1>1) {
       Fraction = Abs(DRho1)*OldDist / (2+Abs(OldAngle1) + Abs(OldAngle2));   
       if ( Fraction > 1) Ratio = (Ratio < 1 / Fraction ? Ratio : 1 / Fraction);
     }

     if (NewConstraintOrder2>1) {
       Fraction = Abs(DRho2)*OldDist/ (2+Abs(OldAngle1) + Abs(OldAngle2));   
       if ( Fraction > 1) Ratio = (Ratio < 1 / Fraction ? Ratio : 1 / Fraction); 
     }

     gp_Vec2d DeltaP1(OldP1, NewP1) , DeltaP2(OldP2, NewP2);
     if ( Ratio == 1) {
        End = Standard_True;
        Toler = Tolerance;
      }
     else {
       DeltaP1 *= Ratio;
       DeltaP2 *= Ratio;
       DAngle1 *= Ratio;
       DAngle2 *= Ratio;
       DRho1 *= Ratio;
       DRho2 *= Ratio;
       Toler =  10 * Tolerance;
     }
 
     Ok = Compute( DeltaP1, DeltaP2, 
	           DAngle1, DAngle2,
		   DRho1,   DRho2,           
	           ACode,
                   NbIterations,
                   Toler);

     if (ACode != FairCurve_OK) End = Standard_True;
     if (NewFreeSliding) NewSlidingFactor = OldSlidingFactor;
     if (NewConstraintOrder1 == 0) NewAngle1 = OldAngle1;
     if (NewConstraintOrder1 < 2)  NewCurvature1 = OldCurvature1;
     if (NewConstraintOrder2 == 0) NewAngle2 = OldAngle2; 
     if (NewConstraintOrder2 < 2)  NewCurvature2 = OldCurvature2;
  }
  myCode = ACode; 
  return Ok;
}

//======================================================================================
Standard_Boolean FairCurve_MinimalVariation::Compute(const gp_Vec2d& DeltaP1,
						     const gp_Vec2d& DeltaP2,
						     const Standard_Real DeltaAngle1,
						     const Standard_Real DeltaAngle2,
						     const Standard_Real DeltaCurvature1,
						     const Standard_Real DeltaCurvature2,
						           FairCurve_AnalysisCode& ACode,
						     const Standard_Integer NbIterations,
						     const Standard_Real Tolerance)
//======================================================================================
{
 Standard_Boolean Ok, OkCompute=Standard_True;
 ACode = FairCurve_OK;

// Deformation de la courbe par ajout d'un polynome d'interpolation
   Standard_Integer L = 2 + NewConstraintOrder1 + NewConstraintOrder2,
                    kk, ii;
//                    NbP1 = Poles->Length()-1, kk, ii;
#ifdef DEB
   Standard_Integer NbP1 = 
#endif
                           Poles->Length() ;
#ifdef DEB
   NbP1 = NbP1 - 1 ;
#endif
   TColStd_Array1OfReal knots (1,2);
   knots(1) = 0;
   knots(2) = 1;
   TColStd_Array1OfInteger mults (1,2);
   TColgp_Array1OfPnt2d HermitePoles(1,L);
   TColgp_Array1OfPnt2d Interpolation(1,L);
   Handle(TColgp_HArray1OfPnt2d) NPoles = new  TColgp_HArray1OfPnt2d(1, Poles->Length());

// Polynomes d'Hermites
   math_Matrix HermiteCoef(1, L, 1, L);
   Ok = PLib::HermiteCoefficients(0,1, NewConstraintOrder1,  NewConstraintOrder2,
                                  HermiteCoef);
   if (!Ok) return Standard_False;

// Definition des contraintes d'interpolation
   TColgp_Array1OfXY ADelta(1,L);
   gp_Vec2d VOld(OldP1, OldP2), VNew( -(OldP1.XY()+DeltaP1.XY()) + (OldP2.XY()+DeltaP2.XY()) );
   Standard_Real DAngleRef = VNew.Angle(VOld);
   Standard_Real DAngle1 = DeltaAngle1 - DAngleRef,
                 DAngle2 = DAngleRef   - DeltaAngle2; // Correction du Delta par le Delta induit par les points.


   ADelta(1) = DeltaP1.XY();
   kk = 2;
   if (NewConstraintOrder1>0) {
      // rotation de la derive premiereDeltaAngle1
      gp_Vec2d OldDerive( Poles->Value(Poles->Lower()), 
                          Poles->Value(Poles->Lower()+1) );
      OldDerive *= Degree / (Knots->Value(Knots->Lower()+1)-Knots->Value(Knots->Lower()) ); 
      ADelta(kk) = (OldDerive.Rotated(DAngle1) -  OldDerive).XY();
      kk += 1;
   
      if (NewConstraintOrder1>1) {
	 // rotation de la derive seconde + ajout 
         gp_Vec2d OldSeconde( Poles->Value(Poles->Lower()).XY() + Poles->Value(Poles->Lower()+2).XY()  
                            - 2*Poles->Value(Poles->Lower()+1).XY() );
         OldSeconde *=  Degree*( Degree-1)
	             /  pow (Knots->Value(Knots->Lower()+1)-Knots->Value(Knots->Lower()), 2);
         Standard_Real CPrim = OldDerive.Magnitude();
         ADelta(kk) = ( OldSeconde.Rotated(DAngle1) -  OldSeconde 
		      + DeltaCurvature1*CPrim*OldDerive.Rotated(PI/2+DAngle1) ).XY();
         kk += 1;
      }
   }
   ADelta(kk) = DeltaP2.XY();
   kk += 1;  
   if (NewConstraintOrder2>0) {
      gp_Vec2d OldDerive( Poles->Value(Poles->Upper()-1), 
                          Poles->Value(Poles->Upper()) );
      OldDerive *= Degree / (Knots->Value(Knots->Upper()) - Knots->Value(Knots->Upper()-1) );
      ADelta(kk) = (OldDerive.Rotated(DAngle2) -  OldDerive).XY();
      kk += 1;
      if (NewConstraintOrder2>1) {
	 // rotation de la derive seconde + ajout 
         gp_Vec2d OldSeconde( Poles->Value(Poles->Upper()).XY() + Poles->Value(Poles->Upper()-2).XY()  
                            - 2*Poles->Value(Poles->Upper()-1).XY() );
         OldSeconde *=  Degree*( Degree-1)
	             /  pow (Knots->Value(Knots->Upper())-Knots->Value(Knots->Upper()-1), 2);
         Standard_Real CPrim = OldDerive.Magnitude();
         ADelta(kk) = ( OldSeconde.Rotated(DAngle2) -  OldSeconde 
		      + DeltaCurvature2*CPrim*OldDerive.Rotated(PI/2+DAngle2) ).XY();
         kk += 1;
      }
   }

// Interpolation
  gp_XY AuxXY (0,0);
  for (ii=1; ii<=L; ii++) {
      AuxXY.SetCoord(0.0, 0);
      for (kk=1; kk<=L; kk++) {
          AuxXY +=  HermiteCoef(kk, ii) * ADelta(kk);       
      }
      Interpolation(ii).SetXY(AuxXY);
  }
// Conversion en BSpline de meme structure que le batten courant.
  PLib::CoefficientsPoles(Interpolation,  PLib::NoWeights(), 
                          HermitePoles,  PLib::NoWeights()); 

  mults.Init(L);

  Handle(Geom2d_BSplineCurve) DeltaCurve = 
    new  Geom2d_BSplineCurve( HermitePoles, 
                              knots, mults, L-1);

  DeltaCurve->IncreaseDegree(Degree);
  if (Mults->Length()>2) {
     DeltaCurve->InsertKnots(Knots->Array1(), Mults->Array1(), 1.e-10);
  }

// Sommation
  DeltaCurve->Poles( NPoles->ChangeArray1() );
  for (kk= NPoles->Lower(); kk<=NPoles->Upper(); kk++) { 
     NPoles->ChangeValue(kk).ChangeCoord() += Poles->Value(kk).Coord(); 
   }

// Donnees intermediaires

 Standard_Real Angle1, Angle2, SlidingLength, 
               Alph1 =  OldAngle1 + DeltaAngle1, 
               Alph2 =  OldAngle2 + DeltaAngle2,
               Rho1 =   OldCurvature1 + DeltaCurvature1,
               Rho2 =   OldCurvature2 + DeltaCurvature2,
               Dist  =  NPoles->Value(NPoles->Upper()) 
                      . Distance( NPoles->Value( NPoles->Lower() ) ),
	       LReference = SlidingOfReference(Dist, Alph1, Alph2);
 gp_Vec2d Ox(1, 0),
                P1P2 (  NPoles->Value(NPoles->Upper()).Coord()
                      - NPoles->Value(NPoles->Lower()).Coord() );

// Angles par rapport a l'axe ox

 Angle1 =  Ox.Angle(P1P2) + Alph1;
 Angle2 = -Ox.Angle(P1P2) + Alph2;

// Calcul de la longeur de glissement (impose ou intiale);
 
 if (!NewFreeSliding) {
    SlidingLength = NewSlidingFactor * LReference;
  }
 else {
   if (OldFreeSliding) {
     SlidingLength = OldSlidingFactor *  LReference;
   }
   else {
     SlidingLength = SlidingOfReference(Dist, Alph1, Alph2);
   }
 }


     
// Energie et vecteurs d'initialisation
 FairCurve_BattenLaw LBatten (NewHeight, NewSlope, SlidingLength ); 
 FairCurve_EnergyOfMVC EMVC (Degree+1, Flatknots, NPoles,  
			     NewConstraintOrder1,  NewConstraintOrder2, 
			     LBatten, NewPhysicalRatio, SlidingLength, NewFreeSliding,
                             Angle1, Angle2, Rho1, Rho2);
 math_Vector VInit (1, EMVC.NbVariables());

 // La valeur ci-dessous donne une idee de la plus petie valeur propre
 //   du critere de flexion.
 Standard_Real VConvex = 0.01 * pow(NewHeight / SlidingLength, 3);
 if (VConvex < 1.e-12) {VConvex = 1.e-12;}

 Ok = EMVC.Variable(VInit);
 
// Minimisation
 FairCurve_Newton Newton(EMVC,
			 Tolerance*(P1P2.Magnitude()/10),
			 Tolerance,
			 NbIterations,
			 VConvex);
 Newton.Perform(EMVC, VInit);
 Ok = Newton.IsDone();
 
 if (Ok) {
    gp_Vec2d Tangente, PseudoNormale;
    Poles = NPoles;
    Newton.Location(VInit);

    if (NewFreeSliding) { OldSlidingFactor = VInit(VInit.Upper()) / LReference;}
    else                { OldSlidingFactor = NewSlidingFactor; }

    if (NewConstraintOrder1 < 2) {
       Tangente.SetXY(  Poles->Value(Poles->Lower()+1).XY()
                      - Poles->Value(Poles->Lower()).XY() );

       if (NewConstraintOrder1 == 0) {OldAngle1 = P1P2.Angle(Tangente);}
       else {OldAngle1 = Alph1;}

       PseudoNormale.SetXY ( Poles->Value(Poles->Lower()).XY()
                            - 2 * Poles->Value(Poles->Lower()+1).XY()
		            + Poles->Value(Poles->Lower()+2).XY());
       OldCurvature1 = (((double)Degree-1) /Degree) * (Tangente.Normalized()^PseudoNormale)
	               / Tangente.SquareMagnitude();
     }
    else {OldCurvature1 = Rho1;
	  OldAngle1 = Alph1; }

    if (NewConstraintOrder2 < 2) {
       Tangente.SetXY ( Poles->Value(Poles->Upper()).XY()
                      - Poles->Value(Poles->Upper()-1).XY() );
       if (NewConstraintOrder2 == 0) OldAngle2 = (-Tangente).Angle(-P1P2);
       else { OldAngle2 = Alph2;}
       PseudoNormale.SetXY ( Poles->Value(Poles->Upper()).XY()
                            - 2 * Poles->Value(Poles->Upper()-1).XY()
		            + Poles->Value(Poles->Upper()-2).XY());
       OldCurvature2 = (((double)Degree-1) /Degree) * (Tangente.Normalized()^PseudoNormale)
	             / Tangente.SquareMagnitude();
     }
    else { OldAngle2 = Alph2;
	   OldCurvature2 = Rho2;
    }

    OldP1 = Poles->Value(Poles->Lower());
    OldP2 = Poles->Value(Poles->Upper());
    OldConstraintOrder1 = NewConstraintOrder1;
    OldConstraintOrder2 = NewConstraintOrder2;
    OldFreeSliding      = NewFreeSliding;
    OldSlope = NewSlope;
    OldHeight = NewHeight;
    OldPhysicalRatio =  NewPhysicalRatio;
  }
  else {
    Standard_Real V;
    ACode = EMVC.Status();
    if (!LBatten.Value(0, V) || !LBatten.Value(1, V)) {
       ACode = FairCurve_NullHeight;
    }
    else { OkCompute = Standard_False;}
    return OkCompute;
  }

 Ok = EMVC.Variable(VInit);

 // Traitement de la non convergence
 if (!Newton.IsConverged()) {
    ACode = FairCurve_NotConverged;
  }


 // Prevention du glissement infinie
 if (NewFreeSliding &&  VInit(VInit.Upper()) > 2*LReference) ACode = FairCurve_InfiniteSliding;  
    

// Insertion eventuelle de Noeuds
 Standard_Boolean  NewKnots = Standard_False;
 Standard_Integer NbKnots = Knots->Length();
 Standard_Real ValAngles = (Abs(OldAngle1) +  Abs(OldAngle2) 
                         + 2 * Abs(OldAngle2 - OldAngle1) ) ;
 while ( ValAngles > (2*(NbKnots-2) + 1)*(1+2*NbKnots) ) {
   NewKnots = Standard_True;
   NbKnots += NbKnots-1;
 }

 if  (NewKnots) {  
   Handle(Geom2d_BSplineCurve) NewBS = 
    new  Geom2d_BSplineCurve( NPoles->Array1(), Knots->Array1(), 
			      Mults->Array1(), Degree);

   Handle(TColStd_HArray1OfInteger) NMults  =
      new TColStd_HArray1OfInteger (1,NbKnots);
   NMults->Init(Degree-3);

    Handle(TColStd_HArray1OfReal) NKnots  =
      new TColStd_HArray1OfReal (1,NbKnots);
   for (ii=1; ii<=NbKnots; ii++) {
       NKnots->ChangeValue(ii) = (double) (ii-1) / (NbKnots-1);
   } 

   NewBS -> InsertKnots(NKnots->Array1(), NMults->Array1(), 1.e-10);
   Handle(TColgp_HArray1OfPnt2d) NPoles = 
      new  TColgp_HArray1OfPnt2d(1, NewBS->NbPoles());
   NewBS -> Poles( NPoles->ChangeArray1() );
   NewBS -> Multiplicities( NMults->ChangeArray1() );
   NewBS -> Knots( NKnots->ChangeArray1() );
   Handle(TColStd_HArray1OfReal) FKnots  =
      new TColStd_HArray1OfReal (1, NewBS->NbPoles() + Degree+1);
   NewBS -> KnotSequence( FKnots->ChangeArray1()); 

   Poles = NPoles;
   Mults = NMults;
   Knots = NKnots;
   Flatknots = FKnots;		      
 } 


// Pour d'eventuelle debug
//  Newton.Dump(cout);
   
 return OkCompute;
} 


//======================================================================================
void FairCurve_MinimalVariation::Dump(Standard_OStream& o) const 
//======================================================================================
{

o << "  MVCurve      |"; o.width(7); o<< "Old " << " | " << "  New" << endl;
o << "  P1    X      |"; o.width(7); o<<  OldP1.X() << " | " << NewP1.X() << endl;
o << "        Y      |"; o.width(7); o<<  OldP1.Y() << " | " << NewP1.Y() << endl;
o << "  P2    X      |"; o.width(7); o<<  OldP2.X() << " | " << NewP2.X() << endl;
o << "        Y      |"; o.width(7); o<<  OldP2.Y() << " | " << NewP2.Y() << endl;
o << "      Angle1   |"; o.width(7); o<<  OldAngle1 << " | " << NewAngle1 << endl;
o << "      Angle2   |"; o.width(7); o<<  OldAngle2 << " | " << NewAngle2 << endl;
o << " Curvature1    |"; o.width(7); o<<  OldCurvature1 << " | " << NewCurvature1 << endl;
o << " Curvature2    |"; o.width(7); o<<  OldCurvature2 << " | " << NewCurvature2 << endl;
o << "      Height   |"; o.width(7); o<<  OldHeight << " | " << NewHeight << endl;
o << "      Slope    |"; o.width(7); o<<  OldSlope  << " | " << NewSlope << endl; 
o << " PhysicalRatio |"; o.width(7); o<<  OldPhysicalRatio << " | " << NewPhysicalRatio << endl;
o << " SlidingFactor |"; o.width(7); o<<  OldSlidingFactor << " | " << NewSlidingFactor << endl;
o << " FreeSliding   |"; o.width(7); o<<  OldFreeSliding << " | " << NewFreeSliding << endl; 
o << " ConstrOrder1  |"; o.width(7); o<<  OldConstraintOrder1 << " | " << NewConstraintOrder1 << endl; 
o << " ConstrOrder2  |"; o.width(7); o<<  OldConstraintOrder2 << " | " << NewConstraintOrder2 << endl;
 switch (myCode) {
   case  FairCurve_OK : 
     o << "AnalysisCode : Ok" << endl;
     break;
   case  FairCurve_NotConverged : 
     o << "AnalysisCode : NotConverged" << endl;
     break;
   case  FairCurve_InfiniteSliding : 
     o << "AnalysisCode : InfiniteSliding" << endl;
     break;
   case  FairCurve_NullHeight : 
     o << "AnalysisCode : NullHeight" << endl;
     break;
     }   
}










