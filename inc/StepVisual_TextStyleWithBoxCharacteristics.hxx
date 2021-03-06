// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepVisual_TextStyleWithBoxCharacteristics_HeaderFile
#define _StepVisual_TextStyleWithBoxCharacteristics_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepVisual_TextStyleWithBoxCharacteristics_HeaderFile
#include <Handle_StepVisual_TextStyleWithBoxCharacteristics.hxx>
#endif

#ifndef _Handle_StepVisual_HArray1OfBoxCharacteristicSelect_HeaderFile
#include <Handle_StepVisual_HArray1OfBoxCharacteristicSelect.hxx>
#endif
#ifndef _StepVisual_TextStyle_HeaderFile
#include <StepVisual_TextStyle.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Handle_StepVisual_TextStyleForDefinedFont_HeaderFile
#include <Handle_StepVisual_TextStyleForDefinedFont.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class StepVisual_HArray1OfBoxCharacteristicSelect;
class TCollection_HAsciiString;
class StepVisual_TextStyleForDefinedFont;
class StepVisual_BoxCharacteristicSelect;



class StepVisual_TextStyleWithBoxCharacteristics : public StepVisual_TextStyle {

public:

  //! Returns a TextStyleWithBoxCharacteristics <br>
  Standard_EXPORT   StepVisual_TextStyleWithBoxCharacteristics();
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Handle(StepVisual_TextStyleForDefinedFont)& aCharacterAppearance) ;
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Handle(StepVisual_TextStyleForDefinedFont)& aCharacterAppearance,const Handle(StepVisual_HArray1OfBoxCharacteristicSelect)& aCharacteristics) ;
  
  Standard_EXPORT     void SetCharacteristics(const Handle(StepVisual_HArray1OfBoxCharacteristicSelect)& aCharacteristics) ;
  
  Standard_EXPORT     Handle_StepVisual_HArray1OfBoxCharacteristicSelect Characteristics() const;
  
  Standard_EXPORT     StepVisual_BoxCharacteristicSelect CharacteristicsValue(const Standard_Integer num) const;
  
  Standard_EXPORT     Standard_Integer NbCharacteristics() const;




  DEFINE_STANDARD_RTTI(StepVisual_TextStyleWithBoxCharacteristics)

protected:




private: 


Handle_StepVisual_HArray1OfBoxCharacteristicSelect characteristics;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
