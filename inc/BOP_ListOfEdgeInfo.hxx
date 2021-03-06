// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOP_ListOfEdgeInfo_HeaderFile
#define _BOP_ListOfEdgeInfo_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Handle_BOP_ListNodeOfListOfEdgeInfo_HeaderFile
#include <Handle_BOP_ListNodeOfListOfEdgeInfo.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoSuchObject;
class BOP_ListIteratorOfListOfEdgeInfo;
class BOP_EdgeInfo;
class BOP_ListNodeOfListOfEdgeInfo;



class BOP_ListOfEdgeInfo  {
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

  
  Standard_EXPORT   BOP_ListOfEdgeInfo();
  
  Standard_EXPORT     void Assign(const BOP_ListOfEdgeInfo& Other) ;
    void operator=(const BOP_ListOfEdgeInfo& Other) 
{
  Assign(Other);
}
  
  Standard_EXPORT     Standard_Integer Extent() const;
  
  Standard_EXPORT     void Clear() ;
~BOP_ListOfEdgeInfo()
{
  Clear();
}
  
        Standard_Boolean IsEmpty() const;
  
  Standard_EXPORT     void Prepend(const BOP_EdgeInfo& I) ;
  
  Standard_EXPORT     void Prepend(const BOP_EdgeInfo& I,BOP_ListIteratorOfListOfEdgeInfo& theIt) ;
  
  Standard_EXPORT     void Prepend(BOP_ListOfEdgeInfo& Other) ;
  
  Standard_EXPORT     void Append(const BOP_EdgeInfo& I) ;
  
  Standard_EXPORT     void Append(const BOP_EdgeInfo& I,BOP_ListIteratorOfListOfEdgeInfo& theIt) ;
  
  Standard_EXPORT     void Append(BOP_ListOfEdgeInfo& Other) ;
  
  Standard_EXPORT     BOP_EdgeInfo& First() const;
  
  Standard_EXPORT     BOP_EdgeInfo& Last() const;
  
  Standard_EXPORT     void RemoveFirst() ;
  
  Standard_EXPORT     void Remove(BOP_ListIteratorOfListOfEdgeInfo& It) ;
  
  Standard_EXPORT     void InsertBefore(const BOP_EdgeInfo& I,BOP_ListIteratorOfListOfEdgeInfo& It) ;
  
  Standard_EXPORT     void InsertBefore(BOP_ListOfEdgeInfo& Other,BOP_ListIteratorOfListOfEdgeInfo& It) ;
  
  Standard_EXPORT     void InsertAfter(const BOP_EdgeInfo& I,BOP_ListIteratorOfListOfEdgeInfo& It) ;
  
  Standard_EXPORT     void InsertAfter(BOP_ListOfEdgeInfo& Other,BOP_ListIteratorOfListOfEdgeInfo& It) ;


friend class BOP_ListIteratorOfListOfEdgeInfo;



protected:





private:

  
  Standard_EXPORT   BOP_ListOfEdgeInfo(const BOP_ListOfEdgeInfo& Other);


Standard_Address myFirst;
Standard_Address myLast;


};

#define Item BOP_EdgeInfo
#define Item_hxx <BOP_EdgeInfo.hxx>
#define TCollection_ListNode BOP_ListNodeOfListOfEdgeInfo
#define TCollection_ListNode_hxx <BOP_ListNodeOfListOfEdgeInfo.hxx>
#define TCollection_ListIterator BOP_ListIteratorOfListOfEdgeInfo
#define TCollection_ListIterator_hxx <BOP_ListIteratorOfListOfEdgeInfo.hxx>
#define Handle_TCollection_ListNode Handle_BOP_ListNodeOfListOfEdgeInfo
#define TCollection_ListNode_Type_() BOP_ListNodeOfListOfEdgeInfo_Type_()
#define TCollection_List BOP_ListOfEdgeInfo
#define TCollection_List_hxx <BOP_ListOfEdgeInfo.hxx>

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
