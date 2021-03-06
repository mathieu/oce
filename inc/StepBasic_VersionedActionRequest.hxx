// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_VersionedActionRequest_HeaderFile
#define _StepBasic_VersionedActionRequest_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepBasic_VersionedActionRequest_HeaderFile
#include <Handle_StepBasic_VersionedActionRequest.hxx>
#endif

#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
class TCollection_HAsciiString;


//! Representation of STEP entity VersionedActionRequest <br>
class StepBasic_VersionedActionRequest : public MMgt_TShared {

public:

  //! Empty constructor <br>
  Standard_EXPORT   StepBasic_VersionedActionRequest();
  //! Initialize all fields (own and inherited) <br>
  Standard_EXPORT     void Init(const Handle(TCollection_HAsciiString)& aId,const Handle(TCollection_HAsciiString)& aVersion,const Handle(TCollection_HAsciiString)& aPurpose,const Standard_Boolean hasDescription,const Handle(TCollection_HAsciiString)& aDescription) ;
  //! Returns field Id <br>
  Standard_EXPORT     Handle_TCollection_HAsciiString Id() const;
  //! Set field Id <br>
  Standard_EXPORT     void SetId(const Handle(TCollection_HAsciiString)& Id) ;
  //! Returns field Version <br>
  Standard_EXPORT     Handle_TCollection_HAsciiString Version() const;
  //! Set field Version <br>
  Standard_EXPORT     void SetVersion(const Handle(TCollection_HAsciiString)& Version) ;
  //! Returns field Purpose <br>
  Standard_EXPORT     Handle_TCollection_HAsciiString Purpose() const;
  //! Set field Purpose <br>
  Standard_EXPORT     void SetPurpose(const Handle(TCollection_HAsciiString)& Purpose) ;
  //! Returns field Description <br>
  Standard_EXPORT     Handle_TCollection_HAsciiString Description() const;
  //! Set field Description <br>
  Standard_EXPORT     void SetDescription(const Handle(TCollection_HAsciiString)& Description) ;
  //! Returns True if optional field Description is defined <br>
  Standard_EXPORT     Standard_Boolean HasDescription() const;




  DEFINE_STANDARD_RTTI(StepBasic_VersionedActionRequest)

protected:




private: 


Handle_TCollection_HAsciiString theId;
Handle_TCollection_HAsciiString theVersion;
Handle_TCollection_HAsciiString thePurpose;
Handle_TCollection_HAsciiString theDescription;
Standard_Boolean defDescription;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
