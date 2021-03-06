// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BinMDataStd_NameDriver_HeaderFile
#define _BinMDataStd_NameDriver_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BinMDataStd_NameDriver_HeaderFile
#include <Handle_BinMDataStd_NameDriver.hxx>
#endif

#ifndef _BinMDF_ADriver_HeaderFile
#include <BinMDF_ADriver.hxx>
#endif
#ifndef _Handle_CDM_MessageDriver_HeaderFile
#include <Handle_CDM_MessageDriver.hxx>
#endif
#ifndef _Handle_TDF_Attribute_HeaderFile
#include <Handle_TDF_Attribute.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BinObjMgt_RRelocationTable_HeaderFile
#include <BinObjMgt_RRelocationTable.hxx>
#endif
#ifndef _BinObjMgt_SRelocationTable_HeaderFile
#include <BinObjMgt_SRelocationTable.hxx>
#endif
class CDM_MessageDriver;
class TDF_Attribute;
class BinObjMgt_Persistent;


//! TDataStd_Name attribute Driver. <br>
class BinMDataStd_NameDriver : public BinMDF_ADriver {

public:

  
  Standard_EXPORT   BinMDataStd_NameDriver(const Handle(CDM_MessageDriver)& theMessageDriver);
  
  Standard_EXPORT     Handle_TDF_Attribute NewEmpty() const;
  //! persistent -> transient (retrieve) <br>
  Standard_EXPORT     Standard_Boolean Paste(const BinObjMgt_Persistent& Source,const Handle(TDF_Attribute)& Target,BinObjMgt_RRelocationTable& RelocTable) const;
  //! transient -> persistent (store) <br>
  Standard_EXPORT     void Paste(const Handle(TDF_Attribute)& Source,BinObjMgt_Persistent& Target,BinObjMgt_SRelocationTable& RelocTable) const;




  DEFINE_STANDARD_RTTI(BinMDataStd_NameDriver)

protected:




private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
