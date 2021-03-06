// File:        TDataStd_RealArray.cxx
// Created:     Wed Jun  16 10:32:25 1999
// Author:      Sergey RUIN


#include <TDataStd_RealArray.ixx>
#include <TDataStd_DeltaOnModificationOfRealArray.hxx>
#include <TDF_DefaultDeltaOnModification.hxx>
#define OCC2932

//=======================================================================
//function : GetID
//purpose  : 
//=======================================================================

const Standard_GUID& TDataStd_RealArray::GetID() 
{ 
  static Standard_GUID TDataStd_RealArrayID ("2a96b61e-ec8b-11d0-bee7-080009dc3333");
  return TDataStd_RealArrayID; 
}


//=======================================================================
//function : TDataStd_RealArray
//purpose  : Empty Constructor
//=======================================================================

TDataStd_RealArray::TDataStd_RealArray() : myIsDelta(Standard_False){}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void TDataStd_RealArray::Init(const Standard_Integer lower,
                              const Standard_Integer upper)
{
  Backup(); // jfa 15.01.2003 for LH3D1378

  myValue = new TColStd_HArray1OfReal(lower, upper, 0.);
}

//=======================================================================
//function : Set
//purpose  : 
//=======================================================================

Handle(TDataStd_RealArray) TDataStd_RealArray::Set
                                          (const TDF_Label&       label,
                                           const Standard_Integer lower,
                                           const Standard_Integer upper,
					   const Standard_Boolean isDelta) 
{
  Handle(TDataStd_RealArray) A;
  if (!label.FindAttribute (TDataStd_RealArray::GetID(), A)) {
    A = new TDataStd_RealArray;
    A->Init (lower, upper);
    A->SetDelta(isDelta); 
    label.AddAttribute(A);
  }
  else if (lower != A->Lower() || upper != A->Upper())
  {
    A->Init (lower, upper); 
  }
  return A;
}


//=======================================================================
//function : SetValue
//purpose  : 
//=======================================================================

void TDataStd_RealArray::SetValue (const Standard_Integer index,
                                   const Standard_Real value) 
{
  // OCC2932 correction
  if(myValue.IsNull()) return;
  if(myValue->Value(index) == value)
    return; 

  Backup();
  myValue->SetValue(index, value);
}


//=======================================================================
//function : GetValue
//purpose  : 
//=======================================================================

Standard_Real TDataStd_RealArray::Value (const Standard_Integer index) const 
{
  if(myValue.IsNull()) return RealFirst();
  return myValue->Value(index); 
}



//=======================================================================
//function : Lower
//purpose  : 
//=======================================================================
Standard_Integer TDataStd_RealArray::Lower (void) const 
{ 
  if(myValue.IsNull()) return 0;
  return myValue->Lower(); 
}


//=======================================================================
//function : Upper
//purpose  : 
//=======================================================================
Standard_Integer TDataStd_RealArray::Upper (void) const 
{ 
  if(myValue.IsNull()) return 0;
  return myValue->Upper(); 
}


//=======================================================================
//function : Length
//purpose  : 
//=======================================================================
Standard_Integer TDataStd_RealArray::Length (void) const 
{
  if(myValue.IsNull()) return 0;
  return myValue->Length(); 
}


//=======================================================================
//function : ChangeArray
//purpose  : If value of <newArray> differs from <myValue>, Backup 
//         : performed and myValue refers to new instance of HArray1OfReal
//         : that holds <newArray>
//=======================================================================

void TDataStd_RealArray::ChangeArray(const Handle(TColStd_HArray1OfReal)& newArray,
					const Standard_Boolean isCheckItems) 
{
  Standard_Integer aLower    = newArray->Lower();
  Standard_Integer anUpper   = newArray->Upper();
  Standard_Boolean aDimEqual = Standard_False;
  Standard_Integer i;

#ifdef OCC2932
  if (Lower() == aLower && Upper() == anUpper ) {
    aDimEqual = Standard_True;
    Standard_Boolean isEqual = Standard_True;
    if(isCheckItems) {
      for(i = aLower; i <= anUpper; i++) {
	if(myValue->Value(i) != newArray->Value(i)) {
	  isEqual = Standard_False;
	  break;
	}
      }
      if(isEqual)
	return;
    }
  }
#endif

  Backup();

  if(myValue.IsNull() || !aDimEqual) 
    myValue = new TColStd_HArray1OfReal(aLower, anUpper);

  for(i = aLower; i <= anUpper; i++) 
    myValue->SetValue(i, newArray->Value(i));
}

//=======================================================================
//function : ID
//purpose  : 
//=======================================================================

const Standard_GUID& TDataStd_RealArray::ID () const { return GetID(); }


//=======================================================================
//function : NewEmpty
//purpose  : 
//=======================================================================

Handle(TDF_Attribute) TDataStd_RealArray::NewEmpty () const
{  
  return new TDataStd_RealArray(); 
}

//=======================================================================
//function : Restore
//purpose  : 
//=======================================================================

void TDataStd_RealArray::Restore(const Handle(TDF_Attribute)& With) 
{
  Standard_Integer i, lower, upper;
  Handle(TDataStd_RealArray) anArray = Handle(TDataStd_RealArray)::DownCast(With);
  if(!anArray->myValue.IsNull()) {
    lower = anArray->Lower();
    upper = anArray->Upper();
    myIsDelta = anArray->myIsDelta;
    myValue = new TColStd_HArray1OfReal(lower, upper);
    for(i = lower; i<=upper; i++)
      myValue->SetValue(i, anArray->Value(i)); 
  }
  else
    myValue.Nullify();
}

//=======================================================================
//function : Paste
//purpose  : 
//=======================================================================

void TDataStd_RealArray::Paste (const Handle(TDF_Attribute)& Into,
                                const Handle(TDF_RelocationTable)& ) const
{
  if(!myValue.IsNull()) {    
    Handle(TDataStd_RealArray) anAtt = Handle(TDataStd_RealArray)::DownCast(Into);
    if(!anAtt.IsNull()) {
      anAtt->ChangeArray( myValue, Standard_False );
      anAtt->SetDelta(myIsDelta);
    }
  }
}

//=======================================================================
//function : Dump
//purpose  : 
//=======================================================================

Standard_OStream& TDataStd_RealArray::Dump (Standard_OStream& anOS) const
{  
  anOS << "\nRealArray::" << this <<" :";
  if(!myValue.IsNull()) {
    Standard_Integer i, lower, upper;
    lower = myValue->Lower();
    upper = myValue->Upper();
    for(i = lower; i<=upper; i++)
      anOS << " " <<myValue->Value(i);
  }
  anOS << " Delta is " << (myIsDelta ? "ON":"OFF");
  anOS << endl;
  return anOS;
}

//=======================================================================
//function : DeltaOnModification
//purpose  : 
//=======================================================================

Handle(TDF_DeltaOnModification) TDataStd_RealArray::DeltaOnModification
(const Handle(TDF_Attribute)& OldAtt) const
{
  if(myIsDelta)
    return new TDataStd_DeltaOnModificationOfRealArray(*((Handle(TDataStd_RealArray)*)&OldAtt));
  else return new TDF_DefaultDeltaOnModification(OldAtt);
}
