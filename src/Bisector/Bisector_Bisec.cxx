// File:	Bisector_Bisec.cxx
// Created:	Mon Jul  4 10:05:48 1994
// Author:	Yves FRICAUD
//		<yfr@phobox>

#include <Bisector_Bisec.ixx>
#include <Bisector.hxx>
#include <Geom2d_Circle.hxx>
#include <Geom2d_Line.hxx>
#include <Geom2d_Point.hxx>
#include <Geom2d_CartesianPoint.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <gp.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <StdFail_NotDone.hxx>
#include <Standard_NotImplemented.hxx>
#include <Precision.hxx>
#include <Bisector_Curve.hxx>
#include <Bisector_BisecAna.hxx>
#include <Bisector_BisecPC.hxx>
#include <Bisector_BisecCC.hxx>

/*
#include <DrawTrSurf.hxx>
static char tname[100];
static Standard_CString name = tname ;
static Standard_Integer nbb  = 0;
*/

#ifdef DEB
static Standard_Boolean  PointIsOnCurve(const Handle(Geom2d_Curve)& C,
					const gp_Pnt2d&             P,
					      Standard_Real&        U);
#endif
static Standard_Boolean IsMaxRC (const Handle(Geom2d_Curve)& C,
				       Standard_Real         U,
        			       Standard_Real&        R);

static void ReplaceByLineIfIsToSmall (Handle(Geom2d_Curve)& Bis,
				      Standard_Real&        UFirst,
				      Standard_Real&        ULast);					
//=============================================================================
//function : Constructeur vide                                                
//=============================================================================
Bisector_Bisec::Bisector_Bisec()
{
}

//===========================================================================
//    calcul de la bissectrice entre deux courbes issue d un point.         
//                                                                          
//   afirstcurve   : \ courbes entre lesquelles on veut calculer la         
//   asecondcurve  : / bissectrice.                                         
//   apoint        :   point par lequel doit passer la bissectrice.         
//   afirstvector  : \ vecteurs pour determiner le secteur dans lequel      
//   asecondvector : / la bissectrice doit se trouver.                      
//   adirection    :   indique le cote de la bissectrice a conserver.       
//   tolerance     :   seuil a partir duquel les bisectrices sont degenerees
//===========================================================================

void Bisector_Bisec::Perform(const Handle(Geom2d_Curve)& afirstcurve   ,
			     const Handle(Geom2d_Curve)& asecondcurve  ,
			     const gp_Pnt2d&             apoint        ,
			     const gp_Vec2d&             afirstvector  ,
			     const gp_Vec2d&             asecondvector ,
			     const Standard_Real         adirection    ,
			     const Standard_Real         tolerance     ,
			     const Standard_Boolean      oncurve       )
{
  Handle(Standard_Type)  Type1 = afirstcurve ->DynamicType();
  Handle(Standard_Type)  Type2 = asecondcurve->DynamicType();
  Handle(Bisector_Curve) Bis;
  Standard_Real          UFirst,ULast;
  
  if (Type1 == STANDARD_TYPE(Geom2d_TrimmedCurve)) {
    Type1 = Handle(Geom2d_TrimmedCurve)::DownCast(afirstcurve)
            ->BasisCurve()->DynamicType();
  }
  if (Type2 == STANDARD_TYPE(Geom2d_TrimmedCurve)) {
    Type2 = Handle(Geom2d_TrimmedCurve)::DownCast(asecondcurve)
            ->BasisCurve()->DynamicType();
  }

  if ( (Type1 == STANDARD_TYPE(Geom2d_Circle) || Type1 == STANDARD_TYPE(Geom2d_Line)) &&
       (Type2 == STANDARD_TYPE(Geom2d_Circle) || Type2 == STANDARD_TYPE(Geom2d_Line))   ) {    
    //------------------------------------------------------------------
    // Bissectrice analytique.
    //------------------------------------------------------------------
     Handle(Bisector_BisecAna) BisAna = new Bisector_BisecAna();
     BisAna->Perform(afirstcurve   ,
		     asecondcurve  ,
		     apoint        ,
		     afirstvector  ,
		     asecondvector ,
		     adirection    ,
		     tolerance     ,
		     oncurve       );
     UFirst = BisAna->ParameterOfStartPoint();
     ULast  = BisAna->ParameterOfEndPoint();    
     Bis = BisAna;   
  }
  else {  
     Standard_Boolean IsLine = Standard_False;

    if (oncurve) {
      gp_Dir2d Fd(afirstvector);
      gp_Dir2d Sd(asecondvector);
      //if (Fd.Dot(Sd) < Precision::Angular() - 1.) { 
      //if (Fd.Dot(Sd) < 10*Precision::Angular() - 1.) //patch
      if (Fd.Dot(Sd) < Sqrt(2.*Precision::Angular()) - 1.)
	IsLine = Standard_True;
    }
    if (IsLine) {     
      //------------------------------------------------------------------
      // Demi-Droite.
      //------------------------------------------------------------------
      gp_Dir2d N ( - adirection*afirstvector.Y(), adirection*afirstvector.X());
      Handle (Geom2d_CartesianPoint) PG     = new Geom2d_CartesianPoint(apoint);
      Handle (Geom2d_Line)           L      = new Geom2d_Line (apoint,N);
      Handle (Geom2d_TrimmedCurve)   
	BisL   = new Geom2d_TrimmedCurve (L,0,Precision::Infinite());
      Handle(Bisector_BisecAna)      BisAna = new Bisector_BisecAna ();
      BisAna->Init(BisL);
      UFirst = BisAna->ParameterOfStartPoint();
      ULast  = BisAna->ParameterOfEndPoint();
      Bis    = BisAna;
    }
    else {
      //-------------------------------------------------------------------
      // Bissectrice algo
      //-------------------------------------------------------------------
      Handle(Bisector_BisecCC) BisCC = new Bisector_BisecCC();
      BisCC -> Perform(asecondcurve, 
		       afirstcurve ,
		       adirection  , 
		       adirection  , 
		       apoint);

      if (BisCC -> IsEmpty()) {
	// la bissectrice est vide apoint se projette a la fin de la courbe
	// guide . Construction d une fausse bissectrice.
//  modified by NIZHNY-EAP Mon Feb 21 12:00:13 2000 ___BEGIN___
	gp_Dir2d dir1(afirstvector), dir2(asecondvector);
	Standard_Real
	  Nx = - dir1.X() - dir2.X(),
	  Ny = - dir1.Y() - dir2.Y();
	if (Abs(Nx) <= gp::Resolution() && Abs(Ny) <= gp::Resolution()) {
	  Nx = - afirstvector.Y();
	  Ny = afirstvector.X();
	}
	//gp_Dir2d N ( - adirection*afirstvector.Y(), adirection*afirstvector.X());
	gp_Dir2d N ( adirection*Nx, adirection*Ny);
//  modified by NIZHNY-EAP Mon Feb 21 12:00:19 2000 ___END___
	
	Handle (Geom2d_CartesianPoint) PG     = new Geom2d_CartesianPoint(apoint);
	Handle (Geom2d_Line)           L      = new Geom2d_Line (apoint,N);
	Handle (Geom2d_TrimmedCurve)   
	  BisL   = new Geom2d_TrimmedCurve (L,0,Precision::Infinite());
	Handle(Bisector_BisecAna)      BisAna = new Bisector_BisecAna ();
	BisAna->Init(BisL);
	UFirst = BisAna->ParameterOfStartPoint();
	ULast  = BisAna->ParameterOfEndPoint();
	Bis    = BisAna;
      }
      else {
	UFirst = BisCC->FirstParameter();
	ULast  = BisCC->LastParameter ();
	Bis    = BisCC;
	ReplaceByLineIfIsToSmall(Bis,UFirst,ULast);
      }
    }
  }
  thebisector = new Geom2d_TrimmedCurve(Bis,UFirst,ULast);

/*
  sprintf( name, "c1_%d", ++nbb );
  DrawTrSurf::Set( name, afirstcurve );
  sprintf( name, "c2_%d", nbb );
  DrawTrSurf::Set( name, asecondcurve );
  sprintf( name, "p%d", nbb );
  DrawTrSurf::Set( name, apoint );
  sprintf( name, "b%d", nbb );
  DrawTrSurf::Set( name, thebisector );
*/
}

//===========================================================================
//  calcul de la bissectrice entre une courbe et un point issue d un point. 
//                                                                          
//   afirstcurve   : \ courbe et point entre lesquelles on veut calculer la 
//   asecondpoint  : / bissectrice.                                         
//   apoint        :   point par lequel doit passer la bissectrice.         
//   afirstvector  : \ vecteurs pour determiner le secteur dans lequel      
//   asecondvector : / la bissectrice doit se trouver.                      
//   adirection    :   indique le cote de la bissectrice a conserver.       
//   tolerance     :   seuil a partir duquel les bisectrices sont degenerees
//===========================================================================

void Bisector_Bisec::Perform(const Handle(Geom2d_Curve)& afirstcurve  ,
			     const Handle(Geom2d_Point)& asecondpoint ,
			     const gp_Pnt2d&             apoint       ,
			     const gp_Vec2d&             afirstvector ,
			     const gp_Vec2d&             asecondvector,
			     const Standard_Real         adirection   ,
			     const Standard_Real         tolerance    ,
			     const Standard_Boolean      oncurve       )
{  
  //gp_Pnt2d SecondPnt = asecondpoint->Pnt2d();

  Handle(Bisector_Curve) Bis;
  Handle(Standard_Type)  Type1 = afirstcurve ->DynamicType();
  Standard_Real          UFirst,ULast;

  if (Type1 == STANDARD_TYPE(Geom2d_TrimmedCurve)) {
    Type1 = Handle(Geom2d_TrimmedCurve)::DownCast(afirstcurve)
            ->BasisCurve()->DynamicType();
  }

  if ( Type1 == STANDARD_TYPE(Geom2d_Circle) || Type1 == STANDARD_TYPE(Geom2d_Line)) {
    //------------------------------------------------------------------
    // Bissectrice analytique.
    //------------------------------------------------------------------
    Handle(Bisector_BisecAna) BisAna = new Bisector_BisecAna();
    BisAna -> Perform (afirstcurve   ,
		       asecondpoint  ,
		       apoint        ,
		       afirstvector  ,
		       asecondvector ,
		       adirection    ,
		       tolerance     ,
		       oncurve       );
    UFirst = BisAna->ParameterOfStartPoint();
    ULast  = BisAna->ParameterOfEndPoint();
    Bis    = BisAna;
  }
  else {  
    Standard_Boolean IsLine    = Standard_False;
    Standard_Real    RC        = Precision::Infinite();
    
    if (oncurve) {
      if (Bisector::IsConvex(afirstcurve,adirection) || 
	  IsMaxRC(afirstcurve,afirstcurve->LastParameter(),RC)) { 
	IsLine = Standard_True; 
      }
    }
    if (IsLine) {     
      //------------------------------------------------------------------
      // Demi-Droite.
      //------------------------------------------------------------------
      gp_Dir2d N ( -adirection*afirstvector.Y(), adirection*afirstvector.X());
      Handle (Geom2d_Line)         L      = new Geom2d_Line (apoint,N);
      Handle (Geom2d_TrimmedCurve) BisL   = new Geom2d_TrimmedCurve(L,0,RC);
      Handle(Bisector_BisecAna)    BisAna = new Bisector_BisecAna ();
      BisAna->Init(BisL);
      UFirst = BisAna->ParameterOfStartPoint();
      ULast  = BisAna->ParameterOfEndPoint();
      Bis    = BisAna;
    }
    else {
      //-------------------------------------------------------------------
      // Bissectrice algo
      //-------------------------------------------------------------------
      Handle(Bisector_BisecPC) BisPC = new Bisector_BisecPC();
      Handle(Geom2d_Curve) afirstcurvereverse = afirstcurve->Reversed();
      
      BisPC -> Perform(afirstcurvereverse   ,
		       asecondpoint->Pnt2d(),
		       - adirection         );
//  Modified by Sergey KHROMOV - Thu Feb 21 16:49:54 2002 Begin
      if (BisPC -> IsEmpty()) {
	gp_Dir2d dir1(afirstvector), dir2(asecondvector);
	Standard_Real
	  Nx = - dir1.X() - dir2.X(),
	  Ny = - dir1.Y() - dir2.Y();
	if (Abs(Nx) <= gp::Resolution() && Abs(Ny) <= gp::Resolution()) {
	  Nx = - afirstvector.Y();
	  Ny = afirstvector.X();
	}
// 	gp_Dir2d N ( -adirection*afirstvector.Y(), adirection*afirstvector.X());
	gp_Dir2d N ( adirection*Nx, adirection*Ny);
	Handle (Geom2d_Line)         L      = new Geom2d_Line (apoint,N);
	Handle (Geom2d_TrimmedCurve) BisL   = new Geom2d_TrimmedCurve(L,0,RC);
	Handle(Bisector_BisecAna)    BisAna = new Bisector_BisecAna ();
	BisAna->Init(BisL);
	UFirst = BisAna->ParameterOfStartPoint();
	ULast  = BisAna->ParameterOfEndPoint();
	Bis    = BisAna;
      } else {
//  Modified by Sergey KHROMOV - Wed Mar  6 17:01:08 2002 End
	UFirst = BisPC->Parameter(apoint);
	ULast  = BisPC->LastParameter();
	if(UFirst >= ULast)
	  {
	  //Standard_Real t = .9;
	  //UFirst = (1. - t) * BisPC->FirstParameter() + t * ULast;
	    //Extrapolate by line
	    //gp_Dir2d N ( -adirection*afirstvector.Y(), adirection*afirstvector.X());
	    gp_Vec2d V( BisPC->Value(BisPC->FirstParameter()), BisPC->Value(ULast) );
	    gp_Dir2d N( V );
	    Handle (Geom2d_Line)         L      = new Geom2d_Line         (apoint,N);
	    Handle (Geom2d_TrimmedCurve) BisL   = new Geom2d_TrimmedCurve (L,0,RC);
	    Handle(Bisector_BisecAna)    BisAna = new Bisector_BisecAna   ();
	    BisAna->Init(BisL);
	    UFirst = BisAna->ParameterOfStartPoint();
	    ULast  = BisAna->ParameterOfEndPoint();
	    Bis    = BisAna;
	  }
	else
	  Bis    = BisPC;
      }
    }
  }
  thebisector = new Geom2d_TrimmedCurve(Bis,UFirst,ULast);

/*
  sprintf( name, "c1_%d", ++nbb );
  DrawTrSurf::Set( name, afirstcurve );
  sprintf( name, "c2_%d", nbb );
  DrawTrSurf::Set( name, SecondPnt );
  sprintf( name, "p%d", nbb );
  DrawTrSurf::Set( name, apoint );
  sprintf( name, "b%d", nbb );
  DrawTrSurf::Set( name, thebisector );
*/
}

//===========================================================================
//  calcul de la bissectrice entre une courbe et un point issue d un point. 
//                                                                          
//   afirstpoint   : \ point et courbe entre lesquelles on veut calculer la         
//   asecondcurve  : / bissectrice.                                         
//   apoint        :   point par lequel doit passer la bissectrice.         
//   afirstvector  : \ vecteurs pour determiner le secteur dans lequel      
//   asecondvector : / la bissectrice doit se trouver.                      
//   adirection    :   indique le cote de la bissectrice a conserver.       
//   tolerance     :   seuil a partir duquel les bisectrices sont degenerees
//===========================================================================

void Bisector_Bisec::Perform(const Handle(Geom2d_Point)& afirstpoint  ,
			     const Handle(Geom2d_Curve)& asecondcurve ,
			     const gp_Pnt2d&             apoint       ,
			     const gp_Vec2d&             afirstvector ,
			     const gp_Vec2d&             asecondvector,
			     const Standard_Real         adirection   ,
			     const Standard_Real         tolerance    ,
			     const Standard_Boolean      oncurve       )

{  
  //gp_Pnt2d FirstPnt = afirstpoint->Pnt2d();

  Handle(Bisector_Curve) Bis;
  Handle(Standard_Type)  Type1 = asecondcurve ->DynamicType();
  Standard_Real          UFirst,ULast;
  
  if (Type1 == STANDARD_TYPE(Geom2d_TrimmedCurve)) {
    Type1 = Handle(Geom2d_TrimmedCurve)::DownCast(asecondcurve)
            ->BasisCurve()->DynamicType();
  }
  
  if ( Type1 == STANDARD_TYPE(Geom2d_Circle) || Type1 == STANDARD_TYPE(Geom2d_Line)) {
    //------------------------------------------------------------------
    // Bissectrice analytique.
    //------------------------------------------------------------------
    Handle(Bisector_BisecAna) BisAna = new Bisector_BisecAna();
    BisAna -> Perform (afirstpoint   ,
		       asecondcurve  ,
		       apoint        ,
		       afirstvector  ,
		       asecondvector ,
		       adirection    ,
		       tolerance     ,
		       oncurve       );
    UFirst = BisAna->ParameterOfStartPoint();
    ULast  = BisAna->ParameterOfEndPoint();
    Bis    = BisAna;
  }
  else {   
//  Standard_Real    UPoint    = 0.;
    Standard_Boolean IsLine    = Standard_False;
    Standard_Real    RC        = Precision::Infinite();
    
    if (oncurve) {
      if (Bisector::IsConvex(asecondcurve, adirection) || 
	  IsMaxRC(asecondcurve,asecondcurve->FirstParameter(),RC)) {
	IsLine = Standard_True;
      }
    }    
    if (IsLine) {     
      //------------------------------------------------------------------
      // Demi-Droite.
      //------------------------------------------------------------------
      gp_Dir2d N ( -adirection*afirstvector.Y(), adirection*afirstvector.X());
      Handle (Geom2d_Line)         L      = new Geom2d_Line         (apoint,N);
      Handle (Geom2d_TrimmedCurve) BisL   = new Geom2d_TrimmedCurve (L,0,RC);
      Handle(Bisector_BisecAna)    BisAna = new Bisector_BisecAna   ();
      BisAna->Init(BisL);
      UFirst = BisAna->ParameterOfStartPoint();
      ULast  = BisAna->ParameterOfEndPoint();
      Bis    = BisAna;
    }
    else {
      //-------------------------------------------------------------------
      // Bissectrice algo
      //-------------------------------------------------------------------
      Handle(Bisector_BisecPC) BisPC = new Bisector_BisecPC();
      BisPC -> Perform(asecondcurve        ,
		       afirstpoint->Pnt2d(),
		       adirection          );
//  Modified by Sergey KHROMOV - Thu Feb 21 16:49:54 2002 Begin
      if (BisPC -> IsEmpty()) {
	gp_Dir2d dir1(afirstvector), dir2(asecondvector);
	Standard_Real
	  Nx = - dir1.X() - dir2.X(),
	  Ny = - dir1.Y() - dir2.Y();
	if (Abs(Nx) <= gp::Resolution() && Abs(Ny) <= gp::Resolution()) {
	  Nx = - afirstvector.Y();
	  Ny = afirstvector.X();
	}
// 	gp_Dir2d N ( -adirection*afirstvector.Y(), adirection*afirstvector.X());
	gp_Dir2d N ( adirection*Nx, adirection*Ny);
	Handle (Geom2d_Line)         L      = new Geom2d_Line (apoint,N);
	Handle (Geom2d_TrimmedCurve) BisL   = new Geom2d_TrimmedCurve(L,0,RC);
	Handle(Bisector_BisecAna)    BisAna = new Bisector_BisecAna ();
	BisAna->Init(BisL);
	UFirst = BisAna->ParameterOfStartPoint();
	ULast  = BisAna->ParameterOfEndPoint();
	Bis    = BisAna;
      } else {
//  Modified by Sergey KHROMOV - Thu Feb 21 16:49:58 2002 End
	UFirst = BisPC->Parameter(apoint);
	ULast  = BisPC->LastParameter();
	if(UFirst >= ULast)
	  {
	    //Extrapolate by line
	    //gp_Dir2d N ( -adirection*afirstvector.Y(), adirection*afirstvector.X());
	    gp_Vec2d V( BisPC->Value(BisPC->FirstParameter()), BisPC->Value(ULast) );
	    gp_Dir2d N( V );
	    Handle (Geom2d_Line)         L      = new Geom2d_Line         (apoint,N);
	    Handle (Geom2d_TrimmedCurve) BisL   = new Geom2d_TrimmedCurve (L,0,RC);
	    Handle(Bisector_BisecAna)    BisAna = new Bisector_BisecAna   ();
	    BisAna->Init(BisL);
	    UFirst = BisAna->ParameterOfStartPoint();
	    ULast  = BisAna->ParameterOfEndPoint();
	    Bis    = BisAna;
	  }
	else
	  Bis    = BisPC;
      }
    }
  }
  thebisector = new Geom2d_TrimmedCurve(Bis,UFirst,ULast);

/*
  sprintf( name, "c1_%d", ++nbb );
  DrawTrSurf::Set( name, FirstPnt );
  sprintf( name, "c2_%d", nbb );
  DrawTrSurf::Set( name, asecondcurve );
  sprintf( name, "p%d", nbb );
  DrawTrSurf::Set( name, apoint );
  sprintf( name, "b%d", nbb );
  DrawTrSurf::Set( name, thebisector );
*/
}

//===========================================================================
//        calcul de la bissectrice entre deux points issue d un point.      
//                                                                          
//   afirstpoint   : \ courbes entre lesquelles on veut calculer la         
//   asecondpoint  : / bissectrice.                                         
//   apoint        :   point par lequel doit passer la bissectrice.         
//   afirstvector  : \ vecteurs pour determiner le secteur dans lequel      
//   asecondvector : / la bissectrice doit se trouver.                      
//   adirection    :   indique le cote de la bissectrice a conserver.       
//===========================================================================

void Bisector_Bisec::Perform(const Handle(Geom2d_Point)& afirstpoint  ,
			     const Handle(Geom2d_Point)& asecondpoint ,
			     const gp_Pnt2d&             apoint       ,
			     const gp_Vec2d&             afirstvector ,
			     const gp_Vec2d&             asecondvector,
			     const Standard_Real         adirection   ,
			     const Standard_Real         tolerance    ,
			     const Standard_Boolean      oncurve      )
{
  Handle(Bisector_BisecAna) Bis = new Bisector_BisecAna();

  Bis -> Perform (afirstpoint   ,
		  asecondpoint  ,
		  apoint        ,
		  afirstvector  ,
		  asecondvector ,
		  adirection    ,
		  tolerance     ,
		  oncurve       ); 
  thebisector = new Geom2d_TrimmedCurve(Bis,
					Bis->ParameterOfStartPoint(),
					Bis->ParameterOfEndPoint());

/*
  sprintf( name, "c1_%d", ++nbb );
  DrawTrSurf::Set( name, afirstpoint->Pnt2d() );
  sprintf( name, "c2_%d", nbb );
  DrawTrSurf::Set( name, asecondpoint->Pnt2d() );
  sprintf( name, "p%d", nbb );
  DrawTrSurf::Set( name, apoint );
  sprintf( name, "b%d", nbb );
  DrawTrSurf::Set( name, thebisector );
*/
}

//=============================================================================
//function : Value
//purpose  :
//=============================================================================
const Handle(Geom2d_TrimmedCurve)&  Bisector_Bisec::Value() const
{
  return thebisector;
}

//=============================================================================
//function : ChangeValue
//purpose  :
//=============================================================================
const Handle(Geom2d_TrimmedCurve)&  Bisector_Bisec::ChangeValue()
{
  return thebisector;
}

//=============================================================================
//function : PointIsOnCurve
// purpose  :
//=============================================================================
#ifdef DEB
static Standard_Boolean  PointIsOnCurve(const Handle(Geom2d_Curve)& C,
					const gp_Pnt2d&             P,
					      Standard_Real&        U)
{
  if (C->Value(C->FirstParameter()).IsEqual(P,Precision::Confusion())) {
    U = C->FirstParameter();
    return Standard_True;
  }
  if (C->Value(C->LastParameter()).IsEqual(P,Precision::Confusion()))  {
    U = C->LastParameter();
    return Standard_True;
  }
  return Standard_False;
}
#endif
//=============================================================================
//function : ReplaceByLineIfIsToSmall 
//purpose  : Si une bissectrice algorithmique est de taille negligeable elle est
//           remplace par une demi-droite.
//=============================================================================
static void ReplaceByLineIfIsToSmall (Handle(Geom2d_Curve)& Bis,
				      Standard_Real&        UFirst,
				      Standard_Real&        ULast )

{
  if (Abs(ULast - UFirst) > 2.*Precision::PConfusion()*10.) return; //patch

  gp_Pnt2d PF = Bis->Value(UFirst);
  gp_Pnt2d PL = Bis->Value(ULast);

  if (PF.Distance(PL) > Precision::Confusion()*10.) return;

  gp_Vec2d T1 = Bis->DN(UFirst,1);

  Handle (Geom2d_CartesianPoint) PG     = new Geom2d_CartesianPoint(PF);
  Handle (Geom2d_Line)           L      = new Geom2d_Line (PF,T1);
  Handle (Geom2d_TrimmedCurve)   
    BisL   = new Geom2d_TrimmedCurve (L,0,Precision::Infinite());
  Handle(Bisector_BisecAna)      BisAna = new Bisector_BisecAna ();
  BisAna->Init(BisL);
  UFirst = BisAna->ParameterOfStartPoint();
  ULast  = BisAna->ParameterOfEndPoint();
  Bis    = BisAna;
}

//=============================================================================
//function : IsMaxRC
//purpose  :
//=============================================================================
static Standard_Boolean  IsMaxRC (const Handle(Geom2d_Curve)& C,
				        Standard_Real         U,
					Standard_Real&        R)
{  
  Standard_Real KF,KL;
  Standard_Real US = C->FirstParameter();
  Standard_Real UL = C->LastParameter();

  gp_Vec2d      D1,D2;
  gp_Pnt2d      P;
  Standard_Real Norm2;

  C->D2(US,P,D1,D2);
  Norm2 = D1.SquareMagnitude();;
  if (Norm2 < gp::Resolution()) { KF = 0.0;}
  else                          { KF = Abs(D1^D2)/(Norm2*sqrt(Norm2));}
  
  C->D2(UL,P,D1,D2);
  Norm2 = D1.SquareMagnitude();;
  if (Norm2 < gp::Resolution()) { KL = 0.0;}
  else                          { KL = Abs(D1^D2)/(Norm2*sqrt(Norm2));}

  Standard_Boolean IsMax = Standard_False;

  if (U == UL) {
    if (KL < KF) {
      if (KL == 0.0) R = Precision::Infinite(); else R = 1/KL;
      IsMax = Standard_True;
    }
  }
  else {   
    if (KF < KL) {
      if (KF == 0.0) R = Precision::Infinite(); else R = 1/KF;
      IsMax = Standard_True;
    }
  }
  return IsMax;
}
