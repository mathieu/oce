
#include <RWStepGeom_RWEllipse.ixx>
#include <StepGeom_Axis2Placement.hxx>


#include <Interface_EntityIterator.hxx>


#include <StepGeom_Ellipse.hxx>


RWStepGeom_RWEllipse::RWStepGeom_RWEllipse () {}

void RWStepGeom_RWEllipse::ReadStep
	(const Handle(StepData_StepReaderData)& data,
	 const Standard_Integer num,
	 Handle(Interface_Check)& ach,
	 const Handle(StepGeom_Ellipse)& ent) const
{


	// --- Number of Parameter Control ---

	if (!data->CheckNbParams(num,4,ach,"ellipse")) return;

	// --- inherited field : name ---

	Handle(TCollection_HAsciiString) aName;
	//szv#4:S4163:12Mar99 `Standard_Boolean stat1 =` not needed
	data->ReadString (num,1,"name",ach,aName);

	// --- inherited field : position ---

	StepGeom_Axis2Placement aPosition;
	//szv#4:S4163:12Mar99 `Standard_Boolean stat2 =` not needed
	data->ReadEntity(num,2,"position",ach,aPosition);

	// --- own field : semiAxis1 ---

	Standard_Real aSemiAxis1;
	//szv#4:S4163:12Mar99 `Standard_Boolean stat3 =` not needed
	data->ReadReal (num,3,"semi_axis_1",ach,aSemiAxis1);

	// --- own field : semiAxis2 ---

	Standard_Real aSemiAxis2;
	//szv#4:S4163:12Mar99 `Standard_Boolean stat4 =` not needed
	data->ReadReal (num,4,"semi_axis_2",ach,aSemiAxis2);

	//--- Initialisation of the read entity ---


	ent->Init(aName, aPosition, aSemiAxis1, aSemiAxis2);
}


void RWStepGeom_RWEllipse::WriteStep
	(StepData_StepWriter& SW,
	 const Handle(StepGeom_Ellipse)& ent) const
{

	// --- inherited field name ---

	SW.Send(ent->Name());

	// --- inherited field position ---

	SW.Send(ent->Position().Value());

	// --- own field : semiAxis1 ---

	SW.Send(ent->SemiAxis1());

	// --- own field : semiAxis2 ---

	SW.Send(ent->SemiAxis2());
}


void RWStepGeom_RWEllipse::Share(const Handle(StepGeom_Ellipse)& ent, Interface_EntityIterator& iter) const
{

	iter.GetOneItem(ent->Position().Value());
}



void RWStepGeom_RWEllipse::Check
(const Handle(StepGeom_Ellipse)& ent,
 const Interface_ShareTool& ,
 Handle(Interface_Check)& ach) const
{
  if (ent->SemiAxis1() < ent->SemiAxis2())
    ach->AddWarning("ERROR: Ellipse: SemiMajor smaller than SemiMinor");
}
