// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TNaming_ListIteratorOfListOfMapOfShape_HeaderFile
#define _TNaming_ListIteratorOfListOfMapOfShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Handle_TNaming_ListNodeOfListOfMapOfShape_HeaderFile
#include <Handle_TNaming_ListNodeOfListOfMapOfShape.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoMoreObject;
class Standard_NoSuchObject;
class TNaming_ListOfMapOfShape;
class TopTools_MapOfShape;
class TNaming_ListNodeOfListOfMapOfShape;



class TNaming_ListIteratorOfListOfMapOfShape  {
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

  
  Standard_EXPORT   TNaming_ListIteratorOfListOfMapOfShape();
  
  Standard_EXPORT   TNaming_ListIteratorOfListOfMapOfShape(const TNaming_ListOfMapOfShape& L);
  
  Standard_EXPORT     void Initialize(const TNaming_ListOfMapOfShape& L) ;
  
        Standard_Boolean More() const;
  
  Standard_EXPORT     void Next() ;
  
  Standard_EXPORT     TopTools_MapOfShape& Value() const;


friend class TNaming_ListOfMapOfShape;



protected:





private:



Standard_Address current;
Standard_Address previous;


};

#define Item TopTools_MapOfShape
#define Item_hxx <TopTools_MapOfShape.hxx>
#define TCollection_ListNode TNaming_ListNodeOfListOfMapOfShape
#define TCollection_ListNode_hxx <TNaming_ListNodeOfListOfMapOfShape.hxx>
#define TCollection_ListIterator TNaming_ListIteratorOfListOfMapOfShape
#define TCollection_ListIterator_hxx <TNaming_ListIteratorOfListOfMapOfShape.hxx>
#define Handle_TCollection_ListNode Handle_TNaming_ListNodeOfListOfMapOfShape
#define TCollection_ListNode_Type_() TNaming_ListNodeOfListOfMapOfShape_Type_()
#define TCollection_List TNaming_ListOfMapOfShape
#define TCollection_List_hxx <TNaming_ListOfMapOfShape.hxx>

#include <TCollection_ListIterator.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_ListNode
#undef TCollection_ListNode_hxx
#undef TCollection_ListIterator
#undef TCollection_ListIterator_hxx
#undef Handle_TCollection_ListNode
#undef TCollection_ListNode_Type_
#undef TCollection_List
#undef TCollection_List_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
