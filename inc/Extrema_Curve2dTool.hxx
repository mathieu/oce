// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Extrema_Curve2dTool_HeaderFile
#define _Extrema_Curve2dTool_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _GeomAbs_Shape_HeaderFile
#include <GeomAbs_Shape.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _gp_Pnt2d_HeaderFile
#include <gp_Pnt2d.hxx>
#endif
#ifndef _gp_Vec2d_HeaderFile
#include <gp_Vec2d.hxx>
#endif
#ifndef _GeomAbs_CurveType_HeaderFile
#include <GeomAbs_CurveType.hxx>
#endif
#ifndef _gp_Lin2d_HeaderFile
#include <gp_Lin2d.hxx>
#endif
#ifndef _gp_Circ2d_HeaderFile
#include <gp_Circ2d.hxx>
#endif
#ifndef _gp_Elips2d_HeaderFile
#include <gp_Elips2d.hxx>
#endif
#ifndef _gp_Hypr2d_HeaderFile
#include <gp_Hypr2d.hxx>
#endif
#ifndef _gp_Parab2d_HeaderFile
#include <gp_Parab2d.hxx>
#endif
#ifndef _Handle_Geom2d_BezierCurve_HeaderFile
#include <Handle_Geom2d_BezierCurve.hxx>
#endif
#ifndef _Handle_Geom2d_BSplineCurve_HeaderFile
#include <Handle_Geom2d_BSplineCurve.hxx>
#endif
class Adaptor2d_Curve2d;
class TColStd_Array1OfReal;
class gp_Pnt2d;
class gp_Vec2d;
class Geom2d_BezierCurve;
class Geom2d_BSplineCurve;



class Extrema_Curve2dTool  {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  
      static  Standard_Real FirstParameter(const Adaptor2d_Curve2d& C) ;
  
      static  Standard_Real LastParameter(const Adaptor2d_Curve2d& C) ;
  
      static  GeomAbs_Shape Continuity(const Adaptor2d_Curve2d& C) ;
  //! If necessary,   breaks the curve  in  intervals of <br>
//!          continuity <S>.     And   returns  the  number  of <br>
//!          intervals. <br>
      static  Standard_Integer NbIntervals(const Adaptor2d_Curve2d& C,const GeomAbs_Shape S) ;
  //! Stores in <T> the  parameters bounding the intervals <br>
//!          of continuity <S>. <br>
      static  void Intervals(const Adaptor2d_Curve2d& C,TColStd_Array1OfReal& T,const GeomAbs_Shape S) ;
  
      static  Standard_Boolean IsClosed(const Adaptor2d_Curve2d& C) ;
  
      static  Standard_Boolean IsPeriodic(const Adaptor2d_Curve2d& C) ;
  
      static  Standard_Real Period(const Adaptor2d_Curve2d& C) ;
  //! Computes the point of parameter U on the curve. <br>
      static  gp_Pnt2d Value(const Adaptor2d_Curve2d& C,const Standard_Real U) ;
  //! Computes the point of parameter U on the curve. <br>
      static  void D0(const Adaptor2d_Curve2d& C,const Standard_Real U,gp_Pnt2d& P) ;
  //! Computes the point of parameter U on the curve with its <br>
//!  first derivative. <br>
      static  void D1(const Adaptor2d_Curve2d& C,const Standard_Real U,gp_Pnt2d& P,gp_Vec2d& V) ;
  
//!  Returns the point P of parameter U, the first and second <br>
//!  derivatives V1 and V2. <br>
      static  void D2(const Adaptor2d_Curve2d& C,const Standard_Real U,gp_Pnt2d& P,gp_Vec2d& V1,gp_Vec2d& V2) ;
  
//!  Returns the point P of parameter U, the first, the second <br>
//!  and the third derivative. <br>
      static  void D3(const Adaptor2d_Curve2d& C,const Standard_Real U,gp_Pnt2d& P,gp_Vec2d& V1,gp_Vec2d& V2,gp_Vec2d& V3) ;
  
//!  The returned vector gives the value of the derivative for the <br>
//!  order of derivation N. <br>
      static  gp_Vec2d DN(const Adaptor2d_Curve2d& C,const Standard_Real U,const Standard_Integer N) ;
  //!  Returns the parametric  resolution corresponding <br>
//!         to the real space resolution <R3d>. <br>
      static  Standard_Real Resolution(const Adaptor2d_Curve2d& C,const Standard_Real R3d) ;
  //! Returns  the  type of the   curve  in the  current <br>
//!          interval :   Line,   Circle,   Ellipse, Hyperbola, <br>
//!          Parabola, BezierCurve, BSplineCurve, OtherCurve. <br>
      static  GeomAbs_CurveType GetType(const Adaptor2d_Curve2d& C) ;
  
      static  gp_Lin2d Line(const Adaptor2d_Curve2d& C) ;
  
      static  gp_Circ2d Circle(const Adaptor2d_Curve2d& C) ;
  
      static  gp_Elips2d Ellipse(const Adaptor2d_Curve2d& C) ;
  
      static  gp_Hypr2d Hyperbola(const Adaptor2d_Curve2d& C) ;
  
      static  gp_Parab2d Parabola(const Adaptor2d_Curve2d& C) ;
  
      static  Standard_Integer Degree(const Adaptor2d_Curve2d& C) ;
  
      static  Standard_Boolean IsRational(const Adaptor2d_Curve2d& C) ;
  
      static  Standard_Integer NbPoles(const Adaptor2d_Curve2d& C) ;
  
      static  Standard_Integer NbKnots(const Adaptor2d_Curve2d& C) ;
  
      static  Handle_Geom2d_BezierCurve Bezier(const Adaptor2d_Curve2d& C) ;
  
      static  Handle_Geom2d_BSplineCurve BSpline(const Adaptor2d_Curve2d& C) ;





protected:





private:





};


#include <Extrema_Curve2dTool.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
