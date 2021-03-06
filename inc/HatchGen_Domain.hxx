// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _HatchGen_Domain_HeaderFile
#define _HatchGen_Domain_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _HatchGen_PointOnHatching_HeaderFile
#include <HatchGen_PointOnHatching.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_DomainError;
class HatchGen_PointOnHatching;



class HatchGen_Domain  {
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

  //! Creates an infinite domain. <br>
  Standard_EXPORT   HatchGen_Domain();
  //! Creates a domain for the curve associated to a hatching. <br>
  Standard_EXPORT   HatchGen_Domain(const HatchGen_PointOnHatching& P1,const HatchGen_PointOnHatching& P2);
  //! Creates a semi-infinite domain for the curve associated <br>
//!          to a hatching. The `First' flag means that the given <br>
//!          point is the first one. <br>
  Standard_EXPORT   HatchGen_Domain(const HatchGen_PointOnHatching& P,const Standard_Boolean First);
  //! Sets the first and the second points of the domain. <br>
        void SetPoints(const HatchGen_PointOnHatching& P1,const HatchGen_PointOnHatching& P2) ;
  //! Sets the first and the second points of the domain <br>
//!          as the infinite. <br>
        void SetPoints() ;
  //! Sets the first point of the domain. <br>
        void SetFirstPoint(const HatchGen_PointOnHatching& P) ;
  //! Sets the first point of the domain at the <br>
//!          infinite. <br>
        void SetFirstPoint() ;
  //! Sets the second point of the domain. <br>
        void SetSecondPoint(const HatchGen_PointOnHatching& P) ;
  //! Sets the second point of the domain at the <br>
//!          infinite. <br>
        void SetSecondPoint() ;
  //! Returns True if the domain has a first point. <br>
        Standard_Boolean HasFirstPoint() const;
  //! Returns the first point of the domain. <br>
//!          The exception DomainError is raised if <br>
//!          HasFirstPoint returns False. <br>
       const HatchGen_PointOnHatching& FirstPoint() const;
  //! Returns True if the domain has a second point. <br>
        Standard_Boolean HasSecondPoint() const;
  //! Returns the second point of the domain. <br>
//!          The exception DomainError is raised if <br>
//!          HasSecondPoint returns False. <br>
       const HatchGen_PointOnHatching& SecondPoint() const;
  //! Dump of the domain. <br>
  Standard_EXPORT     void Dump(const Standard_Integer Index = 0) const;





protected:





private:



Standard_Boolean myHasFirstPoint;
HatchGen_PointOnHatching myFirstPoint;
Standard_Boolean myHasSecondPoint;
HatchGen_PointOnHatching mySecondPoint;


};


#include <HatchGen_Domain.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
