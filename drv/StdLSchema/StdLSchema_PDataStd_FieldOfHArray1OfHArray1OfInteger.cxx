#ifndef _StdLSchema_PDataStd_FieldOfHArray1OfHArray1OfInteger_HeaderFile
#include <StdLSchema_PDataStd_FieldOfHArray1OfHArray1OfInteger.hxx>
#endif
#ifndef _PDataStd_FieldOfHArray1OfHArray1OfInteger_HeaderFile
#include <PDataStd_FieldOfHArray1OfHArray1OfInteger.hxx>
#endif
#include <StdLSchema_PDataStd_FieldOfHArray1OfHArray1OfInteger.ixx>
#ifndef _Storage_Schema_HeaderFile
#include <Storage_Schema.hxx>
#endif
#ifndef _Storage_stCONSTclCOM_HeaderFile
#include <Storage_stCONSTclCOM.hxx>
#endif

void StdLSchema_PDataStd_FieldOfHArray1OfHArray1OfInteger::SAdd(const PDataStd_FieldOfHArray1OfHArray1OfInteger& p, const Handle(Storage_Schema)& theSchema)
{
    Standard_Integer i;
  for (i = 0; i < p.Length(); i++) {
    theSchema->PersistentToAdd(p.Value(i));    
  }

}

void StdLSchema_PDataStd_FieldOfHArray1OfHArray1OfInteger::SWrite(const PDataStd_FieldOfHArray1OfHArray1OfInteger& pp, Storage_BaseDriver& f, const Handle(Storage_Schema)& theSchema)
{
  Standard_Integer i;

  f.BeginWriteObjectData();
  f.PutInteger(pp.Length());
  for (i = 0; i < pp.Length(); i++) {
    theSchema->WritePersistentReference(pp.Value(i),f);

  }
  f.EndWriteObjectData();
}

void StdLSchema_PDataStd_FieldOfHArray1OfHArray1OfInteger::SRead(PDataStd_FieldOfHArray1OfHArray1OfInteger& pp, Storage_BaseDriver& f, const Handle(Storage_Schema)& theSchema)
{
  Standard_Integer size = 0;

  f.BeginReadObjectData();
  f.GetInteger(size);
  pp.Resize(size);

  for (Standard_Integer j = 0; j < size; j++) {
    Handle(PColStd_HArray1OfInteger) par;

    theSchema->ReadPersistentReference(par,f);
    pp.SetValue(j,par);

  }
  f.EndReadObjectData();
}
