// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _HLRBRep_ListOfBPnt2D_HeaderFile
#define _HLRBRep_ListOfBPnt2D_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Handle_HLRBRep_ListNodeOfListOfBPnt2D_HeaderFile
#include <Handle_HLRBRep_ListNodeOfListOfBPnt2D.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoSuchObject;
class HLRBRep_ListIteratorOfListOfBPnt2D;
class HLRBRep_BiPnt2D;
class HLRBRep_ListNodeOfListOfBPnt2D;



class HLRBRep_ListOfBPnt2D  {
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

  
  Standard_EXPORT   HLRBRep_ListOfBPnt2D();
  
  Standard_EXPORT     void Assign(const HLRBRep_ListOfBPnt2D& Other) ;
    void operator=(const HLRBRep_ListOfBPnt2D& Other) 
{
  Assign(Other);
}
  
  Standard_EXPORT     Standard_Integer Extent() const;
  
  Standard_EXPORT     void Clear() ;
~HLRBRep_ListOfBPnt2D()
{
  Clear();
}
  
        Standard_Boolean IsEmpty() const;
  
  Standard_EXPORT     void Prepend(const HLRBRep_BiPnt2D& I) ;
  
  Standard_EXPORT     void Prepend(const HLRBRep_BiPnt2D& I,HLRBRep_ListIteratorOfListOfBPnt2D& theIt) ;
  
  Standard_EXPORT     void Prepend(HLRBRep_ListOfBPnt2D& Other) ;
  
  Standard_EXPORT     void Append(const HLRBRep_BiPnt2D& I) ;
  
  Standard_EXPORT     void Append(const HLRBRep_BiPnt2D& I,HLRBRep_ListIteratorOfListOfBPnt2D& theIt) ;
  
  Standard_EXPORT     void Append(HLRBRep_ListOfBPnt2D& Other) ;
  
  Standard_EXPORT     HLRBRep_BiPnt2D& First() const;
  
  Standard_EXPORT     HLRBRep_BiPnt2D& Last() const;
  
  Standard_EXPORT     void RemoveFirst() ;
  
  Standard_EXPORT     void Remove(HLRBRep_ListIteratorOfListOfBPnt2D& It) ;
  
  Standard_EXPORT     void InsertBefore(const HLRBRep_BiPnt2D& I,HLRBRep_ListIteratorOfListOfBPnt2D& It) ;
  
  Standard_EXPORT     void InsertBefore(HLRBRep_ListOfBPnt2D& Other,HLRBRep_ListIteratorOfListOfBPnt2D& It) ;
  
  Standard_EXPORT     void InsertAfter(const HLRBRep_BiPnt2D& I,HLRBRep_ListIteratorOfListOfBPnt2D& It) ;
  
  Standard_EXPORT     void InsertAfter(HLRBRep_ListOfBPnt2D& Other,HLRBRep_ListIteratorOfListOfBPnt2D& It) ;


friend class HLRBRep_ListIteratorOfListOfBPnt2D;



protected:





private:

  
  Standard_EXPORT   HLRBRep_ListOfBPnt2D(const HLRBRep_ListOfBPnt2D& Other);


Standard_Address myFirst;
Standard_Address myLast;


};

#define Item HLRBRep_BiPnt2D
#define Item_hxx <HLRBRep_BiPnt2D.hxx>
#define TCollection_ListNode HLRBRep_ListNodeOfListOfBPnt2D
#define TCollection_ListNode_hxx <HLRBRep_ListNodeOfListOfBPnt2D.hxx>
#define TCollection_ListIterator HLRBRep_ListIteratorOfListOfBPnt2D
#define TCollection_ListIterator_hxx <HLRBRep_ListIteratorOfListOfBPnt2D.hxx>
#define Handle_TCollection_ListNode Handle_HLRBRep_ListNodeOfListOfBPnt2D
#define TCollection_ListNode_Type_() HLRBRep_ListNodeOfListOfBPnt2D_Type_()
#define TCollection_List HLRBRep_ListOfBPnt2D
#define TCollection_List_hxx <HLRBRep_ListOfBPnt2D.hxx>

#include <TCollection_List.lxx>

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
