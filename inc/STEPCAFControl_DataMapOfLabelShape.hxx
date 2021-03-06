// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _STEPCAFControl_DataMapOfLabelShape_HeaderFile
#define _STEPCAFControl_DataMapOfLabelShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMap_HeaderFile
#include <TCollection_BasicMap.hxx>
#endif
#ifndef _Handle_STEPCAFControl_DataMapNodeOfDataMapOfLabelShape_HeaderFile
#include <Handle_STEPCAFControl_DataMapNodeOfDataMapOfLabelShape.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_DomainError;
class Standard_NoSuchObject;
class TDF_Label;
class TopoDS_Shape;
class TDF_LabelMapHasher;
class STEPCAFControl_DataMapNodeOfDataMapOfLabelShape;
class STEPCAFControl_DataMapIteratorOfDataMapOfLabelShape;



class STEPCAFControl_DataMapOfLabelShape  : public TCollection_BasicMap {
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

  
  Standard_EXPORT   STEPCAFControl_DataMapOfLabelShape(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT     STEPCAFControl_DataMapOfLabelShape& Assign(const STEPCAFControl_DataMapOfLabelShape& Other) ;
    STEPCAFControl_DataMapOfLabelShape& operator =(const STEPCAFControl_DataMapOfLabelShape& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void ReSize(const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT     void Clear() ;
~STEPCAFControl_DataMapOfLabelShape()
{
  Clear();
}
  
  Standard_EXPORT     Standard_Boolean Bind(const TDF_Label& K,const TopoDS_Shape& I) ;
  
  Standard_EXPORT     Standard_Boolean IsBound(const TDF_Label& K) const;
  
  Standard_EXPORT     Standard_Boolean UnBind(const TDF_Label& K) ;
  
  Standard_EXPORT    const TopoDS_Shape& Find(const TDF_Label& K) const;
   const TopoDS_Shape& operator()(const TDF_Label& K) const
{
  return Find(K);
}
  
  Standard_EXPORT     TopoDS_Shape& ChangeFind(const TDF_Label& K) ;
    TopoDS_Shape& operator()(const TDF_Label& K) 
{
  return ChangeFind(K);
}





protected:





private:

  
  Standard_EXPORT   STEPCAFControl_DataMapOfLabelShape(const STEPCAFControl_DataMapOfLabelShape& Other);




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
