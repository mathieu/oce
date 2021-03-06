// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepFEA_ElementGroup_HeaderFile
#define _StepFEA_ElementGroup_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepFEA_ElementGroup_HeaderFile
#include <Handle_StepFEA_ElementGroup.hxx>
#endif

#ifndef _Handle_StepFEA_HArray1OfElementRepresentation_HeaderFile
#include <Handle_StepFEA_HArray1OfElementRepresentation.hxx>
#endif
#ifndef _StepFEA_FeaGroup_HeaderFile
#include <StepFEA_FeaGroup.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Handle_StepFEA_FeaModel_HeaderFile
#include <Handle_StepFEA_FeaModel.hxx>
#endif
class StepFEA_HArray1OfElementRepresentation;
class TCollection_HAsciiString;
class StepFEA_FeaModel;


//! Representation of STEP entity ElementGroup <br>
class StepFEA_ElementGroup : public StepFEA_FeaGroup {

public:

  //! Empty constructor <br>
  Standard_EXPORT   StepFEA_ElementGroup();
  //! Initialize all fields (own and inherited) <br>
  Standard_EXPORT     void Init(const Handle(TCollection_HAsciiString)& aGroup_Name,const Handle(TCollection_HAsciiString)& aGroup_Description,const Handle(StepFEA_FeaModel)& aFeaGroup_ModelRef,const Handle(StepFEA_HArray1OfElementRepresentation)& aElements) ;
  //! Returns field Elements <br>
  Standard_EXPORT     Handle_StepFEA_HArray1OfElementRepresentation Elements() const;
  //! Set field Elements <br>
  Standard_EXPORT     void SetElements(const Handle(StepFEA_HArray1OfElementRepresentation)& Elements) ;




  DEFINE_STANDARD_RTTI(StepFEA_ElementGroup)

protected:




private: 


Handle_StepFEA_HArray1OfElementRepresentation theElements;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
