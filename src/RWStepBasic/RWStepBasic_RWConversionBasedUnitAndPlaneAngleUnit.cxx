// sln 09.10.2001. BUC61003. Correction of looking for items of complex entity in case of them  do not saticfy to alphabetical order
#include <RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.ixx>
#include <StepBasic_ConversionBasedUnit.hxx>
#include <StepBasic_PlaneAngleUnit.hxx>
#include <StepBasic_DimensionalExponents.hxx>
#include <StepBasic_MeasureWithUnit.hxx>


#include <Interface_EntityIterator.hxx>


#include <StepBasic_ConversionBasedUnitAndPlaneAngleUnit.hxx>


RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit () {}

void RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::ReadStep
	(const Handle(StepData_StepReaderData)& data,
	 const Standard_Integer num0,
	 Handle(Interface_Check)& ach,
	 const Handle(StepBasic_ConversionBasedUnitAndPlaneAngleUnit)& ent) const
{
        // sln 09.10.2001. BUC61003. Correction of looking for items of complex entity in case of them  do not saticfy to alphabetical order
        // CONVERSION_BASED_UNIT
	Standard_Integer num = 0;//num0;
	data->NamedForComplex("CONVERSION_BASED_UNIT CNBSUN",num0,num,ach);
	if (!data->CheckNbParams(num,2,ach,"conversion_based_unit")) return;
       	Handle(TCollection_HAsciiString) aName;
	data->ReadString (num,1,"name",ach,aName);
        Handle(StepBasic_MeasureWithUnit) aConversionFactor;
	data->ReadEntity(num, 2,"conversion_factor", ach, STANDARD_TYPE(StepBasic_MeasureWithUnit), aConversionFactor);
        
        // NAMED_UNIT
        //num = 0; //gka TRJ9 c2-id-214.stp
	data->NamedForComplex("NAMED_UNIT NMDUNT",num0,num,ach);
        if (!data->CheckNbParams(num,1,ach,"named_unit")) return;
	Handle(StepBasic_DimensionalExponents) aDimensions;
	data->ReadEntity(num, 1,"dimensions", ach, STANDARD_TYPE(StepBasic_DimensionalExponents), aDimensions);

        // PLANE_ANGLE_UNIT
        //num = 0; //gka
	data->NamedForComplex("PLANE_ANGLE_UNIT PLANUN",num0,num,ach);
        if (!data->CheckNbParams(num,0,ach,"plane_angle_unit")) return;
        
	ent->Init(aDimensions,aName,aConversionFactor);
}


void RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::WriteStep
	(StepData_StepWriter& SW,
	 const Handle(StepBasic_ConversionBasedUnitAndPlaneAngleUnit)& ent) const
{

	// --- Instance of plex componant ConversionBasedUnit ---

	SW.StartEntity("CONVERSION_BASED_UNIT");
	// --- field : name ---

	SW.Send(ent->Name());
	// --- field : conversionFactor ---

	SW.Send(ent->ConversionFactor());

	// --- Instance of common supertype NamedUnit ---

	SW.StartEntity("NAMED_UNIT");
	// --- field : dimensions ---

	SW.Send(ent->Dimensions());

	// --- Instance of plex componant PlaneAngleUnit ---

	SW.StartEntity("PLANE_ANGLE_UNIT");
}


void RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::Share(const Handle(StepBasic_ConversionBasedUnitAndPlaneAngleUnit)& ent, Interface_EntityIterator& iter) const
{

	iter.GetOneItem(ent->Dimensions());


	iter.GetOneItem(ent->ConversionFactor());
}

