// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IFSelect_WorkLibrary_HeaderFile
#define _IFSelect_WorkLibrary_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IFSelect_WorkLibrary_HeaderFile
#include <Handle_IFSelect_WorkLibrary.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Interface_HArray1OfHAsciiString_HeaderFile
#include <Handle_Interface_HArray1OfHAsciiString.hxx>
#endif
#ifndef _Standard_Transient_HeaderFile
#include <Standard_Transient.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Handle_Interface_InterfaceModel_HeaderFile
#include <Handle_Interface_InterfaceModel.hxx>
#endif
#ifndef _Handle_Interface_Protocol_HeaderFile
#include <Handle_Interface_Protocol.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Handle_Message_Messenger_HeaderFile
#include <Handle_Message_Messenger.hxx>
#endif
class Interface_HArray1OfHAsciiString;
class Interface_InterfaceModel;
class Interface_Protocol;
class IFSelect_ContextWrite;
class Interface_EntityIterator;
class Interface_CopyTool;
class Standard_Transient;
class Message_Messenger;


//! This class defines the (empty) frame which can be used to <br>
//!           enrich a XSTEP set with new capabilities <br>
//!           In particular, a specific WorkLibrary must give the way for <br>
//!           Reading a File into a Model, and Writing a Model to a File <br>
//!           Thus, it is possible to define several Work Libraries for each <br>
//!           norm, but recommanded to define one general class for each one : <br>
//!           this general class will define the Read and Write methods. <br>
//! <br>
//!           Also a Dump service is provided, it can produce, according the <br>
//!           norm, either a parcel of a file for an entity, or any other <br>
//!           kind of informations relevant for the norm, <br>
class IFSelect_WorkLibrary : public Standard_Transient {

public:

  //! Gives the way to Read a File and transfer it to a Model <br>
//!           <mod> is the resulting Model, which has to be created by this <br>
//!           method. In case of error, <mod> must be returned Null <br>
//!           Return value is a status with free values. <br>
//!           Simply, 0 is for "Execution OK" <br>
//!           The Protocol can be used to work (e.g. create the Model, read <br>
//!           and recognize the Entities) <br>
  Standard_EXPORT   virtual  Standard_Integer ReadFile(const Standard_CString name,Handle(Interface_InterfaceModel)& model,const Handle(Interface_Protocol)& protocol) const = 0;
  //! Gives the way to Write a File from a Model. <br>
//!           <ctx> contains all necessary informations : the model, the <br>
//!           protocol, the file name, and the list of File Modifiers to be <br>
//!           applied, also with restricted list of selected entities for <br>
//!           each one, if required. <br>
//!           In return, it brings the produced check-list <br>
//! <br>
//!           The WorkLibrary has to query <applied> to get then run the <br>
//!           ContextWrite by looping like this (example) : <br>
//!             for (numap = 1; numap <= ctx.NbModifiers(); numap ++) { <br>
//!               ctx.SetModifier (numap); <br>
//!               cast ctx.FileModifier()  to specific type -> variable filemod <br>
//!               if (!filemod.IsNull()) filemod->Perform (ctx,writer); <br>
//!                 filemod then works with ctx. It can, either act on the <br>
//!                 model itself (for instance on its header), or iterate <br>
//!                 on selected entities (Start/Next/More/Value) <br>
//!                 it can call AddFail or AddWarning, as necessary <br>
//!             } <br>
  Standard_EXPORT   virtual  Standard_Boolean WriteFile(IFSelect_ContextWrite& ctx) const = 0;
  //! Performs the copy of entities from an original model to a new <br>
//!           one. It must also copy headers if any. Returns True when done. <br>
//!           The provided default works by copying the individual entities <br>
//!           designated in the list, by using the general service class <br>
//!           CopyTool. <br>
//!           It can be redefined for a norm which, either implements Copy <br>
//!           by another way (do not forget to Bind each copied result with <br>
//!           its original entity in TC) and returns True, or does not know <br>
//!           how to copy and returns False <br>
  Standard_EXPORT   virtual  Standard_Boolean CopyModel(const Handle(Interface_InterfaceModel)& original,const Handle(Interface_InterfaceModel)& newmodel,const Interface_EntityIterator& list,Interface_CopyTool& TC) const;
  //! Gives the way of dumping an entity under a form comprehensive <br>
//!           for each norm. <model> helps to identify, number ... entities. <br>
//!           <level> is to be interpreted for each norm (because of the <br>
//!           formats which can be very different) <br>
  Standard_EXPORT   virtual  void DumpEntity(const Handle(Interface_InterfaceModel)& model,const Handle(Interface_Protocol)& protocol,const Handle(Standard_Transient)& entity,const Handle(Message_Messenger)& S,const Standard_Integer level) const = 0;
  //! Calls deferred DumpEntity with the recorded default level <br>
  Standard_EXPORT     void DumpEntity(const Handle(Interface_InterfaceModel)& model,const Handle(Interface_Protocol)& protocol,const Handle(Standard_Transient)& entity,const Handle(Message_Messenger)& S) const;
  //! Records a default level and a maximum value for level <br>
//!           level for DumpEntity can go between 0 and <max> <br>
//!           default value will be <def> <br>
  Standard_EXPORT     void SetDumpLevels(const Standard_Integer def,const Standard_Integer max) ;
  //! Returns the recorded default and maximum dump levels <br>
//!           If none was recorded, max is returned negative, def as zero <br>
  Standard_EXPORT     void DumpLevels(Standard_Integer& def,Standard_Integer& max) const;
  //! Records a short line of help for a level (0 - max) <br>
  Standard_EXPORT     void SetDumpHelp(const Standard_Integer level,const Standard_CString help) ;
  //! Returns the help line recorded for <level>, or an empty string <br>
  Standard_EXPORT     Standard_CString DumpHelp(const Standard_Integer level) const;




  DEFINE_STANDARD_RTTI(IFSelect_WorkLibrary)

protected:

  //! Required to initialise fields <br>
  Standard_EXPORT   IFSelect_WorkLibrary();



private: 


Standard_Integer thelevdef;
Handle_Interface_HArray1OfHAsciiString thelevhlp;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
