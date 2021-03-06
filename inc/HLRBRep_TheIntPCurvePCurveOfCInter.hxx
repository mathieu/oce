// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _HLRBRep_TheIntPCurvePCurveOfCInter_HeaderFile
#define _HLRBRep_TheIntPCurvePCurveOfCInter_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _IntRes2d_Domain_HeaderFile
#include <IntRes2d_Domain.hxx>
#endif
#ifndef _IntRes2d_Intersection_HeaderFile
#include <IntRes2d_Intersection.hxx>
#endif
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class HLRBRep_CurveTool;
class HLRBRep_TheProjPCurOfCInter;
class HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter;
class HLRBRep_ThePolygon2dToolOfTheIntPCurvePCurveOfCInter;
class HLRBRep_InterferencePoly2dOfTheIntPCurvePCurveOfCInter;
class HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter;
class HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter;
class IntRes2d_Domain;



class HLRBRep_TheIntPCurvePCurveOfCInter  : public IntRes2d_Intersection {
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

  
  Standard_EXPORT   HLRBRep_TheIntPCurvePCurveOfCInter();
  
  Standard_EXPORT     void Perform(const Standard_Address& Curve1,const IntRes2d_Domain& Domain1,const Standard_Address& Curve2,const IntRes2d_Domain& Domain2,const Standard_Real TolConf,const Standard_Real Tol) ;
  
  Standard_EXPORT     void Perform(const Standard_Address& Curve1,const IntRes2d_Domain& Domain1,const Standard_Real TolConf,const Standard_Real Tol) ;





protected:

  
  Standard_EXPORT     void Perform(const Standard_Address& Curve1,const IntRes2d_Domain& Domain1,const Standard_Address& Curve2,const IntRes2d_Domain& Domain2,const Standard_Real TolConf,const Standard_Real Tol,const Standard_Integer NbIter,const Standard_Real DeltaU,const Standard_Real DeltaV) ;
  
  Standard_EXPORT     void Perform(const Standard_Address& Curve1,const IntRes2d_Domain& Domain1,const Standard_Real TolConf,const Standard_Real Tol,const Standard_Integer NbIter,const Standard_Real DeltaU,const Standard_Real DeltaV) ;




private:



IntRes2d_Domain DomainOnCurve1;
IntRes2d_Domain DomainOnCurve2;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
