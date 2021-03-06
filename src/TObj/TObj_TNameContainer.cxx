// File:        TObj_TNameContainer.cxx
// Created:     Tue Nov 23 12:51:24 2004
// Author:      Pavel TELKOV
// Copyright:   Open CASCADE  2007
// The original implementation Copyright: (C) RINA S.p.A

#include <TObj_TNameContainer.hxx>
#include <Standard_GUID.hxx>

IMPLEMENT_STANDARD_HANDLE(TObj_TNameContainer,TDF_Attribute)
IMPLEMENT_STANDARD_RTTIEXT(TObj_TNameContainer,TDF_Attribute)

//=======================================================================
//function : TObj_TNameContainer
//purpose  : 
//=======================================================================

TObj_TNameContainer::TObj_TNameContainer()
{
}

//=======================================================================
//function : GetID
//purpose  : 
//=======================================================================

const Standard_GUID& TObj_TNameContainer::GetID()
{
  static Standard_GUID theID ("3bbefb47-e618-11d4-ba38-0060b0ee18ea");
  return theID;
}
  
//=======================================================================
//function : ID
//purpose  : 
//=======================================================================

const Standard_GUID& TObj_TNameContainer::ID() const
{
  return GetID();
}

//=======================================================================
//function : Set
//purpose  : 
//=======================================================================

Handle(TObj_TNameContainer) TObj_TNameContainer::Set(const TDF_Label& theLabel)
{
  Handle(TObj_TNameContainer) A;
  if (!theLabel.FindAttribute(TObj_TNameContainer::GetID(), A)) 
  {
    A = new TObj_TNameContainer;
    theLabel.AddAttribute(A);
  }
  return A;
}

//=======================================================================
//function : RecordName
//purpose  : 
//=======================================================================

void TObj_TNameContainer::RecordName(const Handle(TCollection_HExtendedString)& theName,
                                         const TDF_Label& theLabel)
{
  if(!IsRegistered(theName)) 
  {
    Backup();
    myMap.Bind(new TCollection_HExtendedString(theName->String()),theLabel);
  }
}

//=======================================================================
//function : RemoveName
//purpose  : 
//=======================================================================

void TObj_TNameContainer::RemoveName(const Handle(TCollection_HExtendedString)& theName)
{
  if(IsRegistered(theName)) 
  {
    Backup();
    myMap.UnBind(theName);
  }
}

void TObj_TNameContainer::Clear()
{
  Backup();
  myMap.Clear();
}

//=======================================================================
//function : CheckName
//purpose  : 
//=======================================================================

Standard_Boolean TObj_TNameContainer::IsRegistered(const Handle(TCollection_HExtendedString)& theName) const
{
  return myMap.IsBound(theName);
}
  
//=======================================================================
//function : NewEmpty
//purpose  : 
//=======================================================================

Handle(TDF_Attribute) TObj_TNameContainer::NewEmpty () const
{  
  return new TObj_TNameContainer();
}

//=======================================================================
//function : Restore
//purpose  : 
//=======================================================================

void TObj_TNameContainer::Restore(const Handle(TDF_Attribute)& theWith) 
{
  Handle(TObj_TNameContainer) R = Handle(TObj_TNameContainer)::DownCast (theWith);
  
  myMap = R->Get();
}

//=======================================================================
//function : Paste
//purpose  : 
//=======================================================================

void TObj_TNameContainer::Paste (const Handle(TDF_Attribute)& theInto,
                                     const Handle(TDF_RelocationTable)& /* RT */) const
{ 
  Handle(TObj_TNameContainer) R = Handle(TObj_TNameContainer)::DownCast (theInto);
  R->Set(myMap);
}

//=======================================================================
//function : Get
//purpose  : 
//=======================================================================

const TObj_DataMapOfNameLabel& TObj_TNameContainer::Get() const
{
  return myMap;
}

//=======================================================================
//function : Set
//purpose  : 
//=======================================================================

void TObj_TNameContainer::Set(const TObj_DataMapOfNameLabel& theMap)
{
  Backup();
  myMap = theMap;
}
