// File:	BRepFeat_MakePrism.cxx
// Created:	Tue Feb 13 14:42:59 1996
// Author:	Jacques GOUSSARD
//		<jag@bravox>


#include <BRepFeat_MakePrism.ixx>

#include <BRepFeat.hxx>
#include <LocOpe.hxx>
#include <LocOpe_Prism.hxx>
#include <LocOpe_CSIntersector.hxx>
#include <LocOpe_PntFace.hxx>

#include <gp_Vec.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt2d.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Line.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom_Surface.hxx>

#include <BRepLib_MakeFace.hxx>

#include <TColgp_SequenceOfPnt.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Bnd_Box.hxx>

#include <BRep_Tool.hxx>

#include <BRepTools.hxx>


#include <TopExp_Explorer.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopTools_DataMapIteratorOfDataMapOfShapeListOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopTools_ListOfShape.hxx>

#include <BRepBuilderAPI.hxx>
#include <BRepPrimAPI_MakeBox.hxx>

//modified by NIZNHY-PKV Thu Mar 21 18:14:23 2002 f
//#include <BRepAlgo_Cut.hxx>
//#include <BRepAlgo_Fuse.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
//modified by NIZNHY-PKV Thu Mar 21 18:14:26 2002 t

#include <Standard_ConstructionError.hxx>
#include <TopoDS.hxx>


#include <TopoDS_Face.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Compound.hxx>

#include <TopExp.hxx>
#include <BRepBndLib.hxx>

#include <Precision.hxx>
#include <gp_Pln.hxx>
#include <Geom_Plane.hxx>

#ifdef DEB
Standard_IMPORT Standard_Boolean BRepFeat_GettraceFEAT();
#endif

static void MajMap(const TopoDS_Shape&, // base
		   const LocOpe_Prism&,
		   TopTools_DataMapOfShapeListOfShape&, // myMap
		   TopoDS_Shape&,  // myFShape
		   TopoDS_Shape&); // myLShape

static Standard_Boolean ToFuse(const TopoDS_Face& ,
			       const TopoDS_Face&);



#ifdef DEB
static void VerifGluedFaces(const TopoDS_Face& theSkface,
			    const TopoDS_Shape& thePbase,
			    Handle(Geom_Curve)& theBCurve,
			    TColGeom_SequenceOfCurve& theCurves,
			    LocOpe_Prism& thePrism,
			    TopTools_DataMapOfShapeShape& theMap);
#endif

static Standard_Real HeightMax(const TopoDS_Shape& theSbase,
			       const TopoDS_Face& theSkface,
			       const TopoDS_Shape& theSFrom,
			       const TopoDS_Shape& theSUntil);

static Standard_Integer SensOfPrism(const Handle(Geom_Curve) C,
				    const TopoDS_Shape& Until);

static Handle(Geom_Curve) TestCurve(const TopoDS_Shape&,
				    const gp_Vec&);


//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void BRepFeat_MakePrism::Init(const TopoDS_Shape& Sbase,
			      const TopoDS_Shape& Pbase,
			      const TopoDS_Face& Skface,
			      const gp_Dir& Direc,
			      const Standard_Integer Mode,
			      const Standard_Boolean Modify)
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::Init" << endl;
#endif
  mySkface = Skface;
  SketchFaceValid();
  mySbase  = Sbase;
  BasisShapeValid();
  myPbase  = Pbase;
  mySlface.Clear();
  myDir    = Direc;
  if(Mode == 0) {
    myFuse   = Standard_False;
    myJustFeat = Standard_False;
  }
  else if(Mode == 1) {
    myFuse   = Standard_True;
    myJustFeat = Standard_False;
  }
  else if(Mode == 2) {
    myFuse   = Standard_True;
    myJustFeat = Standard_True;
  }
  else {    
  }
  myModify = Modify;
  myJustGluer = Standard_False;


  //-------------- ifv
  //mySkface.Nullify();
  //-------------- ifv


  myShape.Nullify();
  myNewEdges.Clear();
  myTgtEdges.Clear();
  myMap.Clear();
  myFShape.Nullify();
  myLShape.Nullify();
  TopExp_Explorer exp;
  for (exp.Init(mySbase,TopAbs_FACE);exp.More();exp.Next()) {
    TopTools_ListOfShape thelist;
    myMap.Bind(exp.Current(), thelist);
    myMap(exp.Current()).Append(exp.Current());
  }
#ifdef DEB
  if (trc) {
    if (myJustFeat)  cout << " Just Feature" << endl;
    if (myFuse)  cout << " Fuse" << endl;
    if (!myFuse)  cout << " Cut" << endl;
    if (!myModify) cout << " Modify = 0" << endl;
  }
#endif 
}


//=======================================================================
//function : Add
//purpose  : add elements de glissemant (edge sur face)
//=======================================================================

void BRepFeat_MakePrism::Add(const TopoDS_Edge& E,
			     const TopoDS_Face& F)
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::Add(Edge,face)" << endl;
#endif
  TopExp_Explorer exp;
  for (exp.Init(mySbase,TopAbs_FACE);exp.More();exp.Next()) {
    if (exp.Current().IsSame(F)) {
      break;
    }
  }
  if (!exp.More()) {
    Standard_ConstructionError::Raise();
  }
  
  for (exp.Init(myPbase,TopAbs_EDGE);exp.More();exp.Next()) {
    if (exp.Current().IsSame(E)) {
      break;
    }
  }
  if (!exp.More()) {
    Standard_ConstructionError::Raise();
  }
  
  if (!mySlface.IsBound(F)) {
    TopTools_ListOfShape thelist1;
    mySlface.Bind(F, thelist1);
  }
  TopTools_ListIteratorOfListOfShape itl(mySlface(F));
  for (; itl.More();itl.Next()) {
    if (itl.Value().IsSame(E)) {
      break;
    }
  }
  if (!itl.More()) {
    mySlface(F).Append(E);
  }
}


//=======================================================================
//function : Perform
//purpose  : construction du prism de longueur Length et 
//           appel de reconstruction topo
//=======================================================================

void BRepFeat_MakePrism::Perform(const Standard_Real Length)
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::Perform(Length)" << endl;
#endif
  mySFrom.Nullify();
  ShapeFromValid();
  mySUntil.Nullify();
  ShapeUntilValid();
  myGluedF.Clear();
  myPerfSelection = BRepFeat_NoSelection;
  PerfSelectionValid();
  gp_Vec V(Length*myDir);
  
  //construction de prism de hauteur Length

  LocOpe_Prism thePrism(myPbase,V);
  TopoDS_Shape VraiPrism = thePrism.Shape();
  
// gestion des descendants
  MajMap(myPbase,thePrism,myMap,myFShape,myLShape);
  

  myGShape = VraiPrism;    // la primitive
  GeneratedShapeValid();
  
  TopoDS_Face FFace;
  
  Standard_Boolean found = Standard_False;

// essai de detecter des faces de collage 
//cas le top du prism est tgt au shape initial

  if(!mySkface.IsNull() || !mySlface.IsEmpty()) {
    if(myLShape.ShapeType() == TopAbs_WIRE) {
      TopExp_Explorer ex1(VraiPrism, TopAbs_FACE);
      for(; ex1.More(); ex1.Next()) {
	TopExp_Explorer ex2(ex1.Current(), TopAbs_WIRE);
	for(; ex2.More(); ex2.Next()) {
	  if(ex2.Current().IsSame(myLShape)) {
	    FFace = TopoDS::Face(ex1.Current());
	    found = Standard_True;
	    break;
	  }
	}
	if(found) break;
      }
    }
    
    TopExp_Explorer exp(mySbase, TopAbs_FACE);
    for(; exp.More(); exp.Next()) {
      const TopoDS_Face& ff = TopoDS::Face(exp.Current());
      if(ToFuse(ff, FFace)) {
	TopTools_DataMapOfShapeListOfShape sl;
	if(!FFace.IsSame(myPbase) && BRepFeat::IsInside(ff, FFace)) 
//	  SetGluedFaces(ff, mySbase, FFace, sl, thePrism, myGluedF);
	break;
      }
    }
  }

// gestion des faces de collage donnees par l'utilisateur

//  SetGluedFaces(mySkface, mySbase, myPbase, mySlface, thePrism, myGluedF);
  GluedFacesValid();
//  VerifGluedFaces(mySkface, myPbase, myBCurve, myCurves, thePrism, myGluedF);

  if(!myGluedF.IsEmpty()) {   // cas collage
    myJustGluer = Standard_True;
    thePrism.Curves(myCurves);
    myBCurve = thePrism.BarycCurve();    
    GlobalPerform();  // reconstruction topologique
  }

// si il n'y a pas de collage -> appel des ope topo
  if(!myJustGluer) {
    if(myFuse == 1 && !myJustFeat) {
      //modified by NIZNHY-PKV Thu Mar 21 17:55:30 2002 f
      //BRepAlgo_Fuse f(mySbase, myGShape);
      //myShape = f.Shape();
      //UpdateDescendants(f.Builder(), myShape, Standard_False);
      BRepAlgoAPI_Fuse f(mySbase, myGShape);
      myShape = f.Shape();
      UpdateDescendants(f, myShape, Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 17:55:34 2002 t
      Done();
    }
    else if(myFuse == 0) {
      //modified by NIZNHY-PKV Thu Mar 21 17:55:59 2002 f
      //BRepAlgo_Cut c(mySbase, myGShape);
      //myShape = c.Shape();
      //UpdateDescendants(c.Builder(), myShape, Standard_False);
      BRepAlgoAPI_Cut c(mySbase, myGShape);
      myShape = c.Shape();
      UpdateDescendants(c, myShape, Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 17:56:02 2002 t
      Done();
    }
    else {
      myShape = myGShape;
      Done();
    }
  }
}


//=======================================================================
//function : Perform
//purpose  : construction de prism oriente vers la face Until, suffisemment
//           long; appel de reconstruction topo          
//=======================================================================

void BRepFeat_MakePrism::Perform(const TopoDS_Shape& Until)
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::Perform(Until)" << endl;
#endif
  if (Until.IsNull()) {
    Standard_ConstructionError::Raise();
  }
  TopExp_Explorer exp(Until, TopAbs_FACE);
  if (!exp.More()) {
    Standard_ConstructionError::Raise();
  }
  myGluedF.Clear();
  myPerfSelection = BRepFeat_SelectionU;
  PerfSelectionValid();
  mySFrom.Nullify();
  ShapeFromValid();
  mySUntil = Until;
  Standard_Boolean Trf = TransformShapeFU(1);  
  ShapeUntilValid();
  Handle(Geom_Curve) C = TestCurve(myPbase,myDir);  
  Standard_Integer sens = SensOfPrism(C, mySUntil);
  Standard_Real Height = HeightMax(mySbase, mySkface, mySFrom, mySUntil);
  gp_Vec V(2*sens*Height*myDir);

// construction du prism long
  LocOpe_Prism thePrism(myPbase,V);
  TopoDS_Shape VraiPrism = thePrism.Shape();

// dans le cas de support de face Until
  if(!Trf) {    
    MajMap(myPbase,thePrism,myMap,myFShape,myLShape);    
    myGShape = VraiPrism;
    GeneratedShapeValid();

    //SetGluedFaces(mySkface, mySbase, myPbase, mySlface, thePrism, myGluedF);
    GluedFacesValid();
//    VerifGluedFaces(mySkface, myPbase, myBCurve, myCurves, thePrism, myGluedF);

    thePrism.Curves(myCurves);
    myBCurve = thePrism.BarycCurve();
    GlobalPerform();
  }
  else {    // until support -> passage en ope topo
    MajMap(myPbase,thePrism,myMap,myFShape,myLShape);    
    TColGeom_SequenceOfCurve scur;
    scur.Clear();    
    scur.Append(C);

// sens du prism en fonction de Until

    LocOpe_CSIntersector ASI(mySUntil);
    ASI.Perform(scur);
    TopAbs_Orientation Or;
    if (ASI.IsDone() && ASI.NbPoints(1) >=1) {
      if (myFuse == 1) {
	Or = ASI.Point(1,1).Orientation();
      }
      else {
	Or = ASI.Point(1,ASI.NbPoints(1)).Orientation();
      }
      if(sens==-1) Or=TopAbs::Reverse(Or);
      TopoDS_Face FUntil = ASI.Point(1,1).Face();
      TopoDS_Shape Comp;
      BRep_Builder B;
      B.MakeCompound(TopoDS::Compound(Comp));
      TopoDS_Solid S = BRepFeat::Tool(mySUntil, FUntil, Or);
      if (!S.IsNull()) B.Add(Comp,S);
      //modified by NIZNHY-PKV Thu Mar 21 17:56:31 2002 f
      //BRepAlgo_Cut trP(VraiPrism,Comp);
      //UpdateDescendants(trP.Builder(),trP.Shape(), Standard_False);
      BRepAlgoAPI_Cut trP(VraiPrism,Comp);
      UpdateDescendants(trP, trP.Shape(), Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 17:56:38 2002 t
      TopExp_Explorer ex(trP.Shape(), TopAbs_SOLID);
      TopoDS_Shape Cutsh = ex.Current();
      if(myFuse == 1 && !myJustFeat) {
	//modified by NIZNHY-PKV Thu Mar 21 17:57:49 2002 f
	//BRepAlgo_Fuse f(mySbase, Cutsh);
	//myShape = f.Shape();
	//UpdateDescendants(f.Builder(), myShape, Standard_False);
	BRepAlgoAPI_Fuse f(mySbase, Cutsh);
	myShape = f.Shape();
	UpdateDescendants(f, myShape, Standard_False);
	//modified by NIZNHY-PKV Thu Mar 21 17:57:53 2002 t
	Done();
      }
      else if(myFuse == 0) {
	//modified by NIZNHY-PKV Thu Mar 21 17:59:33 2002 f
	//BRepAlgo_Cut c(mySbase, Cutsh);
	//myShape = c.Shape();
	//UpdateDescendants(c.Builder(), myShape, Standard_False);
	BRepAlgoAPI_Cut c(mySbase, Cutsh);
	myShape = c.Shape();
	UpdateDescendants(c, myShape, Standard_False);
	//modified by NIZNHY-PKV Thu Mar 21 17:59:43 2002 t
	Done();
      }
      else {
	myShape = Cutsh;
	Done();	
      }
    }         
  }
/*   // boucle de controle de descendance

  TopExp_Explorer expr(mySbase, TopAbs_FACE);
  char nom1[20], nom2[20];
  Standard_Integer ii = 0;
  for(; expr.More(); expr.Next()) {
    ii++;
    sprintf(nom1, "faceinitial_%d", ii);
    DBRep::Set(nom1, expr.Current());
    Standard_Integer jj = 0;
    const TopTools_ListOfShape& list = Modified(expr.Current());
    TopTools_ListIteratorOfListOfShape ite(list);
    for(; ite.More(); ite.Next()) {
      jj++;
      sprintf(nom2, "facemodifie_%d_%d", ii, jj);
      DBRep::Set(nom2, ite.Value());
    }
  }

  expr.Init(myPbase, TopAbs_EDGE);
  ii=0;
  for(; expr.More(); expr.Next()) {
    ii++;
    sprintf(nom1, "edgeinitial_%d", ii);
    DBRep::Set(nom1, expr.Current());
    Standard_Integer jj = 0;
    const TopTools_ListOfShape& list = Generated(expr.Current());
    TopTools_ListIteratorOfListOfShape ite(list);
    for(; ite.More(); ite.Next()) {
      jj++;
      sprintf(nom2, "facegeneree_%d_%d", ii, jj);
      DBRep::Set(nom2, ite.Value());
    }
  }
*/
}


//=======================================================================
//function : Perform
//purpose  : construction d'un prisme suffisemment long et bien oriente
//           appel de reconstruction topo
//=======================================================================

void BRepFeat_MakePrism::Perform(const TopoDS_Shape& From,
				 const TopoDS_Shape& Until)
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::Perform(From,Until)" << endl;
#endif
  if (From.IsNull() || Until.IsNull()) {
    Standard_ConstructionError::Raise();
  }

  if (!mySkface.IsNull()) {
    if (From.IsSame(mySkface)) {
      myJustGluer = Standard_True;
      Perform(Until);
      if (myJustGluer) return;
    }
    else if (Until.IsSame(mySkface)) {
      myJustGluer = Standard_True;
      Perform(From);
      if (myJustGluer) return;
    } 
  }
  
  myGluedF.Clear();
  myPerfSelection = BRepFeat_SelectionFU;
  PerfSelectionValid();
  
  TopExp_Explorer exp(From, TopAbs_FACE);
  if (!exp.More()) {
    Standard_ConstructionError::Raise();
  }
  exp.Init(Until, TopAbs_FACE);
  if (!exp.More()) {
    Standard_ConstructionError::Raise();
  }
  mySFrom = From;
  Standard_Boolean Trff = TransformShapeFU(0);
  ShapeFromValid();
  mySUntil = Until;
  Standard_Boolean Trfu = TransformShapeFU(1);
  ShapeUntilValid();  
  if(Trfu != Trff) {
    NotDone();
    myStatusError = BRepFeat_IncTypes;
    return;
  }

// longueur en fonction des boites englobantes

  Standard_Real Height = HeightMax(mySbase, mySkface, mySFrom, mySUntil);
  Handle(Geom_Curve) C = TestCurve(myPbase,myDir);  
  Standard_Integer sens;  // sens de prism
  Standard_Integer tran;  // transfert de prism
  if(From.IsSame(Until)) {
    sens = 1;
    tran = -1;
  }
  else {
    sens = SensOfPrism(C, mySUntil);
    tran = sens*SensOfPrism(C, mySFrom);
  }
  LocOpe_Prism thePrism;   
  if(tran < 0) {
    gp_Vec Vtra(-3*Height*sens/2.*myDir);
    thePrism.Perform(myPbase,3*sens*Height*myDir,Vtra);
  }
  else {
    thePrism.Perform(myPbase,2*sens*Height*myDir);
  }
  TopoDS_Shape VraiPrism = thePrism.Shape();
  
  if(!Trff) {
    MajMap(myPbase,thePrism,myMap,myFShape,myLShape);
    
    myGShape = VraiPrism;
    GeneratedShapeValid();

    //SetGluedFaces(TopoDS_Face(), // on ne veut pas binder mySkface
	//	  mySbase, myPbase, mySlface, thePrism, myGluedF);
    GluedFacesValid();
////    VerifGluedFaces(mySkface, myPbase, myBCurve, myCurves, thePrism, myGluedF);

    thePrism.Curves(myCurves);
    myBCurve = thePrism.BarycCurve();
    GlobalPerform();
  }
  else {    // cas until support -> ope topo
    MajMap(myPbase,thePrism,myMap,myFShape,myLShape);    
    TColGeom_SequenceOfCurve scur;
    scur.Clear();    
    scur.Append(C);
    LocOpe_CSIntersector ASI1(mySUntil);
    LocOpe_CSIntersector ASI2(mySFrom);
    ASI1.Perform(scur);
    ASI2.Perform(scur);
    TopAbs_Orientation OrU, OrF;
    TopoDS_Face FFrom, FUntil;
    if (ASI1.IsDone() && ASI1.NbPoints(1) >=1) {
      if (myFuse == 1) {
	OrU = ASI1.Point(1,1).Orientation();
      }
      else {
	OrU = ASI1.Point(1,ASI1.NbPoints(1)).Orientation();
      }
      if(sens==-1) OrU = TopAbs::Reverse(OrU);
      FUntil = ASI1.Point(1,1).Face();
    }
    else {
      NotDone();
      myStatusError = BRepFeat_NoIntersectU;
      return;
    }
    if (ASI2.IsDone() && ASI2.NbPoints(1) >=1) {
      OrF = ASI2.Point(1,1).Orientation();
      if(sens==1) OrF = TopAbs::Reverse(OrF);
      FFrom = ASI2.Point(1,1).Face();
    }
    else {
      NotDone();
      myStatusError = BRepFeat_NoIntersectF;
      return;
    }
    TopoDS_Shape Comp;
    BRep_Builder B;
    B.MakeCompound(TopoDS::Compound(Comp));
    TopoDS_Solid S = BRepFeat::Tool(mySUntil, FUntil, OrU);
    if (!S.IsNull()) {
      B.Add(Comp,S);
    }
    else {
      NotDone();
      myStatusError = BRepFeat_NullToolU;
      return;
    }
    TopoDS_Solid SS = BRepFeat::Tool(mySFrom, FFrom, OrF);
    if (!SS.IsNull()) {
      B.Add(Comp,SS);
    }
    else {
      NotDone();
      myStatusError = BRepFeat_NullToolF;
      return;
    }
    //modified by NIZNHY-PKV Thu Mar 21 18:00:10 2002 f
    //BRepAlgo_Cut trP(VraiPrism,Comp);
    //UpdateDescendants(trP.Builder(), trP.Shape(), Standard_False);
    BRepAlgoAPI_Cut trP(VraiPrism,Comp);
    UpdateDescendants(trP, trP.Shape(), Standard_False);
    //modified by NIZNHY-PKV Thu Mar 21 18:00:16 2002 t
    if(myFuse == 1 && !myJustFeat) {
      //modified by NIZNHY-PKV Thu Mar 21 18:00:35 2002 f
      //BRepAlgo_Fuse f(mySbase, trP.Shape());
      //myShape = f.Shape();
      //UpdateDescendants(f.Builder(), myShape, Standard_False);
      BRepAlgoAPI_Fuse f(mySbase, trP.Shape());
      myShape = f.Shape();
      UpdateDescendants(f, myShape, Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 18:00:40 2002 t
      Done();
    }
    else if(myFuse == 0) {
      //modified by NIZNHY-PKV Thu Mar 21 18:01:01 2002 f
      //BRepAlgo_Cut c(mySbase, trP.Shape());
      //myShape = c.Shape();
      //UpdateDescendants(c.Builder(), myShape, Standard_False);
      BRepAlgoAPI_Cut c(mySbase, trP.Shape());
      myShape = c.Shape();
      UpdateDescendants(c, myShape, Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 18:01:13 2002 t
      Done();
    }
    else {
      myShape = trP.Shape();
      Done();	
    }
  }         
// controle historique
/*
  TopExp_Explorer expr(mySbase, TopAbs_FACE);
  char nom1[20], nom2[20];
  Standard_Integer ii = 0;
  for(; expr.More(); expr.Next()) {
    ii++;
    sprintf(nom1, "faceinitial_%d", ii);
    DBRep::Set(nom1, expr.Current());
    Standard_Integer jj = 0;
    const TopTools_ListOfShape& list = Modified(expr.Current());
    TopTools_ListIteratorOfListOfShape ite(list);
    for(; ite.More(); ite.Next()) {
      jj++;
      sprintf(nom2, "facemodifie_%d_%d", ii, jj);
      DBRep::Set(nom2, ite.Value());
    }
  }

  expr.Init(myPbase, TopAbs_EDGE);
  ii=0;
  for(; expr.More(); expr.Next()) {
    ii++;
    sprintf(nom1, "edgeinitial_%d", ii);
    DBRep::Set(nom1, expr.Current());
    Standard_Integer jj = 0;
    const TopTools_ListOfShape& list = Generated(expr.Current());
    TopTools_ListIteratorOfListOfShape ite(list);
    for(; ite.More(); ite.Next()) {
      jj++;
      sprintf(nom2, "egdegeneree_%d_%d", ii, jj);
      DBRep::Set(nom2, ite.Value());
    }
  }
*/
}



//=======================================================================
//function : PerformUntilEnd
//purpose  : construction d'un prism et reconstruction
//=======================================================================

void BRepFeat_MakePrism::PerformUntilEnd()
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::PerformUntilEnd()" << endl;
#endif
  myPerfSelection = BRepFeat_SelectionSh;
  PerfSelectionValid();
  myGluedF.Clear();
  mySUntil.Nullify();
  ShapeUntilValid();
  mySFrom.Nullify();
  ShapeFromValid();
  Standard_Real Height = HeightMax(mySbase, mySkface, mySFrom, mySUntil);
  gp_Vec V(2*Height*myDir);
  
  LocOpe_Prism thePrism(myPbase,V);
  TopoDS_Shape VraiPrism = thePrism.Shape();
  
  MajMap(myPbase,thePrism,myMap,myFShape,myLShape);
  
  myGShape = VraiPrism;
  GeneratedShapeValid();
  GluedFacesValid();

  if(myFuse == 0) {
    //modified by NIZNHY-PKV Thu Mar 21 18:02:46 2002 f
    //BRepAlgo_Cut c(mySbase, myGShape);
    BRepAlgoAPI_Cut c(mySbase, myGShape);
    //modified by NIZNHY-PKV Thu Mar 21 18:03:15 2002 t
    if (c.IsDone()) {
      myShape = c.Shape();
      //modified by NIZNHY-PKV Thu Mar 21 18:03:38 2002 f
      //UpdateDescendants(c.Builder(), myShape, Standard_False);
      UpdateDescendants(c, myShape, Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 18:03:42 2002 t
      Done();
    }
  }
  else {
    thePrism.Curves(myCurves);
    myBCurve = thePrism.BarycCurve();
    GlobalPerform();
  }
}

//=======================================================================
//function : PerformFromEnd
//purpose  : 
//=======================================================================

void BRepFeat_MakePrism::PerformFromEnd(const TopoDS_Shape& Until)
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::PerformFromEnd(From,Until)" << endl;
#endif
  if (Until.IsNull()) {
    Standard_ConstructionError::Raise();
  }
  if (!mySkface.IsNull() && Until.IsSame(mySkface)) {
    myDir.Reverse();
    PerformUntilEnd();
    return;
  }
  TopExp_Explorer exp;
  exp.Init(Until, TopAbs_FACE);
  if (!exp.More()) {
    Standard_ConstructionError::Raise();
  }
  myPerfSelection = BRepFeat_SelectionShU;
  PerfSelectionValid();
  mySFrom.Nullify();
  ShapeFromValid();
  mySUntil = Until;
  Standard_Boolean Trf = TransformShapeFU(1);
  ShapeUntilValid();
  Handle(Geom_Curve) C = TestCurve(myPbase,myDir);  
  Standard_Integer sens = SensOfPrism(C, mySUntil);
  Standard_Real Height = HeightMax(mySbase, mySkface, mySFrom, mySUntil);
  gp_Vec Vtra(-3*Height*sens/2.*myDir);
  gp_Vec Vect(3*sens*Height*myDir);
  LocOpe_Prism thePrism(myPbase,Vect,Vtra);
  TopoDS_Shape VraiPrism = thePrism.Shape();
  
  if(!Trf) {  // cas face until 
    MajMap(myPbase,thePrism,myMap,myFShape,myLShape);
    myGShape = VraiPrism;
    GeneratedShapeValid();
    myGluedF.Clear();
    GluedFacesValid();
    thePrism.Curves(myCurves);
    myBCurve = thePrism.BarycCurve();
    GlobalPerform();
  }
  else {   // cas support
    MajMap(myPbase,thePrism,myMap,myFShape,myLShape);    
    TColGeom_SequenceOfCurve scur;
    scur.Clear();    
    scur.Append(C);
    LocOpe_CSIntersector ASI1(mySUntil);
    LocOpe_CSIntersector ASI2(mySbase);
    ASI1.Perform(scur);
    ASI2.Perform(scur);
#ifndef DEB
    TopAbs_Orientation OrU = TopAbs_FORWARD, OrF = TopAbs_FORWARD;
#else
    TopAbs_Orientation OrU, OrF;
#endif
    TopoDS_Face FUntil, FFrom;
    if (ASI1.IsDone() && ASI1.NbPoints(1) >=1) {
      OrU = ASI1.Point(1,1).Orientation();
      if(sens==-1) {
	OrU = TopAbs::Reverse(OrU);
      }
      FUntil = ASI1.Point(1,1).Face();
    }
    if (ASI2.IsDone() && ASI2.NbPoints(1) >=1) {
      OrF = ASI2.Point(1,1).Orientation();
//      if(sens==1) OrF = TopAbs::Reverse(OrF);
      FFrom = ASI2.Point(1 ,1).Face();
      Handle(Geom_Surface) S = BRep_Tool::Surface(FFrom);
      if (S->DynamicType() == 
	  STANDARD_TYPE(Geom_RectangularTrimmedSurface)) {
	S = Handle(Geom_RectangularTrimmedSurface)::
	  DownCast(S)->BasisSurface();
      }
      BRepLib_MakeFace fac(S);
      mySFrom = fac.Face();  
      Trf = TransformShapeFU(0);
      FFrom = TopoDS::Face(mySFrom);
    }
//    else {
//      NotDone();
//      return;
//    }
    TopoDS_Shape Comp;
    BRep_Builder B;
    B.MakeCompound(TopoDS::Compound(Comp));
    TopoDS_Solid Sol = BRepFeat::Tool(mySUntil, FUntil, OrU);
    if (!Sol.IsNull()) {
      B.Add(Comp,Sol);
    }
    else {
      NotDone();
      myStatusError = BRepFeat_NullToolU;
      return;
    }

    TopoDS_Solid Sol1 = BRepFeat::Tool(mySFrom, FFrom, OrF);
    if (!Sol1.IsNull()) {
      B.Add(Comp,Sol1);
    }
    else {
      NotDone();
      myStatusError = BRepFeat_NullToolF;
      return;
    }
    //modified by NIZNHY-PKV Thu Mar 21 18:03:57 2002 f
    //BRepAlgo_Cut trP(VraiPrism,Comp);
    //UpdateDescendants(trP.Builder(), trP.Shape(), Standard_False);
    BRepAlgoAPI_Cut trP(VraiPrism,Comp);
    UpdateDescendants(trP, trP.Shape(), Standard_False);
    //modified by NIZNHY-PKV Thu Mar 21 18:04:08 2002 t
    if(myFuse == 1 && !myJustFeat) {
      //modified by NIZNHY-PKV Thu Mar 21 18:04:33 2002 f
      //BRepAlgo_Fuse f(mySbase, trP.Shape());
      //myShape = f.Shape();
      //UpdateDescendants(f.Builder(), myShape, Standard_False);
      BRepAlgoAPI_Fuse f(mySbase, trP.Shape());
      myShape = f.Shape();
      UpdateDescendants(f, myShape, Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 18:04:41 2002 t
      Done();
    }
    else if(myFuse == 0) {
      //modified by NIZNHY-PKV Thu Mar 21 18:04:54 2002 f
      //BRepAlgo_Cut c(mySbase, trP.Shape());
      //myShape = c.Shape();
      //UpdateDescendants(c.Builder(), myShape, Standard_False);
      BRepAlgoAPI_Cut c(mySbase, trP.Shape());
      myShape = c.Shape();
      UpdateDescendants(c, myShape, Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 18:05:00 2002 t
      Done();
    }
    else {
      myShape = trP.Shape();
      Done();	
    }
  }         
}



//=======================================================================
//function : PerformThruAll
//purpose  : 
//=======================================================================

void BRepFeat_MakePrism::PerformThruAll()
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::PerformThruAll()" << endl;
#endif
  mySUntil.Nullify();
  ShapeUntilValid();
  mySFrom.Nullify();
  ShapeFromValid();
  if(myFuse == 0) {
    myPerfSelection = BRepFeat_NoSelection;
  }
  else {
    myPerfSelection = BRepFeat_SelectionSh;
  }
  PerfSelectionValid();
  myGluedF.Clear();
  GluedFacesValid();

  Standard_Real Height = HeightMax(mySbase, mySkface, mySFrom, mySUntil);
  gp_Vec V(3*Height*myDir);
  gp_Vec Vtra(-3*Height/2.*myDir);
  LocOpe_Prism thePrism(myPbase,V,Vtra);
  TopoDS_Shape VraiPrism = thePrism.Shape();
  MajMap(myPbase,thePrism,myMap,myFShape,myLShape);

  myGShape = VraiPrism;
  GeneratedShapeValid();  

  if(myFuse == 0) {
    //modified by NIZNHY-PKV Thu Mar 21 18:05:31 2002 f
    //BRepAlgo_Cut c(mySbase, myGShape);
    BRepAlgoAPI_Cut c(mySbase, myGShape);
    //modified by NIZNHY-PKV Thu Mar 21 18:05:33 2002 t
    if (c.IsDone()) {
      myShape = c.Shape();
      //modified by NIZNHY-PKV Thu Mar 21 18:05:46 2002 f
      //UpdateDescendants(c.Builder(), myShape, Standard_False);
      UpdateDescendants(c, myShape, Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 18:05:50 2002 t
      Done();
    }
  }
  else {
    thePrism.Curves(myCurves);
    myBCurve = thePrism.BarycCurve();
    GlobalPerform();
  }
}


//=======================================================================
//function : PerformUntilHauteur
//purpose  : 
//=======================================================================

void BRepFeat_MakePrism::PerformUntilHeight(const TopoDS_Shape& Until,
					     const Standard_Real Length)
{
#ifdef DEB
  Standard_Boolean trc = BRepFeat_GettraceFEAT();
  if (trc) cout << "BRepFeat_MakePrism::PerformUntilHeight(Until,Length)" << endl;
#endif
  if (Until.IsNull()) {
    Perform(Length);
  }
  if(Length == 0) {
    Perform(Until);
  }
  TopExp_Explorer exp(Until, TopAbs_FACE);
  if (!exp.More()) {
    Standard_ConstructionError::Raise();
  }
  myGluedF.Clear();
  myPerfSelection = BRepFeat_NoSelection;
  PerfSelectionValid();
  mySFrom.Nullify();
  ShapeFromValid();
  mySUntil = Until;
  Standard_Boolean Trf = TransformShapeFU(1);
  ShapeUntilValid();
  Handle(Geom_Curve) C = TestCurve(myPbase,myDir);  
  Standard_Integer sens = SensOfPrism(C, mySUntil);
  gp_Vec V(sens*Length*myDir);
  LocOpe_Prism thePrism(myPbase,V);
  TopoDS_Shape VraiPrism = thePrism.Shape();

  if(!Trf) {
    MajMap(myPbase,thePrism,myMap,myFShape,myLShape);
    
    myGShape = VraiPrism;
    GeneratedShapeValid();

    //SetGluedFaces(mySkface, mySbase, myPbase, mySlface, thePrism, myGluedF);
    GluedFacesValid();
//    VerifGluedFaces(mySkface, myPbase, myBCurve, myCurves, thePrism, myGluedF);

    thePrism.Curves(myCurves);
    myBCurve = thePrism.BarycCurve();
    GlobalPerform();
  }
  else {
    MajMap(myPbase,thePrism,myMap,myFShape,myLShape);    
    TColGeom_SequenceOfCurve scur;
    scur.Clear();    
    scur.Append(C);
    LocOpe_CSIntersector ASI(mySUntil);
    ASI.Perform(scur);
    TopAbs_Orientation Or;
    if (ASI.IsDone() && ASI.NbPoints(1) >=1) {
      if (myFuse == 1) {
	Or = ASI.Point(1,1).Orientation();
      }
      else {
	Or = ASI.Point(1,ASI.NbPoints(1)).Orientation();
      }
      if(sens==-1) Or=TopAbs::Reverse(Or);
      TopoDS_Face FUntil = ASI.Point(1,1).Face();
      TopoDS_Shape Comp;
      BRep_Builder B;
      B.MakeCompound(TopoDS::Compound(Comp));
      TopoDS_Solid S = BRepFeat::Tool(mySUntil, FUntil, Or);
      if (!S.IsNull()) B.Add(Comp,S);

      //modified by NIZNHY-PKV Thu Mar 21 18:06:09 2002 f
      //BRepAlgo_Cut trP(VraiPrism,Comp);
      //UpdateDescendants(trP.Builder(), trP.Shape(), Standard_False);
      BRepAlgoAPI_Cut trP(VraiPrism,Comp);
      UpdateDescendants(trP, trP.Shape(), Standard_False);
      //modified by NIZNHY-PKV Thu Mar 21 18:06:15 2002 t
      if(myFuse == 1 && !myJustFeat) {
	//modified by NIZNHY-PKV Thu Mar 21 18:06:36 2002 f
	//BRepAlgo_Fuse f(mySbase, trP.Shape());
	//myShape = f.Shape();
	//UpdateDescendants(f.Builder(), myShape, Standard_False);
	BRepAlgoAPI_Fuse f(mySbase, trP.Shape());
	myShape = f.Shape();
	UpdateDescendants(f, myShape, Standard_False);
	//modified by NIZNHY-PKV Thu Mar 21 18:06:41 2002 t
	Done();
      }
      else if(myFuse == 0) {
	//modified by NIZNHY-PKV Thu Mar 21 18:07:06 2002 f
	//BRepAlgo_Cut c(mySbase, trP.Shape());
	//myShape = c.Shape();
	//UpdateDescendants(c.Builder(), myShape, Standard_False);
	BRepAlgoAPI_Cut c(mySbase, trP.Shape());
	myShape = c.Shape();
	UpdateDescendants(c, myShape, Standard_False);
	//modified by NIZNHY-PKV Thu Mar 21 18:07:12 2002 t
	Done();
      }
      else {
	myShape = trP.Shape();
	Done();	
      }
    }         
  }
}

//=======================================================================
//function : Curves
//purpose  : sequence de courbes paralleles a l'axe de prism 
//=======================================================================

void BRepFeat_MakePrism::Curves(TColGeom_SequenceOfCurve& scur)
{
  scur = myCurves;
}

//=======================================================================
//function : BarycCurve
//purpose  : courbe parallele a l'axe du prisme passant par le centre des 
//           masses
//=======================================================================

Handle(Geom_Curve) BRepFeat_MakePrism::BarycCurve()
{
  return myBCurve;
}


//=======================================================================
//function : HeightMax
//purpose  : Calcul de la hauteur du prisme selon les parametres de
//           boite englobante
//=======================================================================

static Standard_Real HeightMax(const TopoDS_Shape& theSbase,
			       const TopoDS_Face&  theSkface,
			       const TopoDS_Shape& theSFrom,
			       const TopoDS_Shape& theSUntil)
{
  Bnd_Box Box;
  BRepBndLib::Add(theSbase,Box);
  BRepBndLib::Add(theSkface,Box);
  if(!theSFrom.IsNull()) {
#ifndef DEB
    Standard_Boolean FacRevolInfini = Standard_False;
#else
    Standard_Boolean FacRevolInfini;
#endif
    TopExp_Explorer exp;
    exp.Init(theSFrom, TopAbs_EDGE);
    for(; exp.More(); exp.Next()) {
      TopExp_Explorer exp1;
      exp1.Init(exp.Current(), TopAbs_VERTEX);
      if(!exp1.More()) {
	FacRevolInfini = Standard_True;
	break;
      }
    }
    if(!FacRevolInfini)
      BRepBndLib::Add(theSFrom,Box);
  }
  if(!theSUntil.IsNull()) {
#ifndef DEB
    Standard_Boolean FacRevolInfini = Standard_False;
#else
    Standard_Boolean FacRevolInfini;
#endif
    TopExp_Explorer exp;
    exp.Init(theSUntil, TopAbs_EDGE);
    for(; exp.More(); exp.Next()) {
      TopExp_Explorer exp1;
      exp1.Init(exp.Current(), TopAbs_VERTEX);
      if(!exp1.More()) {
	FacRevolInfini = Standard_True;
	break;
      }
    }
    if(!FacRevolInfini)
      BRepBndLib::Add(theSUntil,Box);
  }

  Standard_Real c[6];

  Box.Get(c[0],c[2],c[4],c[1],c[3],c[5]);
  Standard_Real parmin=c[0], parmax = c[0];
  for(Standard_Integer i = 0 ; i < 6; i++) {
    if(c[i] > parmax) parmax = c[i];
    if(c[i] < parmin ) parmin = c[i];    
  }
//#ifndef DEB
  Standard_Real Height = fabs(2.*(parmax - parmin));
//#else
//  Standard_Real Height = abs(2.*(parmax - parmin));
//#endif
  return(Height);
}


//=======================================================================
//function : SensOfPrism
//purpose  : sens de prism en fonction du shape Until
//=======================================================================
Standard_Integer SensOfPrism(const Handle(Geom_Curve) C,
			     const TopoDS_Shape& Until)
{
  LocOpe_CSIntersector ASI1(Until);
  TColGeom_SequenceOfCurve scur;
  scur.Append(C);
  ASI1.Perform(scur);
  Standard_Integer sens = 1;
  if(ASI1.IsDone() && ASI1.NbPoints(1) >= 1) {
    if(ASI1.Point(1, 1).Parameter() < 0. && 
       ASI1.Point(1, ASI1.NbPoints(1)).Parameter() < 0.) {
      sens = -1;
    }
  }
  else if(BRepFeat::ParametricBarycenter(Until,C) < 0) {
      sens = -1;
  }
  else {}
  return sens;
}




//=======================================================================
//function : VerifGluedFaces
//purpose  : Verification  intersection Outil/theSkface = thePbase
//           Si oui -> OK si non -> cas sans collage
//=======================================================================
#ifdef DEB
static void VerifGluedFaces(const TopoDS_Face& theSkface,
			    const TopoDS_Shape& thePbase,
			    Handle(Geom_Curve)& theBCurve,
			    TColGeom_SequenceOfCurve& theCurves,
			    LocOpe_Prism& thePrism,
			    TopTools_DataMapOfShapeShape& theMap)
{
  Standard_Boolean GluedFaces = Standard_True;
  TopoDS_Shape VraiPrism = thePrism.Shape();
  
  TColGeom_SequenceOfCurve scur;
  thePrism.Curves(theCurves);
  theBCurve = thePrism.BarycCurve();    
  scur.Clear();    
  scur.Append(theBCurve);
  LocOpe_CSIntersector ASI(theSkface);
  ASI.Perform(scur);
  if (ASI.IsDone() && ASI.NbPoints(1) >=1) {
    TopAbs_Orientation Or = ASI.Point(1,1).Orientation();
    TopoDS_Face FSk = ASI.Point(1,1).Face();
    TopoDS_Shape Comp;
    BRep_Builder B;
    B.MakeCompound(TopoDS::Compound(Comp));
    TopoDS_Solid S = BRepFeat::Tool(theSkface, FSk, Or);
    if (!S.IsNull()) B.Add(Comp,S);
    //modified by NIZNHY-PKV Thu Mar 21 18:07:35 2002 f
    //BRepAlgo_Cut trP(VraiPrism,Comp);
    BRepAlgoAPI_Cut trP(VraiPrism,Comp);
    //modified by NIZNHY-PKV Thu Mar 21 18:07:39 2002 t
    TopoDS_Shape Cutsh = trP.Shape();
    TopExp_Explorer ex(Cutsh, TopAbs_SOLID);
    for(; ex.More(); ex.Next()) {
      TopExp_Explorer ex1(ex.Current(), TopAbs_FACE);
      for(; ex1.More(); ex1.Next()) {
	const TopoDS_Face& fac1 = TopoDS::Face(ex1.Current());
	TopExp_Explorer ex2(thePbase, TopAbs_FACE);
	for(; ex2.More(); ex2.Next()) {
	  const TopoDS_Face& fac2 = TopoDS::Face(ex2.Current());
	  if(fac1.IsSame(fac2)) break;
	}
	if (ex2.More()) break;
      }
      if (ex1.More()) continue;
      GluedFaces = Standard_False;
      break;
    }
    if (!GluedFaces) {
#ifdef DEB
      Standard_Boolean trc = BRepFeat_GettraceFEAT();
      if (trc) cout << " Intersection Prism/skface : pas de collage" << endl;
#endif
      theMap.Clear();
    }
  }
}
#endif

//=======================================================================
//function : MajMap
//purpose  : gestion des descendants
//=======================================================================

static void MajMap(const TopoDS_Shape& theB,
		   const LocOpe_Prism& theP,
		   TopTools_DataMapOfShapeListOfShape& theMap, // myMap
		   TopoDS_Shape& theFShape,  // myFShape
		   TopoDS_Shape& theLShape) // myLShape
{
  TopExp_Explorer exp(theP.FirstShape(),TopAbs_WIRE);
  if (exp.More()) {
    theFShape = exp.Current();
    TopTools_ListOfShape thelist2;
    theMap.Bind(theFShape, thelist2);
    for (exp.Init(theP.FirstShape(),TopAbs_FACE);exp.More();exp.Next()) {
      theMap(theFShape).Append(exp.Current());
    }
  }
  
  exp.Init(theP.LastShape(),TopAbs_WIRE);
  if (exp.More()) {
    theLShape = exp.Current();
    TopTools_ListOfShape thelist3;
    theMap.Bind(theLShape, thelist3);
    for (exp.Init(theP.LastShape(),TopAbs_FACE);exp.More();exp.Next()) {
      theMap(theLShape).Append(exp.Current());
    }
  }

  for (exp.Init(theB,TopAbs_EDGE); exp.More(); exp.Next()) {
    if (!theMap.IsBound(exp.Current())) {
      TopTools_ListOfShape thelist4;
      theMap.Bind(exp.Current(), thelist4);
      theMap(exp.Current()) = theP.Shapes(exp.Current());
    }
  }
}


//=======================================================================
//function : MajMap
//purpose  : gestion des descendants
//=======================================================================

static Handle(Geom_Curve) TestCurve(const TopoDS_Shape& Base,
				    const gp_Vec& V)
{
  gp_Pnt bar(0., 0., 0.);
  TColgp_SequenceOfPnt spt;
  LocOpe::SampleEdges(Base,spt);
  for (Standard_Integer jj=1;jj<=spt.Length(); jj++) {
    const gp_Pnt& pvt = spt(jj);
    bar.ChangeCoord() += pvt.XYZ();
  }
  bar.ChangeCoord().Divide(spt.Length());
  gp_Ax1 newAx(bar,V);
  Handle(Geom_Line) theLin = new Geom_Line(newAx);
  return theLin;
}




//=======================================================================
//function : ToFuse
//purpose  : face SameDomaine ou pas
//=======================================================================

Standard_Boolean ToFuse(const TopoDS_Face& F1,
			const TopoDS_Face& F2)
{
  if (F1.IsNull() || F2.IsNull()) {
    return Standard_False;
  }

  Handle(Geom_Surface) S1,S2;
  TopLoc_Location loc1, loc2;
  Handle(Standard_Type) typS1,typS2;
  const Standard_Real tollin = Precision::Confusion();
  const Standard_Real tolang = Precision::Angular();

  S1 = BRep_Tool::Surface(F1,loc1);
  S2 = BRep_Tool::Surface(F2,loc2);

  typS1 = S1->DynamicType();
  typS2 = S2->DynamicType();

  if (typS1 == STANDARD_TYPE(Geom_RectangularTrimmedSurface)) {
    S1 =  (*((Handle(Geom_RectangularTrimmedSurface)*)&S1))->BasisSurface();
    typS1 = S1->DynamicType();
  }

  if (typS2 == STANDARD_TYPE(Geom_RectangularTrimmedSurface)) {
    S2 =  (*((Handle(Geom_RectangularTrimmedSurface)*)&S2))->BasisSurface();
    typS2 = S2->DynamicType();
  }

  if (typS1 != typS2) {
    return Standard_False;
  }


  Standard_Boolean ValRet = Standard_False;
  if (typS1 == STANDARD_TYPE(Geom_Plane)) {
    S1 = BRep_Tool::Surface(F1);  // pour appliquer la location.
    S2 = BRep_Tool::Surface(F2);
    gp_Pln pl1( (*((Handle(Geom_Plane)*)&S1))->Pln());
    gp_Pln pl2( (*((Handle(Geom_Plane)*)&S2))->Pln());

    if (pl1.Position().IsCoplanar(pl2.Position(),tollin,tolang)) {
      ValRet = Standard_True;
    }
  }

  return ValRet;
}






