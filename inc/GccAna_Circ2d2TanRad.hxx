// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GccAna_Circ2d2TanRad_HeaderFile
#define _GccAna_Circ2d2TanRad_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _GccEnt_Array1OfPosition_HeaderFile
#include <GccEnt_Array1OfPosition.hxx>
#endif
#ifndef _TColStd_Array1OfInteger_HeaderFile
#include <TColStd_Array1OfInteger.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TColgp_Array1OfCirc2d_HeaderFile
#include <TColgp_Array1OfCirc2d.hxx>
#endif
#ifndef _TColgp_Array1OfPnt2d_HeaderFile
#include <TColgp_Array1OfPnt2d.hxx>
#endif
#ifndef _TColStd_Array1OfReal_HeaderFile
#include <TColStd_Array1OfReal.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _GccEnt_Position_HeaderFile
#include <GccEnt_Position.hxx>
#endif
class Standard_NegativeValue;
class Standard_OutOfRange;
class GccEnt_BadQualifier;
class StdFail_NotDone;
class GccEnt_QualifiedCirc;
class GccEnt_QualifiedLin;
class gp_Pnt2d;
class gp_Circ2d;


//! This class implements the algorithms used to <br>
//!          create 2d circles tangent to 2 <br>
//!          points/lines/circles and with a given radius. <br>
//!          For each construction methods arguments are: <br>
//!            - Two Qualified elements for tangency constraints. <br>
//!            (for example EnclosedCirc if we want the <br>
//!            solution inside the argument EnclosedCirc). <br>
//!            - Two Reals. One (Radius) for the radius and the <br>
//!            other (Tolerance) for the tolerance. <br>
//!          Tolerance is only used for the limit cases. <br>
//!          For example : <br>
//!          We want to create a circle inside a circle C1 and <br>
//!          inside a circle C2 with a radius Radius and a <br>
//!          tolerance Tolerance. <br>
//!          If we do not use Tolerance it is impossible to <br>
//!          find a solution in the following case : C2 is <br>
//!          inside C1 and there is no intersection point <br>
//!          between the two circles. <br>
//!          With Tolerance it gives a solution if the lowest <br>
//!          distance between C1 and C2 is lower than or equal <br>
//!          Tolerance. <br>
class GccAna_Circ2d2TanRad  {
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

  //! This method implements the algorithms used to <br>
//!          create 2d circles TANgent to two 2d circle with a <br>
//!          radius of Radius. <br>//! It raises NegativeValue if Radius is lower than zero. <br>
  Standard_EXPORT   GccAna_Circ2d2TanRad(const GccEnt_QualifiedCirc& Qualified1,const GccEnt_QualifiedCirc& Qualified2,const Standard_Real Radius,const Standard_Real Tolerance);
  //! This method implements the algorithms used to <br>
//!          create 2d circles TANgent to a 2d circle and a 2d line <br>
//!          with a radius of Radius. <br>//! It raises NegativeValue if Radius is lower than zero. <br>
  Standard_EXPORT   GccAna_Circ2d2TanRad(const GccEnt_QualifiedCirc& Qualified1,const GccEnt_QualifiedLin& Qualified2,const Standard_Real Radius,const Standard_Real Tolerance);
  //! This method implements the algorithms used to <br>
//!          create 2d circles TANgent to a 2d circle and a point <br>
//!          with a radius of Radius. <br>//! It raises NegativeValue if Radius is lower than zero. <br>
  Standard_EXPORT   GccAna_Circ2d2TanRad(const GccEnt_QualifiedCirc& Qualified1,const gp_Pnt2d& Point2,const Standard_Real Radius,const Standard_Real Tolerance);
  //! This method implements the algorithms used to <br>
//!          create 2d circles TANgent to a 2d line and a point <br>
//!          with a radius of Radius. <br>//! It raises NegativeValue if Radius is lower than zero. <br>
  Standard_EXPORT   GccAna_Circ2d2TanRad(const GccEnt_QualifiedLin& Qualified1,const gp_Pnt2d& Point2,const Standard_Real Radius,const Standard_Real Tolerance);
  //! This method implements the algorithms used to <br>
//!          create 2d circles TANgent to two 2d lines <br>
//!          with a radius of Radius. <br>//! It raises NegativeValue if Radius is lower than zero. <br>
  Standard_EXPORT   GccAna_Circ2d2TanRad(const GccEnt_QualifiedLin& Qualified1,const GccEnt_QualifiedLin& Qualified2,const Standard_Real Radius,const Standard_Real Tolerance);
  //! This method implements the algorithms used to <br>
//!          create 2d circles passing through two points with a <br>
//!          radius of Radius. <br>//! It raises NegativeValue if Radius is lower than zero. <br>
  Standard_EXPORT   GccAna_Circ2d2TanRad(const gp_Pnt2d& Point1,const gp_Pnt2d& Point2,const Standard_Real Radius,const Standard_Real Tolerance);
  //! This method returns True if the algorithm succeeded. <br>
//! Note: IsDone protects against a failure arising from a <br>
//! more internal intersection algorithm, which has reached its numeric limits. <br>
  Standard_EXPORT     Standard_Boolean IsDone() const;
  //! This method returns the number of circles, representing solutions computed by this algorithm. <br>
//! Exceptions <br>
//! StdFail_NotDone if the construction fails. of solutions. <br>
  Standard_EXPORT     Standard_Integer NbSolutions() const;
  //! Returns the solution number Index. <br>
//!          Be careful: the Index is only a way to get all the <br>
//!          solutions, but is not associated to those outside the context <br>
//!          of the algorithm-object. Raises OutOfRange exception if Index is greater <br>
//!          than the number of solutions. <br>
//!          It raises NotDone if the construction algorithm did not <br>
//!          succeed. <br>
  Standard_EXPORT     gp_Circ2d ThisSolution(const Standard_Integer Index) const;
  //! Returns the information about the qualifiers of <br>
//!          the tangency arguments concerning the solution number Index. <br>
//!          It returns the real qualifiers (the qualifiers given to the <br>
//!          constructor method in case of enclosed, enclosing and outside <br>
//!          and the qualifiers computedin case of unqualified). <br>
  Standard_EXPORT     void WhichQualifier(const Standard_Integer Index,GccEnt_Position& Qualif1,GccEnt_Position& Qualif2) const;
  //! Returns information about the tangency point between the <br>
//! result number Index and the first argument. <br>
//! ParSol is the intrinsic parameter of the point PntSol on the solution. <br>
//! ParArg is the intrinsic parameter of the point PntSol on the first <br>
//! argument. Raises OutOfRange if Index is greater than the number <br>
//!          of solutions. <br>
//!          It raises NotDone if the construction algorithm did not succeed <br>
  Standard_EXPORT     void Tangency1(const Standard_Integer Index,Standard_Real& ParSol,Standard_Real& ParArg,gp_Pnt2d& PntSol) const;
  //! Returns information about the tangency point between the <br>
//!          result number Index and the second argument. <br>
//!          ParSol is the intrinsic parameter of the point PntSol on <br>
//!          the solution. <br>
//!          ParArg is the intrinsic parameter of the point PntArg on <br>
//!          the second argument. Raises OutOfRange if Index is greater than the number <br>
//!          of solutions. <br>
//!          It raises NotDone if the construction algorithm did not succeed. <br>
  Standard_EXPORT     void Tangency2(const Standard_Integer Index,Standard_Real& ParSol,Standard_Real& ParArg,gp_Pnt2d& PntSol) const;
  //! Returns True if the solution number Index is equal to <br>
//!          the first argument. Raises OutOfRange if Index is greater than the number <br>
//!          of solutions. <br>
//!          It raises NotDone if the construction algorithm did not <br>
//!          succeed. <br>
  Standard_EXPORT     Standard_Boolean IsTheSame1(const Standard_Integer Index) const;
  //! Returns True if the solution number Index is equal to <br>
//!          the second argument. Raises OutOfRange if Index is greater than the number <br>
//!          of solutions. <br>
//!          It raises NotDone if the construction algorithm did not  succeed. <br>
  Standard_EXPORT     Standard_Boolean IsTheSame2(const Standard_Integer Index) const;





protected:





private:



Standard_Boolean WellDone;
GccEnt_Array1OfPosition qualifier1;
GccEnt_Array1OfPosition qualifier2;
TColStd_Array1OfInteger TheSame1;
TColStd_Array1OfInteger TheSame2;
Standard_Integer NbrSol;
TColgp_Array1OfCirc2d cirsol;
TColgp_Array1OfPnt2d pnttg1sol;
TColgp_Array1OfPnt2d pnttg2sol;
TColStd_Array1OfReal par1sol;
TColStd_Array1OfReal par2sol;
TColStd_Array1OfReal pararg1;
TColStd_Array1OfReal pararg2;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
