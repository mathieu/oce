// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GraphTools_RGNode_HeaderFile
#define _GraphTools_RGNode_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TColStd_SequenceOfInteger_HeaderFile
#include <TColStd_SequenceOfInteger.hxx>
#endif
#ifndef _Handle_GraphTools_SC_HeaderFile
#include <Handle_GraphTools_SC.hxx>
#endif
class GraphTools_SC;



class GraphTools_RGNode  {
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

  
  Standard_EXPORT   GraphTools_RGNode();
  
  Standard_EXPORT     void Reset() ;
  
  Standard_EXPORT     void SetVisited(const Standard_Integer v) ;
  
  Standard_EXPORT     Standard_Integer GetVisited() const;
  
  Standard_EXPORT     void AddAdj(const Standard_Integer adj) ;
  
  Standard_EXPORT     Standard_Integer NbAdj() const;
  
  Standard_EXPORT     Standard_Integer GetAdj(const Standard_Integer index) const;
  
  Standard_EXPORT     void SetSC(const Handle(GraphTools_SC)& SC) ;
  
  Standard_EXPORT     Handle_GraphTools_SC GetSC() const;





protected:





private:



Standard_Integer visited;
TColStd_SequenceOfInteger myAdj;
Handle_GraphTools_SC mySC;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
