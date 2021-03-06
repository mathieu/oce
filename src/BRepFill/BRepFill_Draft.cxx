// File:	BRepFill_Draft.cxx
// Created:	Mon Jun  8 15:13:03 1998
// Author:	Stephanie HUMEAU
//		<shu@sun17>


#include <BRepFill_Draft.ixx>

#include <BRepFill_DraftLaw.hxx>
#include <BRepFill_ShapeLaw.hxx>
#include <BRepFill_Sweep.hxx>

#include <BndLib_Add3dCurve.hxx>
#include <BndLib_AddSurface.hxx>
#include <Bnd_Box.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <gp_Trsf.hxx>
#include <gp_Ax3.hxx>
#include <gp_Lin.hxx>
#include <gp_Mat.hxx>
#include <TColgp_Array1OfPnt.hxx>

#include <GeomAdaptor_Surface.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Adaptor3d_HCurve.hxx>

#include <GeomLProp_SLProps.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Line.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Plane.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>

#include <GeomAdaptor_HSurface.hxx>
#include <Adaptor3d_Surface.hxx>
#include <BRepAdaptor_Curve.hxx>

#include <GeomFill_LocationDraft.hxx>

#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>  
#include <TopoDS_Shell.hxx> 
#include <TopoDS_Solid.hxx> 
#include <TopoDS_Iterator.hxx>
#include <TopExp_Explorer.hxx> 
#include <TopExp.hxx>
#include <TopAbs.hxx>
#include <BRepLib_MakeWire.hxx>
#include <BRepLib_MakeEdge.hxx>
#include <BRepLib_MakeFace.hxx>
#include <BRepLib_FindSurface.hxx>
#include <BRep_Builder.hxx>

#include <BRep_Tool.hxx>
#include <BRepTools.hxx>
#include <BRepAlgo_DSAccess.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepClass3d_SolidClassifier.hxx>

#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepExtrema_DistShapeShape.hxx>

#include <Precision.hxx> 
#include <TColStd_Array1OfReal.hxx>

#include <Standard_NoSuchObject.hxx>
#include <StdFail_NotDone.hxx>

#ifdef DRAW
#include <Geom_Circle.hxx>
#include <gp.hxx>
#include <DBRep.hxx>
#include <DrawTrSurf.hxx>
static Standard_Boolean Affich = 0;
#endif

//=======================================================================
//function : Trsf
//purpose  : 
//======================================================================
static void ComputeTrsf(const TopoDS_Wire& W,
			const gp_Dir& D,
			Bnd_Box& Box,
			gp_Trsf& Tf)
{
  // Calcul d'un barycentre approximatif
  BRepTools_WireExplorer Exp(W);
// Class BRep_Tool without fields and without Constructor :
//  BRep_Tool BT;
  gp_XYZ Bary(0.,0.,0.);
  Standard_Integer nb;

  for (nb=0; Exp.More(); Exp.Next()) {
//    Bary += BT.Pnt(Exp.CurrentVertex()).XYZ();
    Bary += BRep_Tool::Pnt(Exp.CurrentVertex()).XYZ();
    nb++;
  }
  Bary /= nb;

  // Calcul la Transfo  
  gp_Ax3 N(Bary, D);
  Tf.SetTransformation(N);
  BRepAdaptor_Curve AC;
//  BndLib_Add3dCurve BC;  

  // transfo du wire
  TopoDS_Wire TheW = W;
  TopLoc_Location Loc(Tf);
  TheW.Location(Loc);


  // Calcul la boite
  Box.SetVoid();
  for (Exp.Init(TheW); Exp.More(); Exp.Next()) {
    AC.Initialize(Exp.Current());
//    BC.Add(AC, 0.1, Box);
    BndLib_Add3dCurve::Add(AC, 0.1, Box);
  }
}

//=======================================================================
//function : Longueur
//purpose  : 
//======================================================================
static Standard_Real Longueur(const Bnd_Box& WBox,
			      const Bnd_Box& SBox,
			      gp_Dir& D,
			      gp_Pnt& P)
{
  // face de la boite la plus eloignee de la face entree dans 
  //la direction de depouille
  Standard_Real Xmin,Ymin,Zmin,Xmax,Ymax,Zmax,WZmin,WZmax,L;

  //"coord" de la boite
  WBox.Get(Xmin,Ymin,Zmin,Xmax,Ymax,Zmax);
  WZmin = Zmin;
  WZmax = Zmax;   

  SBox.Get(Xmin,Ymin,Zmin,Xmax,Ymax,Zmax);
  P.SetCoord( (Xmin+Xmax)/2, (Ymin+Ymax)/2, Zmax);

  if (Zmax < WZmin) {
    // Depouille dans le mauvais sens. On inverse...
    D.Reverse();
    L = WZmax - Zmin;
    P.SetZ(Zmin);
  }
  else {
    L = Zmax - WZmin;
  }
  return L;
}

//=======================================================================
//function : GoodOrientation
//purpose  : Regarde si la loi est oriente de maniere a avoir une depouille
//           "exterieur"
//======================================================================
static Standard_Boolean GoodOrientation(const Bnd_Box& B,
					const Handle(BRepFill_LocationLaw)& Law,
					const gp_Dir& D)
{
  Standard_Real f, l, r, t;
  Standard_Real aXmin, aYmin, aZmin, aXmax, aYmax, aZmax;

  B.Get(aXmin, aYmin, aZmin, aXmax, aYmax, aZmax);
  gp_Pnt P1(aXmin, aYmin, aZmin), P2(aXmax, aYmax, aZmax);
  gp_Vec V(P1, P2);

  Law->CurvilinearBounds(Law->NbLaw(), f, l);
  r = V.Magnitude()/l;
 
  Standard_Integer ii, Ind;
//#ifndef DEB
  Standard_Integer Nb = (Standard_Integer) (4+(10*r));
//#else
//  Standard_Integer Nb = 4+(10*r);
//#endif
  r = l/Nb;

  Nb++; // Nombre de points

  TColgp_Array1OfPnt Pnts(1, Nb);
  Handle(Adaptor3d_HCurve) AC;
  gp_XYZ Bary(0.,0.,0.);
  
  for (ii=1; ii<=Nb; ii++) {
    Law->Parameter((ii-1)*r, Ind, t);
    AC = Law->Law(Ind)->GetCurve();
    AC->D0(t,  Pnts(ii));
    Bary+= Pnts(ii).XYZ();
  }

  Bary /= Nb;
  gp_Pnt Centre(Bary);
  gp_Vec Normal(D.XYZ());
  Standard_Real Angle = 0;
  gp_Vec Ref(Centre,  Pnts(1));

  for (ii=2; ii<=Nb; ii++) {
    gp_Vec R(Centre, Pnts(ii));
    Angle += Ref.AngleWithRef(R, Normal);
    Ref = R;
  }

  return (Angle >= 0);
}

//=======================================================================
//function : Constructeur
//purpose  : 
//======================================================================
 BRepFill_Draft::BRepFill_Draft(const TopoDS_Shape& S,
				const gp_Dir& Dir,
				const Standard_Real Angle)
{
  myLoc.Nullify();
  mySec.Nullify();
  myFaces.Nullify();
  mySections.Nullify(); 
   
  switch (S.ShapeType()) {
  case TopAbs_WIRE :
    {
      myWire = TopoDS::Wire(S);
      break;
    }
  case TopAbs_FACE :
    {  
      TopoDS_Iterator Exp (S);
      myWire = TopoDS::Wire(Exp.Value());
      break;
    }
  case TopAbs_SHELL :
    {  
      TopTools_ListOfShape List;
      TopTools_IndexedDataMapOfShapeListOfShape edgemap;
      TopExp::MapShapesAndAncestors(S,TopAbs_EDGE,TopAbs_FACE,edgemap);
      Standard_Integer iedge, nbf;
      for (iedge = 1; iedge <= edgemap.Extent(); iedge++) {   
	const TopoDS_Edge& theEdge = TopoDS::Edge(edgemap.FindKey(iedge));    
	// skip degenerated edges
	if (!BRep_Tool::Degenerated(theEdge)) {
	  nbf = edgemap(iedge).Extent();
	  if (nbf==1) List.Append(theEdge);
	}
      }

      if( List.Extent()>0) {
	BRepLib_MakeWire MW;
	MW.Add(List);
	BRepLib_WireError Err = MW.Error();
	if (Err == BRepLib_WireDone) {
	  myWire = MW.Wire();
	}
	else {
#if DEB
	  cout << "Error in MakeWire" << endl;
#endif 
	  Standard_ConstructionError::Raise("BRepFill_Draft");
	}
      }
      else {
#if DEB
	  cout << "Pas de Bords Libre !" << endl;
#endif 
	  Standard_ConstructionError::Raise("BRepFill_Draft");
      }
      break;
    }
    default :
      Standard_ConstructionError::Raise("BRepFill_Draft");
  }

  // Attention aux wire closed non declare !
  if (!myWire.Closed()) {
    TopoDS_Vertex Vf, Vl;
    TopExp::Vertices(myWire, Vf, Vl);
    if (Vf.IsSame(Vl)) myWire.Closed(Standard_True);
  }
#if DRAW
  if (Affich) {
    DBRep::Set("TheWire", myWire);
  }
#endif

  myAngle = Abs(Angle);
  myDir = Dir;
  myTop = S;
  myDone = Standard_False;
  myTol = 1.e-4;
  myCont = GeomAbs_C1;
  SetOptions();
  SetDraft();
}

//=======================================================================
//function :SetOptions
//purpose  : Definit le style
//======================================================================
 void BRepFill_Draft::SetOptions(const BRepFill_TransitionStyle Style,
				 const Standard_Real Min,
				 const Standard_Real Max)
{
  myStyle =  Style;
  angmin = Min; 
  angmax = Max;
}

//=======================================================================
//function :SetDraft
//purpose  :
//======================================================================
 void BRepFill_Draft::SetDraft(const Standard_Boolean Internal)
{
  IsInternal = Internal;
}


//=======================================================================
//function :Perform
//purpose  : calcul d'une surface de depouille
//======================================================================
 void BRepFill_Draft::Perform(const Standard_Real LengthMax)
{
  Handle(Geom_Surface) S;
  S.Nullify();
  Bnd_Box WBox;//, SBox;
  gp_Trsf Trsf;


  ComputeTrsf(myWire, myDir, WBox, Trsf); 
  Init(S, LengthMax, WBox);
  BuildShell(S); 
  Sewing(); 
}

//=======================================================================
//function :Perform
//purpose  : calcul d'une surface de depouille
//======================================================================
 void BRepFill_Draft::Perform(const Handle(Geom_Surface)& Surface,
			      const Standard_Boolean KeepInsideSurface)
{
  Bnd_Box WBox, SBox;
  gp_Trsf Trsf;
  gp_Pnt Pt;
  Standard_Real L;

  ComputeTrsf(myWire, myDir, WBox, Trsf);

  // boite englobant la surface d'arret  
  Handle(Geom_Surface) Surf;
  Surf =   Handle(Geom_Surface)::DownCast(Surface->Transformed(Trsf));
  GeomAdaptor_Surface S1 (Surf);   
//  BndLib_AddSurface AS; 
//  AS.Add(S1, 0.1, SBox);
  BndLib_AddSurface::Add(S1, 0.1, SBox);

  // on calcule la longueur maximum de la regle.
  L = Longueur(WBox, SBox, myDir, Pt);
  L /= Abs(Cos(myAngle));

  // Constructuion
  Init(Surface, L, WBox);
  BuildShell(Surface, !KeepInsideSurface);
  Sewing(); 
}

//=======================================================================
//function :Perform
//purpose  : calcul de la surface de depouille, arretee par une shape
//======================================================================
 void BRepFill_Draft::Perform(const TopoDS_Shape& StopShape,
			      const Standard_Boolean KeepOutSide)
{
  Bnd_Box WBox, SBox;
  gp_Trsf Trsf;
  gp_Pnt Pt;
  Standard_Real L;

  ComputeTrsf(myWire, myDir, WBox, Trsf); 

// boite englobant la shape d'arret
  Bnd_Box BSurf;//, TheBox;
  Standard_Real Umin, Umax, Vmin, Vmax;
#ifdef DEB
  Standard_Real Tol = Precision::Confusion()/10;
#endif
//  BRepTools B;
//  BRep_Tool BT;
  Handle(Geom_Surface) Surf;
 
//  BndLib_AddSurface AS;
  
  TopExp_Explorer Ex (StopShape, TopAbs_FACE);

  SBox.SetVoid();
  while (Ex.More()) { // on parcourt les faces de la shape d'arret
//    B.UVBounds(TopoDS::Face(Ex.Current()), Umin,Umax,Vmin,Vmax); 
    BRepTools::UVBounds(TopoDS::Face(Ex.Current()), Umin,Umax,Vmin,Vmax); 
    Surf = Handle(Geom_Surface)::DownCast(
//     BT.Surface(TopoDS::Face(Ex.Current()))->Transformed(Trsf) ); 
     BRep_Tool::Surface(TopoDS::Face(Ex.Current()))->Transformed(Trsf) ); 
    GeomAdaptor_Surface S1 (Surf);
    // boite englobant la face courante
//    AS.Add(S1, Umin, Umax, Vmin, Vmax, 0.1, BSurf); 
    BndLib_AddSurface::Add(S1, Umin, Umax, Vmin, Vmax, 0.1, BSurf);
    SBox.Add(BSurf);	// on regroupe les boites
    Ex.Next();
  }// while_Ex

  // on calcule la longueur maximum de la regle.
  L = Longueur(WBox, SBox, myDir, Pt);
  L /= Abs(Cos(myAngle));

// surface d'arret
  gp_Trsf Inv;
  Inv = Trsf.Inverted(); // transfo inverse
  Pt.Transform(Inv); // coord dans le repere absolu
  Handle(Geom_Plane) Plan = new (Geom_Plane)(Pt, myDir);
  Surf = new (Geom_RectangularTrimmedSurface) (Plan,-L, L, -L, L); 

#if DRAW
  if (Affich) {
    char* Temp = "ThePlan" ;
    DrawTrSurf::Set(Temp, Surf);
//    DrawTrSurf::Set("ThePlan", Surf);
  }
#endif

// Balayage et restriction
  Init(Plan,  L*1.01, WBox);
  BuildShell(Surf, Standard_False);
  Fuse(StopShape,  KeepOutSide);
  Sewing();
}

//=======================================================================
//function : Init
//purpose  : Construction des lois.
//======================================================================
 void BRepFill_Draft::Init(const Handle(Geom_Surface)& ,
                           const Standard_Real Length,
			   const Bnd_Box&  Box)
{
  Standard_Boolean B;

// loi de positionnement  
  Handle(GeomFill_LocationDraft) Loc
    = new (GeomFill_LocationDraft) (myDir, myAngle); 
  myLoc = new (BRepFill_DraftLaw) (myWire, Loc);

  B = GoodOrientation(Box, myLoc, myDir);

  if (IsInternal ^ (!B) )  {
    myAngle = - myAngle;
    Loc->SetAngle(myAngle);
    myLoc = new (BRepFill_DraftLaw) (myWire, Loc);
  }

  myLoc->CleanLaw(angmin); // Nettoie les petites discontinuites.

// loi de section
// generatrice est une droite // a la binormal.
  gp_Pnt P(0, 0, 0);
  gp_Vec D (0., 1., 0.);

// Controle de l'orientation
  Standard_Real f,l;
  myLoc->Law(1)->GetDomain(f,l);
  gp_Mat M;

  gp_Vec Bid; 
  myLoc->Law(1)->D0( (f+l)/2, M, Bid);
  gp_Dir BN(M.Column(2));
  
  Standard_Real ang = myDir.Angle(BN);
  if (ang > PI/2) D.Reverse();    
  Handle(Geom_Line) L = new (Geom_Line) (P, D);

  Handle(Geom_Curve) TC = new (Geom_TrimmedCurve) (L, 0, Length);


#if DRAW
  if (Affich > 2) {
     TC = new (Geom_Circle) (gp::XOY(), Length);
  }
#endif 

  BRepLib_MakeEdge ME(TC);
  TopoDS_Edge EG = ME.Edge();
  
  BRepLib_MakeWire MW(EG);
  TopoDS_Wire G = MW.Wire();

  mySec = new (BRepFill_ShapeLaw) (G, Standard_True);
}


//=======================================================================
//function : BuildShell
//purpose  : Construction de la surface de depouille
//======================================================================
 void BRepFill_Draft::BuildShell(const Handle(Geom_Surface)& Surf,
				 const Standard_Boolean  KeepOutSide) 
{
// construction de la surface
  BRepFill_Sweep Sweep(mySec, myLoc, Standard_True);
  Sweep.SetTolerance(myTol);
  Sweep.SetAngularControl(angmin, angmax);
  Sweep.Build(myStyle, GeomFill_Location, myCont);
  if (Sweep.IsDone()) {
    myShape = Sweep.Shape();
    myShell = TopoDS::Shell(myShape);
    myFaces    = Sweep.SubShape();
    mySections = Sweep.Sections();    
    myDone = Standard_True;
    // Controle de l'orientation
    Standard_Boolean out=Standard_True;
    TopExp_Explorer ex(myShell,TopAbs_FACE);
    TopoDS_Face F;
    F = TopoDS::Face(ex.Current());
    BRepAdaptor_Surface SF(F);
    Standard_Real u, v;
    gp_Pnt P;
    gp_Vec V1, V2, V;
    u = SF.FirstUParameter();
    v = SF.FirstVParameter();
    SF.D1(u,v,P,V1,V2);
    V = V1.Crossed(V2);
    if (F.Orientation() == TopAbs_REVERSED) V.Reverse();
    if (V.Magnitude() > 1.e-10) {
      out = myDir.Angle(V) > PI/2;
    }
    if (out == IsInternal) {
      myShell.Reverse();
      myShape.Reverse();
    }    
  }
  else {
    myDone = Standard_False;
    return;
  }

  if (!Surf.IsNull()) { // On ajoute la face en bout

  // En attendant une utilisation des traces & retriction dans BRepFill_Sweep
  // On fait un Fuse.
    BRepLib_MakeFace MkF;
    MkF.Init(Surf);
    Fuse(MkF.Face(), KeepOutSide);
  }
}


//=======================================================================
//function : Fuse
//purpose  : Operation booleenne entre la depouille et 
//           la shape d'arret
//======================================================================
 Standard_Boolean BRepFill_Draft::Fuse(const TopoDS_Shape& StopShape,
			   const Standard_Boolean KeepOutSide)
{
  BRep_Builder B;
  Standard_Boolean issolid = Standard_False;
  TopoDS_Solid Sol1, Sol2;
  TopAbs_State State1 = TopAbs_OUT,  State2 = TopAbs_OUT;


  if (myShape.ShapeType()==TopAbs_SOLID) {
    Sol1 = TopoDS::Solid(myShape);
    issolid = Standard_True;
  }
  else {
    B.MakeSolid(Sol1);
    B.Add(Sol1, myShape); // shell => solid (pour fusion)    
  }


  switch (StopShape.ShapeType()) {
  case TopAbs_COMPOUND :
    {
      TopoDS_Iterator It(StopShape);
      return Fuse(It.Value(), KeepOutSide);
    }
  case TopAbs_SOLID : 
    {
      Sol2 = TopoDS::Solid(StopShape);
      break;
    }
 case TopAbs_SHELL :
    {
      B.MakeSolid(Sol2);
      B.Add(Sol2, StopShape); // shell => solid (pour fusion) 
      break;
    }

 case TopAbs_FACE :
    {
      TopoDS_Shell S;
      B.MakeShell(S);
      B.Add(S, StopShape);
      B.MakeSolid(Sol2);
      B.Add(Sol2, S); // shell => solid (pour fusion)
      break;
    }

  default :
    {
      return Standard_False; // On ne sait pas faire
    }
  }
      
  BRepAlgo_DSAccess DSA;
  DSA.Load(Sol1, Sol2);
  DSA.Intersect(Sol1, Sol2); // intersection des 2 solids
 
// suppression des aretes correspondant aux intersections "inutiles"
  Standard_Integer NbPaquet;
// gp_Pnt P1,P2;
  TopoDS_Vertex V,V1;
  TopTools_ListOfShape List;
  List  = DSA.GetSectionEdgeSet();// liste des aretes
  
  NbPaquet = List.Extent();

  if (NbPaquet == 0) {
#if DRAW
    cout << "Pas de fusion" << endl;
    DBRep::Set("DepPart", Sol1);
    DBRep::Set("StopPart", Sol2);
#endif
    return Standard_False;
  }

  if (NbPaquet > 1) {
    // Il faut selectioner les paquets.
    TColStd_Array1OfReal Dist(1, NbPaquet);
    TopTools_ListIteratorOfListOfShape it(List);
    Standard_Real D, Dmin = 1.e10;
    Standard_Integer ii;
 
    //On classe les paquets par eloignement.
    BRepExtrema_DistShapeShape Dist2;
    Dist2.LoadS1( myWire );
    for (ii=1; it.More();it.Next(),ii++){
      Dist2.LoadS2( it.Value() );
      Dist2.Perform();
      if (Dist2.IsDone()) {
	D = Dist2.Value();
	Dist(ii) = D;
	if (D < Dmin) Dmin = D;
      }
      else
	Dist(ii) = 1.e10;
    }

    // on supprime les edges "plus loin" que Dmin
    for (ii=1, it.Initialize(List); it.More();it.Next(), ii++){
      if (Dist(ii) > Dmin) {
	DSA.SuppressEdgeSet(it.Value());
      }
#if DRAW
     else if (Affich) {
	DBRep::Set("KeepEdges", it.Value());
      }
#endif
    }
  }

  if (StopShape.ShapeType() != TopAbs_SOLID) {
    // Il faut choisir le state par la geometrie

    //(1) On recupere une edge de section
    List  = DSA.GetSectionEdgeSet();// liste des aretes
    TopTools_ListIteratorOfListOfShape it(List);
    TopoDS_Iterator iter(it.Value());
    TopoDS_Edge E = TopoDS::Edge(iter.Value());

    // (2)  On recupere sa geometrie sur StopShape
// Class BRep_Tool without fields and without Constructor :
//    BRep_Tool BT;
    Handle(Geom_Surface) S;
    Handle(Geom2d_Curve) C2d;
    gp_Pnt2d P2d;
    Standard_Real f,l;  
    TopLoc_Location L;
//    BT.CurveOnSurface(E, C2d, S, L, f, l, 2);
    BRep_Tool::CurveOnSurface(E, C2d, S, L, f, l, 2);

    // On Trouve une normale.
    C2d->D0((f+l)/2,P2d); 
    GeomLProp_SLProps SP(S, P2d.X(), P2d.Y(), 1, 1.e-12);
    if (! SP.IsNormalDefined()) {
      C2d->D0((3*f+l)/4,P2d);
      SP.SetParameters(P2d.X(), P2d.Y());
      if ( !SP.IsNormalDefined()) {
	C2d->D0((f+3*l)/4,P2d);
	SP.SetParameters(P2d.X(), P2d.Y());
      }
    }

    // On en deduit State1
    if (myDir.Angle(SP.Normal()) < PI/2)  State1 = TopAbs_IN;
    else  State1 = TopAbs_OUT;
  }

  if (! KeepOutSide) { // On inverse State2;
    if (State2 == TopAbs_IN) State2 = TopAbs_OUT;
    else State2 = TopAbs_IN;
  }
 
//recalcul de la shape finale
  TopoDS_Shape result = DSA.Merge(State1, State2); 

  if (issolid) myShape =  result;
  else {
    TopExp_Explorer Exp;
    Exp.Init(result, TopAbs_SHELL);
    if (Exp.More()) myShape = Exp.Current();
  }

// Mise a jour de l'Historique
  Standard_Integer ii;
  for (ii=1; ii<=myLoc->NbLaw(); ii++) {
    const TopTools_ListOfShape& L = DSA.Modified(myFaces->Value(1,ii));
    if (L.Extent()>0) 
      myFaces->SetValue(1, ii, L.First());
  }
  for (ii=1; ii<=myLoc->NbLaw()+1; ii++) {
    const TopTools_ListOfShape& L = DSA.Modified(mySections->Value(1,ii));
    if (L.Extent()>0) 
      mySections->SetValue(1, ii, L.First());
  } 
 
  return Standard_True;
}

//=======================================================================
//function : Sewing 
//purpose  : Assemble la depouille avec la face du dessus
//======================================================================
 Standard_Boolean BRepFill_Draft::Sewing()
{
  Standard_Boolean ToAss;
  Standard_Boolean Ok = Standard_False;
  ToAss = (myTop.ShapeType() != TopAbs_WIRE);

  if ((!ToAss) || (!myDone)) return Standard_False;

   // Assemblage
  // on fait un shell a partir des faces de la shape + la shape en entree
  Handle(BRepBuilderAPI_Sewing) Ass =  new BRepBuilderAPI_Sewing(5*myTol, Standard_True, 
   		                                     Standard_True, Standard_False);
  Ass->Add(myShape);
  Ass->Add(myTop);
  ToAss = Standard_True;
 

  Standard_Integer NbCE;
  
  Ass->Perform();
  // On verifie que l'assemblage est effectif.
  NbCE = Ass->NbContigousEdges();
  
  if (NbCE > 0) {
    TopoDS_Shape res;
    res = Ass->SewedShape();   
    if ((res.ShapeType() == TopAbs_SHELL)||
	(res.ShapeType() == TopAbs_SOLID))  {
      myShape = res;
      Ok = Standard_True;
    }
    else if (res.ShapeType() == TopAbs_COMPOUND) {
      TopoDS_Iterator It(res);
      res = It.Value();
      It.Next();
      if (!It.More()) {//Une seule partie => c'est bon
	myShape = res;
	Ok = Standard_True;
      }
    }
  }

  if (Ok) {
    // Mise a jour de l'Historique
    Standard_Integer ii;
    for (ii=1; ii<=myLoc->NbLaw(); ii++) {
      if (Ass->IsModified(myFaces->Value(1,ii)))     
	myFaces->SetValue(1, ii, 
			  Ass->Modified(myFaces->Value(1,ii)));
    }
    for (ii=1; ii<=myLoc->NbLaw()+1; ii++) {
      if (Ass->IsModified(mySections->Value(1,ii))) 
	mySections->SetValue(1, ii, 
			     Ass->Modified(mySections->Value(1,ii)));
    }   

    if (myShape.Closed()) { // On fait un Solid
      TopoDS_Solid solid;
      BRep_Builder BS;
      BS.MakeSolid(solid); 
      BS.Add(solid,TopoDS::Shell(myShape));
      
      BRepClass3d_SolidClassifier SC(solid);
      SC.PerformInfinitePoint(Precision::Confusion());
      if ( SC.State() == TopAbs_IN) {
	BS.MakeSolid(solid);
	myShape.Reverse();
	BS.Add(solid,TopoDS::Shell(myShape));
      }
      myShape = solid;
    }    
  }
#if DEB
  else cout << "Draft : Pas d'assemblage !" << endl;
#endif
  return Ok;
}

//=======================================================================
//function : Generated
//purpose  : retourne une sous partie partie generes par balayage
//======================================================================
 const TopTools_ListOfShape& 
 BRepFill_Draft::Generated(const TopoDS_Shape& S) 
{
  myGenerated.Clear();
  TopoDS_Edge E;
  Standard_Integer ii;
  E = TopoDS::Edge(S);
  if (E.IsNull()) {
   for (ii=0; ii<=myLoc->NbLaw(); ii++)
      if (E.IsSame(myLoc->Vertex(ii))) {
	myGenerated.Append(mySections->Value(1, ii+1));
	break;
      } 
  }
  else {
    for (ii=1; ii<=myLoc->NbLaw(); ii++)
      if (E.IsSame(myLoc->Edge(ii))) {
	myGenerated.Append(myFaces->Value(1, ii));
	break;
      }
  }
  
  return myGenerated;
}

//=======================================================================
//function : Shape
//purpose  : retourne la shape complete
//======================================================================
 TopoDS_Shape BRepFill_Draft::Shape()const
{
  return myShape;
}

//=======================================================================
//function : Shell
//purpose  : surface de depouille avec la face entree (=>shell)
//======================================================================
 TopoDS_Shell BRepFill_Draft::Shell()const
{
  return myShell;
}

//=======================================================================
//function : IsDone
//purpose  : 
//======================================================================
 Standard_Boolean BRepFill_Draft::IsDone()const
{
  return myDone;
}
