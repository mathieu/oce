// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepToTopoDS_DataMapIteratorOfDataMapOfRI_HeaderFile
#define _StepToTopoDS_DataMapIteratorOfDataMapOfRI_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMapIterator_HeaderFile
#include <TCollection_BasicMapIterator.hxx>
#endif
#ifndef _Handle_StepRepr_RepresentationItem_HeaderFile
#include <Handle_StepRepr_RepresentationItem.hxx>
#endif
#ifndef _Handle_StepToTopoDS_DataMapNodeOfDataMapOfRI_HeaderFile
#include <Handle_StepToTopoDS_DataMapNodeOfDataMapOfRI.hxx>
#endif
class Standard_NoSuchObject;
class StepRepr_RepresentationItem;
class TopoDS_Shape;
class TColStd_MapTransientHasher;
class StepToTopoDS_DataMapOfRI;
class StepToTopoDS_DataMapNodeOfDataMapOfRI;



class StepToTopoDS_DataMapIteratorOfDataMapOfRI  : public TCollection_BasicMapIterator {
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

  
  Standard_EXPORT   StepToTopoDS_DataMapIteratorOfDataMapOfRI();
  
  Standard_EXPORT   StepToTopoDS_DataMapIteratorOfDataMapOfRI(const StepToTopoDS_DataMapOfRI& aMap);
  
  Standard_EXPORT     void Initialize(const StepToTopoDS_DataMapOfRI& aMap) ;
  
  Standard_EXPORT    const Handle_StepRepr_RepresentationItem& Key() const;
  
  Standard_EXPORT    const TopoDS_Shape& Value() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
