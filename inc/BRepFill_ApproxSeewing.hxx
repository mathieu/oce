// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFill_ApproxSeewing_HeaderFile
#define _BRepFill_ApproxSeewing_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BRepFill_MultiLine_HeaderFile
#include <BRepFill_MultiLine.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Geom_Curve_HeaderFile
#include <Handle_Geom_Curve.hxx>
#endif
#ifndef _Handle_Geom2d_Curve_HeaderFile
#include <Handle_Geom2d_Curve.hxx>
#endif
class Geom_Curve;
class Geom2d_Curve;
class StdFail_NotDone;
class BRepFill_MultiLine;


//! Evaluate the 3dCurve  and the PCurves described in <br>
//!          a MultiLine from BRepFill.  The parametrization of <br>
//!          those curves is  not  imposed by  the Bissectrice. <br>
//!          The  parametrization  is given  approximatively by <br>
//!          the abscissa of the curve3d. <br>
class BRepFill_ApproxSeewing  {
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

  
  Standard_EXPORT   BRepFill_ApproxSeewing();
  
  Standard_EXPORT   BRepFill_ApproxSeewing(const BRepFill_MultiLine& ML);
  
  Standard_EXPORT     void Perform(const BRepFill_MultiLine& ML) ;
  
  Standard_EXPORT     Standard_Boolean IsDone() const;
  //! returns the approximation of the 3d Curve <br>
  Standard_EXPORT    const Handle_Geom_Curve& Curve() const;
  //! returns the  approximation  of the  PCurve  on the <br>
//!          first face of the MultiLine <br>
  Standard_EXPORT    const Handle_Geom2d_Curve& CurveOnF1() const;
  //! returns the  approximation  of the  PCurve  on the <br>
//!          first face of the MultiLine <br>
  Standard_EXPORT    const Handle_Geom2d_Curve& CurveOnF2() const;





protected:





private:



BRepFill_MultiLine myML;
Standard_Boolean myIsDone;
Handle_Geom_Curve myCurve;
Handle_Geom2d_Curve myPCurve1;
Handle_Geom2d_Curve myPCurve2;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
