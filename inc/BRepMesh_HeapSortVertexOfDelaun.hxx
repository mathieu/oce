// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepMesh_HeapSortVertexOfDelaun_HeaderFile
#define _BRepMesh_HeapSortVertexOfDelaun_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

class BRepMesh_Vertex;
class BRepMesh_Array1OfVertexOfDelaun;
class BRepMesh_ComparatorOfVertexOfDelaun;



class BRepMesh_HeapSortVertexOfDelaun  {
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

  
  Standard_EXPORT   static  void Sort(BRepMesh_Array1OfVertexOfDelaun& TheArray,const BRepMesh_ComparatorOfVertexOfDelaun& Comp) ;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
