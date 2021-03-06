// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepRepr_RepresentationContext_HeaderFile
#define _StepRepr_RepresentationContext_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepRepr_RepresentationContext_HeaderFile
#include <Handle_StepRepr_RepresentationContext.hxx>
#endif

#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
class TCollection_HAsciiString;



class StepRepr_RepresentationContext : public MMgt_TShared {

public:

  //! Returns a RepresentationContext <br>
  Standard_EXPORT   StepRepr_RepresentationContext();
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aContextIdentifier,const Handle(TCollection_HAsciiString)& aContextType) ;
  
  Standard_EXPORT     void SetContextIdentifier(const Handle(TCollection_HAsciiString)& aContextIdentifier) ;
  
  Standard_EXPORT     Handle_TCollection_HAsciiString ContextIdentifier() const;
  
  Standard_EXPORT     void SetContextType(const Handle(TCollection_HAsciiString)& aContextType) ;
  
  Standard_EXPORT     Handle_TCollection_HAsciiString ContextType() const;




  DEFINE_STANDARD_RTTI(StepRepr_RepresentationContext)

protected:




private: 


Handle_TCollection_HAsciiString contextIdentifier;
Handle_TCollection_HAsciiString contextType;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
