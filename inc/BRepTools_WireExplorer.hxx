// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepTools_WireExplorer_HeaderFile
#define _BRepTools_WireExplorer_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopTools_DataMapOfShapeListOfShape_HeaderFile
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#endif
#ifndef _TopoDS_Edge_HeaderFile
#include <TopoDS_Edge.hxx>
#endif
#ifndef _TopoDS_Vertex_HeaderFile
#include <TopoDS_Vertex.hxx>
#endif
#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _TopTools_MapOfShape_HeaderFile
#include <TopTools_MapOfShape.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _TopAbs_Orientation_HeaderFile
#include <TopAbs_Orientation.hxx>
#endif
class Standard_DomainError;
class Standard_NoSuchObject;
class Standard_NoMoreObject;
class TopoDS_Wire;
class TopoDS_Face;
class TopoDS_Edge;
class TopoDS_Vertex;


//! The WireExplorer is a tool to explore the edges of <br>
//!          a wire in a connection order. <br>
//! <br>
//!          i.e. each edge is connected to the previous one by <br>
//!          its origin. <br>
//!      If a wire is not closed returns only a segment of edges which <br>
//! length depends on started in exploration edge. If wire has <br>
//! singularities (for example, loops) WireExplorer can return not all <br>
//! edges in a wire. it depends on type of singularity. <br>
class BRepTools_WireExplorer  {
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

  //! Constructs an empty explorer (which can be initialized using Init) <br>
  Standard_EXPORT   BRepTools_WireExplorer();
  //! Initializes an exploration  of the wire <W> face F is used to <br>
//!   involve 2D analysis while exploration). <br>
  Standard_EXPORT   BRepTools_WireExplorer(const TopoDS_Wire& W);
  //! Initializes an exploration  of the wire <W>. <br>
//!          F is used to select the edge connected to the <br>
//!          previous in the parametric representation of <F>. <br>
  Standard_EXPORT   BRepTools_WireExplorer(const TopoDS_Wire& W,const TopoDS_Face& F);
  //! Initializes an exploration of the wire <W>. <br>
  Standard_EXPORT     void Init(const TopoDS_Wire& W) ;
  //! Initializes an exploration of the wire <W>. <br>
//!          F is used to select the edge connected to the <br>
//!          previous in the parametric representation of <F>. <br>
//! <br>
  Standard_EXPORT     void Init(const TopoDS_Wire& W,const TopoDS_Face& F) ;
  //! Returns True if there  is a current  edge. <br>
  Standard_EXPORT     Standard_Boolean More() const;
  //! Proceeds to the next edge. <br>
  Standard_EXPORT     void Next() ;
  //! Returns the current edge. <br>
  Standard_EXPORT    const TopoDS_Edge& Current() const;
  //! Returns an Orientation for the current edge. <br>
  Standard_EXPORT     TopAbs_Orientation Orientation() const;
  //! Returns the vertex connecting the current  edge to <br>
//!          the previous one. <br>
  Standard_EXPORT    const TopoDS_Vertex& CurrentVertex() const;
  //! Clears the content of the explorer. <br>
  Standard_EXPORT     void Clear() ;





protected:





private:



TopTools_DataMapOfShapeListOfShape myMap;
TopoDS_Edge myEdge;
TopoDS_Vertex myVertex;
TopoDS_Face myFace;
TopTools_MapOfShape myDoubles;
Standard_Boolean myReverse;
Standard_Real myTolU;
Standard_Real myTolV;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
