// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepOffset_Analyse_HeaderFile
#define _BRepOffset_Analyse_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _BRepOffset_DataMapOfShapeListOfInterval_HeaderFile
#include <BRepOffset_DataMapOfShapeListOfInterval.hxx>
#endif
#ifndef _TopTools_IndexedDataMapOfShapeListOfShape_HeaderFile
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _BRepOffset_Type_HeaderFile
#include <BRepOffset_Type.hxx>
#endif
class TopoDS_Shape;
class BRepOffset_ListOfInterval;
class TopoDS_Edge;
class TopoDS_Vertex;
class TopTools_ListOfShape;
class TopoDS_Face;
class TopoDS_Compound;
class TopTools_MapOfShape;


//! Analyse of a shape consit to <br>
//!          Find the part of edges convex concave tangent. <br>
class BRepOffset_Analyse  {
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

  
  Standard_EXPORT   BRepOffset_Analyse();
  
  Standard_EXPORT   BRepOffset_Analyse(const TopoDS_Shape& S,const Standard_Real Angle);
  
  Standard_EXPORT     void Perform(const TopoDS_Shape& S,const Standard_Real Angle) ;
  
  Standard_EXPORT     Standard_Boolean IsDone() const;
  
  Standard_EXPORT     void Clear() ;
  
  Standard_EXPORT    const BRepOffset_ListOfInterval& Type(const TopoDS_Edge& E) const;
  //! Stores in <L> all the edges of Type <T> <br>
//!          on the vertex <V>. <br>
  Standard_EXPORT     void Edges(const TopoDS_Vertex& V,const BRepOffset_Type T,TopTools_ListOfShape& L) const;
  //! Stores in <L> all the edges of Type <T> <br>
//!          on the face <F>. <br>
  Standard_EXPORT     void Edges(const TopoDS_Face& F,const BRepOffset_Type T,TopTools_ListOfShape& L) const;
  //! set in <Edges> all  the Edges of <Shape> which are <br>
//!          tangent to <Edge> at the vertex <Vertex>. <br>
  Standard_EXPORT     void TangentEdges(const TopoDS_Edge& Edge,const TopoDS_Vertex& Vertex,TopTools_ListOfShape& Edges) const;
  
  Standard_EXPORT     Standard_Boolean HasAncestor(const TopoDS_Shape& S) const;
  
  Standard_EXPORT    const TopTools_ListOfShape& Ancestors(const TopoDS_Shape& S) const;
  //! Explode in compounds of faces where <br>
//!          all the connex edges are of type <Side> <br>
  Standard_EXPORT     void Explode(TopTools_ListOfShape& L,const BRepOffset_Type Type) const;
  //! Explode in compounds of faces where <br>
//!          all the connex edges are of type <Side1> or <Side2> <br>
  Standard_EXPORT     void Explode(TopTools_ListOfShape& L,const BRepOffset_Type Type1,const BRepOffset_Type Type2) const;
  //! Add in <CO> the faces of the shell containing <Face> <br>
//!          where all the connex edges are of type <Side>. <br>
  Standard_EXPORT     void AddFaces(const TopoDS_Face& Face,TopoDS_Compound& Co,TopTools_MapOfShape& Map,const BRepOffset_Type Type) const;
  //! Add in <CO> the faces of the shell containing <Face> <br>
//!          where all the connex edges are of type <Side1> or <Side2>. <br>
  Standard_EXPORT     void AddFaces(const TopoDS_Face& Face,TopoDS_Compound& Co,TopTools_MapOfShape& Map,const BRepOffset_Type Type1,const BRepOffset_Type Type2) const;





protected:





private:



Standard_Boolean myDone;
TopoDS_Shape myShape;
BRepOffset_DataMapOfShapeListOfInterval mapEdgeType;
TopTools_IndexedDataMapOfShapeListOfShape ancestors;
Standard_Real angle;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
