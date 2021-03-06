// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State_HeaderFile
#define _TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMap_HeaderFile
#include <TCollection_BasicMap.hxx>
#endif
#ifndef _Handle_TopOpeBRepDS_DataMapNodeOfDataMapOfShapeListOfShapeOn1State_HeaderFile
#include <Handle_TopOpeBRepDS_DataMapNodeOfDataMapOfShapeListOfShapeOn1State.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_DomainError;
class Standard_NoSuchObject;
class TopoDS_Shape;
class TopOpeBRepDS_ListOfShapeOn1State;
class TopTools_ShapeMapHasher;
class TopOpeBRepDS_DataMapNodeOfDataMapOfShapeListOfShapeOn1State;
class TopOpeBRepDS_DataMapIteratorOfDataMapOfShapeListOfShapeOn1State;



class TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State  : public TCollection_BasicMap {
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

  
  Standard_EXPORT   TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT     TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State& Assign(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State& Other) ;
    TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State& operator =(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void ReSize(const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT     void Clear() ;
~TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State()
{
  Clear();
}
  
  Standard_EXPORT     Standard_Boolean Bind(const TopoDS_Shape& K,const TopOpeBRepDS_ListOfShapeOn1State& I) ;
  
  Standard_EXPORT     Standard_Boolean IsBound(const TopoDS_Shape& K) const;
  
  Standard_EXPORT     Standard_Boolean UnBind(const TopoDS_Shape& K) ;
  
  Standard_EXPORT    const TopOpeBRepDS_ListOfShapeOn1State& Find(const TopoDS_Shape& K) const;
   const TopOpeBRepDS_ListOfShapeOn1State& operator()(const TopoDS_Shape& K) const
{
  return Find(K);
}
  
  Standard_EXPORT     TopOpeBRepDS_ListOfShapeOn1State& ChangeFind(const TopoDS_Shape& K) ;
    TopOpeBRepDS_ListOfShapeOn1State& operator()(const TopoDS_Shape& K) 
{
  return ChangeFind(K);
}





protected:





private:

  
  Standard_EXPORT   TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State& Other);




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
