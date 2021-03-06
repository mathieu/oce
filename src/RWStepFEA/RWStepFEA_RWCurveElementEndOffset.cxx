// File:	RWStepFEA_RWCurveElementEndOffset.cxx
// Created:	Thu Dec 12 17:51:03 2002 
// Author:	data exchange team
// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.2
// Copyright:	Open CASCADE 2002

#include <RWStepFEA_RWCurveElementEndOffset.ixx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_Real.hxx>

//=======================================================================
//function : RWStepFEA_RWCurveElementEndOffset
//purpose  : 
//=======================================================================

RWStepFEA_RWCurveElementEndOffset::RWStepFEA_RWCurveElementEndOffset ()
{
}

//=======================================================================
//function : ReadStep
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementEndOffset::ReadStep (const Handle(StepData_StepReaderData)& data,
                                                  const Standard_Integer num,
                                                  Handle(Interface_Check)& ach,
                                                  const Handle(StepFEA_CurveElementEndOffset) &ent) const
{
  // Check number of parameters
  if ( ! data->CheckNbParams(num,2,ach,"curve_element_end_offset") ) return;

  // Own fields of CurveElementEndOffset

  StepFEA_CurveElementEndCoordinateSystem aCoordinateSystem;
  data->ReadEntity (num, 1, "coordinate_system", ach, aCoordinateSystem);

  Handle(TColStd_HArray1OfReal) aOffsetVector;
  Standard_Integer sub2 = 0;
  if ( data->ReadSubList (num, 2, "offset_vector", ach, sub2) ) {
    Standard_Integer nb0 = data->NbParams(sub2);
    aOffsetVector = new TColStd_HArray1OfReal (1, nb0);
    Standard_Integer num2 = sub2;
    for ( Standard_Integer i0=1; i0 <= nb0; i0++ ) {
      Standard_Real anIt0;
      data->ReadReal (num2, i0, "real", ach, anIt0);
      aOffsetVector->SetValue(i0, anIt0);
    }
  }

  // Initialize entity
  ent->Init(aCoordinateSystem,
            aOffsetVector);
}

//=======================================================================
//function : WriteStep
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementEndOffset::WriteStep (StepData_StepWriter& SW,
                                                   const Handle(StepFEA_CurveElementEndOffset) &ent) const
{

  // Own fields of CurveElementEndOffset

  SW.Send (ent->CoordinateSystem().Value());

  SW.OpenSub();
  for (Standard_Integer i1=1; i1 <= ent->OffsetVector()->Length(); i1++ ) {
    Standard_Real Var0 = ent->OffsetVector()->Value(i1);
    SW.Send (Var0);
  }
  SW.CloseSub();
}

//=======================================================================
//function : Share
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementEndOffset::Share (const Handle(StepFEA_CurveElementEndOffset) &ent,
                                               Interface_EntityIterator& iter) const
{

  // Own fields of CurveElementEndOffset

  iter.AddItem (ent->CoordinateSystem().Value());
}
