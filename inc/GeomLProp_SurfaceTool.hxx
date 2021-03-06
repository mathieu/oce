// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GeomLProp_SurfaceTool_HeaderFile
#define _GeomLProp_SurfaceTool_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_Geom_Surface_HeaderFile
#include <Handle_Geom_Surface.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Geom_Surface;
class gp_Pnt;
class gp_Vec;



class GeomLProp_SurfaceTool  {
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

  //! Computes the point <P> of parameter <U> and <V> on the <br>
//!          Surface <S>. <br>
  Standard_EXPORT   static  void Value(const Handle(Geom_Surface)& S,const Standard_Real U,const Standard_Real V,gp_Pnt& P) ;
  //! Computes the point <P> and first derivative <D1*> of <br>
//!          parameter <U> and <V> on the Surface <S>. <br>
  Standard_EXPORT   static  void D1(const Handle(Geom_Surface)& S,const Standard_Real U,const Standard_Real V,gp_Pnt& P,gp_Vec& D1U,gp_Vec& D1V) ;
  //! Computes the point <P>, the first derivative <D1*> and second <br>
//!          derivative <D2*> of parameter <U> and <V> on the Surface <S>. <br>
  Standard_EXPORT   static  void D2(const Handle(Geom_Surface)& S,const Standard_Real U,const Standard_Real V,gp_Pnt& P,gp_Vec& D1U,gp_Vec& D1V,gp_Vec& D2U,gp_Vec& D2V,gp_Vec& DUV) ;
  
  Standard_EXPORT   static  gp_Vec DN(const Handle(Geom_Surface)& S,const Standard_Real U,const Standard_Real V,const Standard_Integer IU,const Standard_Integer IV) ;
  //! returns the order of continuity of the Surface <S>. <br>
//!          returns 1 : first derivative only is computable <br>
//!          returns 2 : first and second derivative only are computable. <br>
  Standard_EXPORT   static  Standard_Integer Continuity(const Handle(Geom_Surface)& S) ;
  //! returns the bounds of the Surface. <br>
  Standard_EXPORT   static  void Bounds(const Handle(Geom_Surface)& S,Standard_Real& U1,Standard_Real& V1,Standard_Real& U2,Standard_Real& V2) ;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
