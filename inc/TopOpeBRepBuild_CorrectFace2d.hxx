// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopOpeBRepBuild_CorrectFace2d_HeaderFile
#define _TopOpeBRepBuild_CorrectFace2d_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _TopoDS_Wire_HeaderFile
#include <TopoDS_Wire.hxx>
#endif
#ifndef _TopTools_ListOfShape_HeaderFile
#include <TopTools_ListOfShape.hxx>
#endif
#ifndef _TopTools_IndexedMapOfOrientedShape_HeaderFile
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#endif
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _TopTools_IndexedDataMapOfShapeShape_HeaderFile
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#endif
#ifndef _Handle_Geom2d_Curve_HeaderFile
#include <Handle_Geom2d_Curve.hxx>
#endif
class TopoDS_Face;
class TopTools_IndexedMapOfOrientedShape;
class TopTools_IndexedDataMapOfShapeShape;
class TopoDS_Edge;
class gp_Pnt2d;
class TopoDS_Shape;
class TopTools_ListOfShape;
class gp_Vec2d;
class Geom2d_Curve;
class TopoDS_Wire;
class Bnd_Box2d;



class TopOpeBRepBuild_CorrectFace2d  {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  
  Standard_EXPORT   TopOpeBRepBuild_CorrectFace2d();
  
  Standard_EXPORT   TopOpeBRepBuild_CorrectFace2d(const TopoDS_Face& aFace,const TopTools_IndexedMapOfOrientedShape& anAvoidMap,TopTools_IndexedDataMapOfShapeShape& aMap);
  
  Standard_EXPORT    const TopoDS_Face& Face() const;
  
  Standard_EXPORT     void Perform() ;
  
  Standard_EXPORT     Standard_Boolean IsDone() const;
  
  Standard_EXPORT     Standard_Integer ErrorStatus() const;
  
  Standard_EXPORT    const TopoDS_Face& CorrectedFace() const;
  
  Standard_EXPORT     void SetMapOfTrans2dInfo(TopTools_IndexedDataMapOfShapeShape& aMap) ;
  
  Standard_EXPORT     TopTools_IndexedDataMapOfShapeShape& MapOfTrans2dInfo() ;
  
  Standard_EXPORT   static  void GetP2dFL(const TopoDS_Face& aFace,const TopoDS_Edge& anEdge,gp_Pnt2d& P2dF,gp_Pnt2d& P2dL) ;
  
  Standard_EXPORT   static  void CheckList(const TopoDS_Face& aFace,TopTools_ListOfShape& aHeadList) ;





protected:





private:

  
  Standard_EXPORT     void CheckFace() ;
  
  Standard_EXPORT     Standard_Integer MakeRightWire() ;
  
  Standard_EXPORT     void MakeHeadList(const TopoDS_Shape& aFirstEdge,TopTools_ListOfShape& aHeadList) const;
  
  Standard_EXPORT     void TranslateCurve2d(const TopoDS_Edge& anEdge,const TopoDS_Face& aFace,const gp_Vec2d& aTranslateVec,Handle(Geom2d_Curve)& aCurve2d) ;
  
  Standard_EXPORT     Standard_Integer OuterWire(TopoDS_Wire& anOuterWire) const;
  
  Standard_EXPORT     void BndBoxWire(const TopoDS_Wire& aWire,Bnd_Box2d& aB2d) const;
  
  Standard_EXPORT     void MoveWire2d(TopoDS_Wire& aWire,const gp_Vec2d& aTrV) ;
  
  Standard_EXPORT     void MoveWires2d(TopoDS_Wire& aWire) ;
  
  Standard_EXPORT     void UpdateEdge(const TopoDS_Edge& E,const Handle(Geom2d_Curve)& C,const TopoDS_Face& F,const Standard_Real Tol) ;
  
  Standard_EXPORT     void UpdateEdge(const TopoDS_Edge& E,const Handle(Geom2d_Curve)& C1,const Handle(Geom2d_Curve)& C2,const TopoDS_Face& F,const Standard_Real Tol) ;
  
  Standard_EXPORT     void BuildCopyData(const TopoDS_Face& F,const TopTools_IndexedMapOfOrientedShape& anAvoidMap,TopoDS_Face& aCopyFace,TopTools_IndexedMapOfOrientedShape& aCopyAvoidMap,const Standard_Boolean aNeedToUsePMap) ;
  
  Standard_EXPORT     Standard_Integer ConnectWire(TopoDS_Face& aCopyFace,const TopTools_IndexedMapOfOrientedShape& aCopyAvoidMap,const Standard_Boolean aTryToConnectFlag) ;


TopoDS_Face myFace;
TopoDS_Face myCorrectedFace;
Standard_Boolean myIsDone;
Standard_Integer myErrorStatus;
Standard_Real myFaceTolerance;
TopoDS_Wire myCurrentWire;
TopTools_ListOfShape myOrderedWireList;
TopTools_IndexedMapOfOrientedShape myAvoidMap;
Standard_Address myMap;
TopoDS_Face myCopyFace;
TopTools_IndexedMapOfOrientedShape myCopyAvoidMap;
TopTools_IndexedDataMapOfShapeShape myEdMapInversed;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
