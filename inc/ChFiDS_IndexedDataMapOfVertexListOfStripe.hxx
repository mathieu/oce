// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ChFiDS_IndexedDataMapOfVertexListOfStripe_HeaderFile
#define _ChFiDS_IndexedDataMapOfVertexListOfStripe_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMap_HeaderFile
#include <TCollection_BasicMap.hxx>
#endif
#ifndef _Handle_ChFiDS_IndexedDataMapNodeOfIndexedDataMapOfVertexListOfStripe_HeaderFile
#include <Handle_ChFiDS_IndexedDataMapNodeOfIndexedDataMapOfVertexListOfStripe.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_DomainError;
class Standard_OutOfRange;
class Standard_NoSuchObject;
class TopoDS_Vertex;
class ChFiDS_ListOfStripe;
class TopTools_ShapeMapHasher;
class ChFiDS_IndexedDataMapNodeOfIndexedDataMapOfVertexListOfStripe;



class ChFiDS_IndexedDataMapOfVertexListOfStripe  : public TCollection_BasicMap {
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

  
  Standard_EXPORT   ChFiDS_IndexedDataMapOfVertexListOfStripe(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT     ChFiDS_IndexedDataMapOfVertexListOfStripe& Assign(const ChFiDS_IndexedDataMapOfVertexListOfStripe& Other) ;
    ChFiDS_IndexedDataMapOfVertexListOfStripe& operator =(const ChFiDS_IndexedDataMapOfVertexListOfStripe& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void ReSize(const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT     void Clear() ;
~ChFiDS_IndexedDataMapOfVertexListOfStripe()
{
  Clear();
}
  
  Standard_EXPORT     Standard_Integer Add(const TopoDS_Vertex& K,const ChFiDS_ListOfStripe& I) ;
  
  Standard_EXPORT     void Substitute(const Standard_Integer I,const TopoDS_Vertex& K,const ChFiDS_ListOfStripe& T) ;
  
  Standard_EXPORT     void RemoveLast() ;
  
  Standard_EXPORT     Standard_Boolean Contains(const TopoDS_Vertex& K) const;
  
  Standard_EXPORT    const TopoDS_Vertex& FindKey(const Standard_Integer I) const;
  
  Standard_EXPORT    const ChFiDS_ListOfStripe& FindFromIndex(const Standard_Integer I) const;
   const ChFiDS_ListOfStripe& operator ()(const Standard_Integer I) const
{
  return FindFromIndex(I);
}
  
  Standard_EXPORT     ChFiDS_ListOfStripe& ChangeFromIndex(const Standard_Integer I) ;
    ChFiDS_ListOfStripe& operator ()(const Standard_Integer I) 
{
  return ChangeFromIndex(I);
}
  
  Standard_EXPORT     Standard_Integer FindIndex(const TopoDS_Vertex& K) const;
  
  Standard_EXPORT    const ChFiDS_ListOfStripe& FindFromKey(const TopoDS_Vertex& K) const;
  
  Standard_EXPORT     ChFiDS_ListOfStripe& ChangeFromKey(const TopoDS_Vertex& K) ;





protected:





private:

  
  Standard_EXPORT   ChFiDS_IndexedDataMapOfVertexListOfStripe(const ChFiDS_IndexedDataMapOfVertexListOfStripe& Other);




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
