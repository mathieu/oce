// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColStd_ListIteratorOfListOfInteger_HeaderFile
#define _TColStd_ListIteratorOfListOfInteger_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_TColStd_ListNodeOfListOfInteger_HeaderFile
#include <Handle_TColStd_ListNodeOfListOfInteger.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoMoreObject;
class Standard_NoSuchObject;
class TColStd_ListOfInteger;
class TColStd_ListNodeOfListOfInteger;



class TColStd_ListIteratorOfListOfInteger  {
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

  
  Standard_EXPORT   TColStd_ListIteratorOfListOfInteger();
  
  Standard_EXPORT   TColStd_ListIteratorOfListOfInteger(const TColStd_ListOfInteger& L);
  
  Standard_EXPORT     void Initialize(const TColStd_ListOfInteger& L) ;
  
        Standard_Boolean More() const;
  
  Standard_EXPORT     void Next() ;
  
  Standard_EXPORT     Standard_Integer& Value() const;


friend class TColStd_ListOfInteger;



protected:





private:



Standard_Address current;
Standard_Address previous;


};

#define Item Standard_Integer
#define Item_hxx <Standard_Integer.hxx>
#define TCollection_ListNode TColStd_ListNodeOfListOfInteger
#define TCollection_ListNode_hxx <TColStd_ListNodeOfListOfInteger.hxx>
#define TCollection_ListIterator TColStd_ListIteratorOfListOfInteger
#define TCollection_ListIterator_hxx <TColStd_ListIteratorOfListOfInteger.hxx>
#define Handle_TCollection_ListNode Handle_TColStd_ListNodeOfListOfInteger
#define TCollection_ListNode_Type_() TColStd_ListNodeOfListOfInteger_Type_()
#define TCollection_List TColStd_ListOfInteger
#define TCollection_List_hxx <TColStd_ListOfInteger.hxx>

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
