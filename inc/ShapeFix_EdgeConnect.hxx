// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeFix_EdgeConnect_HeaderFile
#define _ShapeFix_EdgeConnect_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopTools_DataMapOfShapeShape_HeaderFile
#include <TopTools_DataMapOfShapeShape.hxx>
#endif
#ifndef _TopTools_DataMapOfShapeListOfShape_HeaderFile
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#endif
class TopoDS_Edge;
class TopoDS_Shape;


//! Makes vertices to be shared to connect edges, <br>
//!           updates positions and tolerances for shared vertices. <br>
//!           Accepts edges bounded by two vertices each. <br>
class ShapeFix_EdgeConnect  {
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

  
  Standard_EXPORT   ShapeFix_EdgeConnect();
  //! Adds information on connectivity between start vertex <br>
//!           of second edge and end vertex of first edge, <br>
//!           taking edges orientation into account <br>
  Standard_EXPORT     void Add(const TopoDS_Edge& aFirst,const TopoDS_Edge& aSecond) ;
  //! Adds connectivity information for the whole shape. <br>
//!           Note: edges in wires must be well ordered <br>
//!           Note: flag Closed should be set for closed wires <br>
  Standard_EXPORT     void Add(const TopoDS_Shape& aShape) ;
  //! Builds shared vertices, updates their positions and tolerances <br>
  Standard_EXPORT     void Build() ;
  //! Clears internal data structure <br>
  Standard_EXPORT     void Clear() ;





protected:





private:



TopTools_DataMapOfShapeShape myVertices;
TopTools_DataMapOfShapeListOfShape myLists;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
