// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESDraw_SegmentedViewsVisible_HeaderFile
#define _IGESDraw_SegmentedViewsVisible_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IGESDraw_SegmentedViewsVisible_HeaderFile
#include <Handle_IGESDraw_SegmentedViewsVisible.hxx>
#endif

#ifndef _Handle_IGESDraw_HArray1OfViewKindEntity_HeaderFile
#include <Handle_IGESDraw_HArray1OfViewKindEntity.hxx>
#endif
#ifndef _Handle_TColStd_HArray1OfReal_HeaderFile
#include <Handle_TColStd_HArray1OfReal.hxx>
#endif
#ifndef _Handle_TColStd_HArray1OfInteger_HeaderFile
#include <Handle_TColStd_HArray1OfInteger.hxx>
#endif
#ifndef _Handle_IGESGraph_HArray1OfColor_HeaderFile
#include <Handle_IGESGraph_HArray1OfColor.hxx>
#endif
#ifndef _Handle_IGESBasic_HArray1OfLineFontEntity_HeaderFile
#include <Handle_IGESBasic_HArray1OfLineFontEntity.hxx>
#endif
#ifndef _IGESData_ViewKindEntity_HeaderFile
#include <IGESData_ViewKindEntity.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_IGESData_ViewKindEntity_HeaderFile
#include <Handle_IGESData_ViewKindEntity.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_IGESGraph_Color_HeaderFile
#include <Handle_IGESGraph_Color.hxx>
#endif
#ifndef _Handle_IGESData_LineFontEntity_HeaderFile
#include <Handle_IGESData_LineFontEntity.hxx>
#endif
class IGESDraw_HArray1OfViewKindEntity;
class TColStd_HArray1OfReal;
class TColStd_HArray1OfInteger;
class IGESGraph_HArray1OfColor;
class IGESBasic_HArray1OfLineFontEntity;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class IGESData_ViewKindEntity;
class IGESGraph_Color;
class IGESData_LineFontEntity;


//! defines IGESSegmentedViewsVisible, Type <402> Form <19> <br>
//!          in package IGESDraw <br>
class IGESDraw_SegmentedViewsVisible : public IGESData_ViewKindEntity {

public:

  
  Standard_EXPORT   IGESDraw_SegmentedViewsVisible();
  //! This method is used to set the fields of the class <br>
//!           SegmentedViewsVisible <br>
//!       - allViews                : Pointers to View Entities <br>
//!       - allBreakpointParameters : Parameters of breakpoints <br>
//!       - allDisplayFlags         : Display flags <br>
//!       - allColorValues          : Color Values <br>
//!       - allColorDefinitions     : Color Definitions <br>
//!       - allLineFontValues       : LineFont values <br>
//!       - allLineFontDefinitions  : LineFont Definitions <br>
//!       - allLineWeights          : Line weights <br>
//! raises exception if Lengths of allViews, allBreakpointParameters, <br>
//! allDisplayFlags, allColorValues, allColorDefinitions, <br>
//! allLineFontValues, allLineFontDefinitions and allLineWeights <br>
//! are not same. <br>
  Standard_EXPORT     void Init(const Handle(IGESDraw_HArray1OfViewKindEntity)& allViews,const Handle(TColStd_HArray1OfReal)& allBreakpointParameters,const Handle(TColStd_HArray1OfInteger)& allDisplayFlags,const Handle(TColStd_HArray1OfInteger)& allColorValues,const Handle(IGESGraph_HArray1OfColor)& allColorDefinitions,const Handle(TColStd_HArray1OfInteger)& allLineFontValues,const Handle(IGESBasic_HArray1OfLineFontEntity)& allLineFontDefinitions,const Handle(TColStd_HArray1OfInteger)& allLineWeights) ;
  //! Returns False (for a complex view) <br>
  Standard_EXPORT     Standard_Boolean IsSingle() const;
  //! Returns the count of Views referenced by <me> (inherited) <br>
  Standard_EXPORT     Standard_Integer NbViews() const;
  //! returns the number of view/segment blocks in <me> <br>
//!           Similar to NbViews but has a more general significance <br>
  Standard_EXPORT     Standard_Integer NbSegmentBlocks() const;
  //! returns the View entity indicated by ViewIndex <br>
//! raises an exception if ViewIndex <= 0 or <br>
//! ViewIndex > NbSegmentBlocks() <br>
  Standard_EXPORT     Handle_IGESData_ViewKindEntity ViewItem(const Standard_Integer ViewIndex) const;
  //! returns the parameter of the breakpoint indicated by <br>
//! BreakpointIndex <br>
//! raises an exception if BreakpointIndex <= 0 or <br>
//! BreakpointIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Standard_Real BreakpointParameter(const Standard_Integer BreakpointIndex) const;
  //! returns the Display flag indicated by FlagIndex <br>
//! raises an exception if FlagIndex <= 0 or <br>
//! FlagIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Standard_Integer DisplayFlag(const Standard_Integer FlagIndex) const;
  //! returns True if the ColorIndex'th value of the <br>
//! "theColorDefinitions" field of <me> is a pointer <br>
//! raises an exception if ColorIndex <= 0 or <br>
//! ColorIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Standard_Boolean IsColorDefinition(const Standard_Integer ColorIndex) const;
  //! returns the Color value indicated by ColorIndex <br>
//! raises an exception if ColorIndex <= 0 or <br>
//! ColorIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Standard_Integer ColorValue(const Standard_Integer ColorIndex) const;
  //! returns the Color definition entity indicated by ColorIndex <br>
//! raises an exception if ColorIndex <= 0 or <br>
//! ColorIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Handle_IGESGraph_Color ColorDefinition(const Standard_Integer ColorIndex) const;
  //! returns True if the FontIndex'th value of the <br>
//! "theLineFontDefinitions" field of <me> is a pointer <br>
//! raises an exception if FontIndex <= 0 or <br>
//! FontIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Standard_Boolean IsFontDefinition(const Standard_Integer FontIndex) const;
  //! returns the LineFont value indicated by FontIndex <br>
//! raises an exception if FontIndex <= 0 or <br>
//! FontIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Standard_Integer LineFontValue(const Standard_Integer FontIndex) const;
  //! returns the LineFont definition entity indicated by FontIndex <br>
//! raises an exception if FontIndex <= 0 or <br>
//! FontIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Handle_IGESData_LineFontEntity LineFontDefinition(const Standard_Integer FontIndex) const;
  //! returns the LineWeight value indicated by WeightIndex <br>
//! raises an exception if WeightIndex <= 0 or <br>
//! WeightIndex > NbSegmentBlocks(). <br>
  Standard_EXPORT     Standard_Integer LineWeightItem(const Standard_Integer WeightIndex) const;




  DEFINE_STANDARD_RTTI(IGESDraw_SegmentedViewsVisible)

protected:




private: 


Handle_IGESDraw_HArray1OfViewKindEntity theViews;
Handle_TColStd_HArray1OfReal theBreakpointParameters;
Handle_TColStd_HArray1OfInteger theDisplayFlags;
Handle_TColStd_HArray1OfInteger theColorValues;
Handle_IGESGraph_HArray1OfColor theColorDefinitions;
Handle_TColStd_HArray1OfInteger theLineFontValues;
Handle_IGESBasic_HArray1OfLineFontEntity theLineFontDefinitions;
Handle_TColStd_HArray1OfInteger theLineWeights;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
