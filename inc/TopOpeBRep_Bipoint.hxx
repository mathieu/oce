// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopOpeBRep_Bipoint_HeaderFile
#define _TopOpeBRep_Bipoint_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif



class TopOpeBRep_Bipoint  {
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

  
  Standard_EXPORT   TopOpeBRep_Bipoint();
  
  Standard_EXPORT   TopOpeBRep_Bipoint(const Standard_Integer I1,const Standard_Integer I2);
  
  Standard_EXPORT     Standard_Integer I1() const;
  
  Standard_EXPORT     Standard_Integer I2() const;





protected:





private:



Standard_Integer myI1;
Standard_Integer myI2;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
