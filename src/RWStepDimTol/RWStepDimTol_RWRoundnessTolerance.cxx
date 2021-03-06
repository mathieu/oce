// File:	RWStepDimTol_RWRoundnessTolerance.cxx
// Created:	Wed Jun  4 13:34:34 2003 
// Author:	Galina KULIKOVA
// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.2
// Copyright:	Open CASCADE 2002

#include <RWStepDimTol_RWRoundnessTolerance.ixx>

//=======================================================================
//function : RWStepDimTol_RWRoundnessTolerance
//purpose  : 
//=======================================================================

RWStepDimTol_RWRoundnessTolerance::RWStepDimTol_RWRoundnessTolerance ()
{
}

//=======================================================================
//function : ReadStep
//purpose  : 
//=======================================================================

void RWStepDimTol_RWRoundnessTolerance::ReadStep (const Handle(StepData_StepReaderData)& data,
                                                  const Standard_Integer num,
                                                  Handle(Interface_Check)& ach,
                                                  const Handle(StepDimTol_RoundnessTolerance) &ent) const
{
  // Check number of parameters
  if ( ! data->CheckNbParams(num,4,ach,"roundness_tolerance") ) return;

  // Inherited fields of GeometricTolerance

  Handle(TCollection_HAsciiString) aGeometricTolerance_Name;
  data->ReadString (num, 1, "geometric_tolerance.name", ach, aGeometricTolerance_Name);

  Handle(TCollection_HAsciiString) aGeometricTolerance_Description;
  data->ReadString (num, 2, "geometric_tolerance.description", ach, aGeometricTolerance_Description);

  Handle(StepBasic_MeasureWithUnit) aGeometricTolerance_Magnitude;
  data->ReadEntity (num, 3, "geometric_tolerance.magnitude", ach, STANDARD_TYPE(StepBasic_MeasureWithUnit), aGeometricTolerance_Magnitude);

  Handle(StepRepr_ShapeAspect) aGeometricTolerance_TolerancedShapeAspect;
  data->ReadEntity (num, 4, "geometric_tolerance.toleranced_shape_aspect", ach, STANDARD_TYPE(StepRepr_ShapeAspect), aGeometricTolerance_TolerancedShapeAspect);

  // Initialize entity
  ent->Init(aGeometricTolerance_Name,
            aGeometricTolerance_Description,
            aGeometricTolerance_Magnitude,
            aGeometricTolerance_TolerancedShapeAspect);
}

//=======================================================================
//function : WriteStep
//purpose  : 
//=======================================================================

void RWStepDimTol_RWRoundnessTolerance::WriteStep (StepData_StepWriter& SW,
                                                   const Handle(StepDimTol_RoundnessTolerance) &ent) const
{

  // Inherited fields of GeometricTolerance

  SW.Send (ent->StepDimTol_GeometricTolerance::Name());

  SW.Send (ent->StepDimTol_GeometricTolerance::Description());

  SW.Send (ent->StepDimTol_GeometricTolerance::Magnitude());

  SW.Send (ent->StepDimTol_GeometricTolerance::TolerancedShapeAspect());
}

//=======================================================================
//function : Share
//purpose  : 
//=======================================================================

void RWStepDimTol_RWRoundnessTolerance::Share (const Handle(StepDimTol_RoundnessTolerance) &ent,
                                               Interface_EntityIterator& iter) const
{

  // Inherited fields of GeometricTolerance

  iter.AddItem (ent->StepDimTol_GeometricTolerance::Magnitude());

  iter.AddItem (ent->StepDimTol_GeometricTolerance::TolerancedShapeAspect());
}
