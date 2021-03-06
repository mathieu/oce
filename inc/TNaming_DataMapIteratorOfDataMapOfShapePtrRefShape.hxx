// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TNaming_DataMapIteratorOfDataMapOfShapePtrRefShape_HeaderFile
#define _TNaming_DataMapIteratorOfDataMapOfShapePtrRefShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMapIterator_HeaderFile
#include <TCollection_BasicMapIterator.hxx>
#endif
#ifndef _TNaming_PtrRefShape_HeaderFile
#include <TNaming_PtrRefShape.hxx>
#endif
#ifndef _Handle_TNaming_DataMapNodeOfDataMapOfShapePtrRefShape_HeaderFile
#include <Handle_TNaming_DataMapNodeOfDataMapOfShapePtrRefShape.hxx>
#endif
class Standard_NoSuchObject;
class TopoDS_Shape;
class TopTools_ShapeMapHasher;
class TNaming_DataMapOfShapePtrRefShape;
class TNaming_DataMapNodeOfDataMapOfShapePtrRefShape;



class TNaming_DataMapIteratorOfDataMapOfShapePtrRefShape  : public TCollection_BasicMapIterator {
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

  
  Standard_EXPORT   TNaming_DataMapIteratorOfDataMapOfShapePtrRefShape();
  
  Standard_EXPORT   TNaming_DataMapIteratorOfDataMapOfShapePtrRefShape(const TNaming_DataMapOfShapePtrRefShape& aMap);
  
  Standard_EXPORT     void Initialize(const TNaming_DataMapOfShapePtrRefShape& aMap) ;
  
  Standard_EXPORT    const TopoDS_Shape& Key() const;
  
  Standard_EXPORT    const TNaming_PtrRefShape& Value() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
