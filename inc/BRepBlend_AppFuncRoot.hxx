// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepBlend_AppFuncRoot_HeaderFile
#define _BRepBlend_AppFuncRoot_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BRepBlend_AppFuncRoot_HeaderFile
#include <Handle_BRepBlend_AppFuncRoot.hxx>
#endif

#ifndef _Handle_BRepBlend_Line_HeaderFile
#include <Handle_BRepBlend_Line.hxx>
#endif
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _math_Vector_HeaderFile
#include <math_Vector.hxx>
#endif
#ifndef _Blend_Point_HeaderFile
#include <Blend_Point.hxx>
#endif
#ifndef _gp_Pnt_HeaderFile
#include <gp_Pnt.hxx>
#endif
#ifndef _Approx_SweepFunction_HeaderFile
#include <Approx_SweepFunction.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _GeomAbs_Shape_HeaderFile
#include <GeomAbs_Shape.hxx>
#endif
class BRepBlend_Line;
class Standard_OutOfRange;
class Blend_AppFunction;
class TColgp_Array1OfPnt;
class TColgp_Array1OfPnt2d;
class TColStd_Array1OfReal;
class TColgp_Array1OfVec;
class TColgp_Array1OfVec2d;
class TColStd_Array1OfInteger;
class gp_Pnt;
class Blend_Point;
class math_Vector;


//! Function to approximate by AppSurface <br>
class BRepBlend_AppFuncRoot : public Approx_SweepFunction {

public:

  //! compute the section for v = param <br>
  Standard_EXPORT   virtual  Standard_Boolean D0(const Standard_Real Param,const Standard_Real First,const Standard_Real Last,TColgp_Array1OfPnt& Poles,TColgp_Array1OfPnt2d& Poles2d,TColStd_Array1OfReal& Weigths) ;
  //! compute the first  derivative in v direction  of the <br>
//!           section for v =  param <br>
  Standard_EXPORT   virtual  Standard_Boolean D1(const Standard_Real Param,const Standard_Real First,const Standard_Real Last,TColgp_Array1OfPnt& Poles,TColgp_Array1OfVec& DPoles,TColgp_Array1OfPnt2d& Poles2d,TColgp_Array1OfVec2d& DPoles2d,TColStd_Array1OfReal& Weigths,TColStd_Array1OfReal& DWeigths) ;
  //! compute the second derivative  in v direction of the <br>
//!          section  for v = param <br>
  Standard_EXPORT   virtual  Standard_Boolean D2(const Standard_Real Param,const Standard_Real First,const Standard_Real Last,TColgp_Array1OfPnt& Poles,TColgp_Array1OfVec& DPoles,TColgp_Array1OfVec& D2Poles,TColgp_Array1OfPnt2d& Poles2d,TColgp_Array1OfVec2d& DPoles2d,TColgp_Array1OfVec2d& D2Poles2d,TColStd_Array1OfReal& Weigths,TColStd_Array1OfReal& DWeigths,TColStd_Array1OfReal& D2Weigths) ;
  //! get the number of 2d curves to  approximate. <br>
  Standard_EXPORT   virtual  Standard_Integer Nb2dCurves() const;
  //! get the format of an  section <br>
  Standard_EXPORT   virtual  void SectionShape(Standard_Integer& NbPoles,Standard_Integer& NbKnots,Standard_Integer& Degree) const;
  //! get the Knots of the section <br>
  Standard_EXPORT   virtual  void Knots(TColStd_Array1OfReal& TKnots) const;
  //! get the Multplicities of the section <br>
  Standard_EXPORT   virtual  void Mults(TColStd_Array1OfInteger& TMults) const;
  //! Returns if the section is rationnal or not <br>
  Standard_EXPORT   virtual  Standard_Boolean IsRational() const;
  //! Returns  the number  of  intervals for  continuity <br>
//!          <S>. May be one if Continuity(me) >= <S> <br>
  Standard_EXPORT   virtual  Standard_Integer NbIntervals(const GeomAbs_Shape S) const;
  //! Stores in <T> the  parameters bounding the intervals <br>
//!          of continuity <S>. <br>
//! <br>
//!          The array must provide  enough room to  accomodate <br>
//!          for the parameters. i.e. T.Length() > NbIntervals() <br>
  Standard_EXPORT   virtual  void Intervals(TColStd_Array1OfReal& T,const GeomAbs_Shape S) const;
  //! Sets the bounds of the parametric interval on <br>
//!          the fonction <br>
//!          This determines the derivatives in these values if the <br>
//!          function is not Cn. <br>
  Standard_EXPORT   virtual  void SetInterval(const Standard_Real First,const Standard_Real Last) ;
  //! Returns the resolutions in the  sub-space 2d <Index> -- <br>
//!          This information is usfull to find an good tolerance in <br>
//!          2d approximation <br>
  Standard_EXPORT   virtual  void Resolution(const Standard_Integer Index,const Standard_Real Tol,Standard_Real& TolU,Standard_Real& TolV) const;
  //! Returns the tolerance to reach in approximation <br>
//!          to respecte <br>
//!          BoundTol error at the Boundary <br>
//!          AngleTol tangent error at the Boundary (in radian) <br>
//!          SurfTol error inside the surface. <br>
  Standard_EXPORT   virtual  void GetTolerance(const Standard_Real BoundTol,const Standard_Real SurfTol,const Standard_Real AngleTol,TColStd_Array1OfReal& Tol3d) const;
  //! Is usfull, if (me) have to  be run numerical <br>
//!           algorithme to perform D0, D1 or D2 <br>
  Standard_EXPORT   virtual  void SetTolerance(const Standard_Real Tol3d,const Standard_Real Tol2d) ;
  //!  Get    the   barycentre of   Surface.   An   very  poor <br>
//!          estimation is sufficent. This information is usefull <br>
//!          to perform well conditionned rational approximation. <br>
  Standard_EXPORT   virtual  gp_Pnt BarycentreOfSurf() const;
  //! Returns the   length of the maximum section. This <br>
//!          information is usefull to perform well conditionned rational <br>
//!          approximation. <br>
  Standard_EXPORT   virtual  Standard_Real MaximalSection() const;
  //! Compute the minimal value of weight for each poles <br>
//!          of all  sections.  This information is  usefull to <br>
//!          perform well conditionned rational approximation. <br>
  Standard_EXPORT   virtual  void GetMinimalWeight(TColStd_Array1OfReal& Weigths) const;
  
  Standard_EXPORT   virtual  void Point(const Blend_AppFunction& Func,const Standard_Real Param,const math_Vector& Sol,Blend_Point& Pnt) const = 0;
  
  Standard_EXPORT   virtual  void Vec(math_Vector& Sol,const Blend_Point& Pnt) const = 0;




  DEFINE_STANDARD_RTTI(BRepBlend_AppFuncRoot)

protected:

  
  Standard_EXPORT   BRepBlend_AppFuncRoot(Handle(BRepBlend_Line)& Line,Blend_AppFunction& Func,const Standard_Real Tol3d,const Standard_Real Tol2d);



private: 

  
  Standard_EXPORT     Standard_Boolean SearchPoint(Blend_AppFunction& Func,const Standard_Real Param,Blend_Point& Pnt) ;
  
  Standard_EXPORT     Standard_Boolean SearchLocation(const Standard_Real Param,const Standard_Integer FirstIndex,const Standard_Integer LastIndex,Standard_Integer& ParamIndex) const;

Handle_BRepBlend_Line myLine;
Standard_Address myFunc;
Standard_Integer mydimension;
math_Vector myTolerance;
Blend_Point myPnt;
gp_Pnt myBary;
math_Vector X1;
math_Vector X2;
math_Vector XInit;
math_Vector Sol;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
