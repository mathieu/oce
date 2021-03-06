// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ExprIntrp_StackOfNames_HeaderFile
#define _ExprIntrp_StackOfNames_HeaderFile

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
#ifndef _Handle_ExprIntrp_StackNodeOfStackOfNames_HeaderFile
#include <Handle_ExprIntrp_StackNodeOfStackOfNames.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoSuchObject;
class ExprIntrp_StackIteratorOfStackOfNames;
class TCollection_AsciiString;
class ExprIntrp_StackNodeOfStackOfNames;



class ExprIntrp_StackOfNames  {
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

  
  Standard_EXPORT   ExprIntrp_StackOfNames();
  
  Standard_EXPORT    const ExprIntrp_StackOfNames& Assign(const ExprIntrp_StackOfNames& Other) ;
   const ExprIntrp_StackOfNames& operator =(const ExprIntrp_StackOfNames& Other) 
{
  return Assign(Other);
}
  
        Standard_Boolean IsEmpty() const;
  
        Standard_Integer Depth() const;
  
  Standard_EXPORT    const TCollection_AsciiString& Top() const;
  
  Standard_EXPORT     void Push(const TCollection_AsciiString& I) ;
  
  Standard_EXPORT     void Pop() ;
  
  Standard_EXPORT     void Clear() ;
~ExprIntrp_StackOfNames()
{
  Clear();
}
  
  Standard_EXPORT     TCollection_AsciiString& ChangeTop() ;


friend class ExprIntrp_StackIteratorOfStackOfNames;



protected:





private:

  
  Standard_EXPORT   ExprIntrp_StackOfNames(const ExprIntrp_StackOfNames& Other);


Standard_Address myTop;
Standard_Integer myDepth;


};

#define Item TCollection_AsciiString
#define Item_hxx <TCollection_AsciiString.hxx>
#define TCollection_StackNode ExprIntrp_StackNodeOfStackOfNames
#define TCollection_StackNode_hxx <ExprIntrp_StackNodeOfStackOfNames.hxx>
#define TCollection_StackIterator ExprIntrp_StackIteratorOfStackOfNames
#define TCollection_StackIterator_hxx <ExprIntrp_StackIteratorOfStackOfNames.hxx>
#define Handle_TCollection_StackNode Handle_ExprIntrp_StackNodeOfStackOfNames
#define TCollection_StackNode_Type_() ExprIntrp_StackNodeOfStackOfNames_Type_()
#define TCollection_Stack ExprIntrp_StackOfNames
#define TCollection_Stack_hxx <ExprIntrp_StackOfNames.hxx>

#include <TCollection_Stack.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_StackNode
#undef TCollection_StackNode_hxx
#undef TCollection_StackIterator
#undef TCollection_StackIterator_hxx
#undef Handle_TCollection_StackNode
#undef TCollection_StackNode_Type_
#undef TCollection_Stack
#undef TCollection_Stack_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
