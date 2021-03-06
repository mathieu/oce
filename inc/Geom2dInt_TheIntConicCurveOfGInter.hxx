// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Geom2dInt_TheIntConicCurveOfGInter_HeaderFile
#define _Geom2dInt_TheIntConicCurveOfGInter_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _IntRes2d_Intersection_HeaderFile
#include <IntRes2d_Intersection.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class IntCurve_IConicTool;
class Adaptor2d_Curve2d;
class Geom2dInt_Geom2dCurveTool;
class Geom2dInt_TheProjPCurOfGInter;
class Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter;
class Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter;
class gp_Lin2d;
class IntRes2d_Domain;
class gp_Circ2d;
class gp_Elips2d;
class gp_Parab2d;
class gp_Hypr2d;



class Geom2dInt_TheIntConicCurveOfGInter  : public IntRes2d_Intersection {
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

  
      Geom2dInt_TheIntConicCurveOfGInter();
  
      Geom2dInt_TheIntConicCurveOfGInter(const gp_Lin2d& L,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol);
  
  Standard_EXPORT   Geom2dInt_TheIntConicCurveOfGInter(const gp_Circ2d& C,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol);
  
  Standard_EXPORT   Geom2dInt_TheIntConicCurveOfGInter(const gp_Elips2d& E,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol);
  
  Standard_EXPORT   Geom2dInt_TheIntConicCurveOfGInter(const gp_Parab2d& Prb,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol);
  
  Standard_EXPORT   Geom2dInt_TheIntConicCurveOfGInter(const gp_Hypr2d& H,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol);
  
        void Perform(const gp_Lin2d& L,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol) ;
  
        void Perform(const gp_Circ2d& C,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol) ;
  
        void Perform(const gp_Elips2d& E,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol) ;
  
        void Perform(const gp_Parab2d& Prb,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol) ;
  
        void Perform(const gp_Hypr2d& H,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol) ;





protected:





private:

  
        void Perform(const IntCurve_IConicTool& ICurve,const IntRes2d_Domain& D1,const Adaptor2d_Curve2d& PCurve,const IntRes2d_Domain& D2,const Standard_Real TolConf,const Standard_Real Tol) ;




};

#define TheImpTool IntCurve_IConicTool
#define TheImpTool_hxx <IntCurve_IConicTool.hxx>
#define ThePCurve Adaptor2d_Curve2d
#define ThePCurve_hxx <Adaptor2d_Curve2d.hxx>
#define ThePCurveTool Geom2dInt_Geom2dCurveTool
#define ThePCurveTool_hxx <Geom2dInt_Geom2dCurveTool.hxx>
#define TheProjPCur Geom2dInt_TheProjPCurOfGInter
#define TheProjPCur_hxx <Geom2dInt_TheProjPCurOfGInter.hxx>
#define IntCurve_TheIntersector Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter
#define IntCurve_TheIntersector_hxx <Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.hxx>
#define IntCurve_MyImpParToolOfTheIntersector Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter
#define IntCurve_MyImpParToolOfTheIntersector_hxx <Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.hxx>
#define IntCurve_MyImpParToolOfTheIntersector Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter
#define IntCurve_MyImpParToolOfTheIntersector_hxx <Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.hxx>
#define IntCurve_IntConicCurveGen Geom2dInt_TheIntConicCurveOfGInter
#define IntCurve_IntConicCurveGen_hxx <Geom2dInt_TheIntConicCurveOfGInter.hxx>

#include <IntCurve_IntConicCurveGen.lxx>

#undef TheImpTool
#undef TheImpTool_hxx
#undef ThePCurve
#undef ThePCurve_hxx
#undef ThePCurveTool
#undef ThePCurveTool_hxx
#undef TheProjPCur
#undef TheProjPCur_hxx
#undef IntCurve_TheIntersector
#undef IntCurve_TheIntersector_hxx
#undef IntCurve_MyImpParToolOfTheIntersector
#undef IntCurve_MyImpParToolOfTheIntersector_hxx
#undef IntCurve_MyImpParToolOfTheIntersector
#undef IntCurve_MyImpParToolOfTheIntersector_hxx
#undef IntCurve_IntConicCurveGen
#undef IntCurve_IntConicCurveGen_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
