// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Interface_DataMapOfTransientInteger_HeaderFile
#define _Interface_DataMapOfTransientInteger_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMap_HeaderFile
#include <TCollection_BasicMap.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Interface_DataMapNodeOfDataMapOfTransientInteger_HeaderFile
#include <Handle_Interface_DataMapNodeOfDataMapOfTransientInteger.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_DomainError;
class Standard_NoSuchObject;
class Standard_Transient;
class TColStd_MapTransientHasher;
class Interface_DataMapNodeOfDataMapOfTransientInteger;
class Interface_DataMapIteratorOfDataMapOfTransientInteger;



class Interface_DataMapOfTransientInteger  : public TCollection_BasicMap {
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

  
  Standard_EXPORT   Interface_DataMapOfTransientInteger(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT     Interface_DataMapOfTransientInteger& Assign(const Interface_DataMapOfTransientInteger& Other) ;
    Interface_DataMapOfTransientInteger& operator =(const Interface_DataMapOfTransientInteger& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void ReSize(const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT     void Clear() ;
~Interface_DataMapOfTransientInteger()
{
  Clear();
}
  
  Standard_EXPORT     Standard_Boolean Bind(const Handle(Standard_Transient)& K,const Standard_Integer& I) ;
  
  Standard_EXPORT     Standard_Boolean IsBound(const Handle(Standard_Transient)& K) const;
  
  Standard_EXPORT     Standard_Boolean UnBind(const Handle(Standard_Transient)& K) ;
  
  Standard_EXPORT    const Standard_Integer& Find(const Handle(Standard_Transient)& K) const;
   const Standard_Integer& operator()(const Handle(Standard_Transient)& K) const
{
  return Find(K);
}
  
  Standard_EXPORT     Standard_Integer& ChangeFind(const Handle(Standard_Transient)& K) ;
    Standard_Integer& operator()(const Handle(Standard_Transient)& K) 
{
  return ChangeFind(K);
}





protected:





private:

  
  Standard_EXPORT   Interface_DataMapOfTransientInteger(const Interface_DataMapOfTransientInteger& Other);




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
