// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepAP214_HArray1OfDateItem_HeaderFile
#define _StepAP214_HArray1OfDateItem_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepAP214_HArray1OfDateItem_HeaderFile
#include <Handle_StepAP214_HArray1OfDateItem.hxx>
#endif

#ifndef _StepAP214_Array1OfDateItem_HeaderFile
#include <StepAP214_Array1OfDateItem.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class StepAP214_DateItem;
class StepAP214_Array1OfDateItem;



class StepAP214_HArray1OfDateItem : public MMgt_TShared {

public:

  
  Standard_EXPORT   StepAP214_HArray1OfDateItem(const Standard_Integer Low,const Standard_Integer Up);
  
  Standard_EXPORT   StepAP214_HArray1OfDateItem(const Standard_Integer Low,const Standard_Integer Up,const StepAP214_DateItem& V);
  
  Standard_EXPORT     void Init(const StepAP214_DateItem& V) ;
  
        Standard_Integer Length() const;
  
        Standard_Integer Lower() const;
  
        Standard_Integer Upper() const;
  
        void SetValue(const Standard_Integer Index,const StepAP214_DateItem& Value) ;
  
       const StepAP214_DateItem& Value(const Standard_Integer Index) const;
  
        StepAP214_DateItem& ChangeValue(const Standard_Integer Index) ;
  
       const StepAP214_Array1OfDateItem& Array1() const;
  
        StepAP214_Array1OfDateItem& ChangeArray1() ;




  DEFINE_STANDARD_RTTI(StepAP214_HArray1OfDateItem)

protected:




private: 


StepAP214_Array1OfDateItem myArray;


};

#define ItemHArray1 StepAP214_DateItem
#define ItemHArray1_hxx <StepAP214_DateItem.hxx>
#define TheArray1 StepAP214_Array1OfDateItem
#define TheArray1_hxx <StepAP214_Array1OfDateItem.hxx>
#define TCollection_HArray1 StepAP214_HArray1OfDateItem
#define TCollection_HArray1_hxx <StepAP214_HArray1OfDateItem.hxx>
#define Handle_TCollection_HArray1 Handle_StepAP214_HArray1OfDateItem
#define TCollection_HArray1_Type_() StepAP214_HArray1OfDateItem_Type_()

#include <TCollection_HArray1.lxx>

#undef ItemHArray1
#undef ItemHArray1_hxx
#undef TheArray1
#undef TheArray1_hxx
#undef TCollection_HArray1
#undef TCollection_HArray1_hxx
#undef Handle_TCollection_HArray1
#undef TCollection_HArray1_Type_


// other Inline functions and methods (like "C++: function call" methods)


#endif
