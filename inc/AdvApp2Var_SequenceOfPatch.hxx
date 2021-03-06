// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AdvApp2Var_SequenceOfPatch_HeaderFile
#define _AdvApp2Var_SequenceOfPatch_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BaseSequence_HeaderFile
#include <TCollection_BaseSequence.hxx>
#endif
#ifndef _Handle_AdvApp2Var_SequenceNodeOfSequenceOfPatch_HeaderFile
#include <Handle_AdvApp2Var_SequenceNodeOfSequenceOfPatch.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_NoSuchObject;
class Standard_OutOfRange;
class AdvApp2Var_Patch;
class AdvApp2Var_SequenceNodeOfSequenceOfPatch;



class AdvApp2Var_SequenceOfPatch  : public TCollection_BaseSequence {
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

  
      AdvApp2Var_SequenceOfPatch();
  
  Standard_EXPORT     void Clear() ;
~AdvApp2Var_SequenceOfPatch()
{
  Clear();
}
  
  Standard_EXPORT    const AdvApp2Var_SequenceOfPatch& Assign(const AdvApp2Var_SequenceOfPatch& Other) ;
   const AdvApp2Var_SequenceOfPatch& operator =(const AdvApp2Var_SequenceOfPatch& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void Append(const AdvApp2Var_Patch& T) ;
  
        void Append(AdvApp2Var_SequenceOfPatch& S) ;
  
  Standard_EXPORT     void Prepend(const AdvApp2Var_Patch& T) ;
  
        void Prepend(AdvApp2Var_SequenceOfPatch& S) ;
  
        void InsertBefore(const Standard_Integer Index,const AdvApp2Var_Patch& T) ;
  
        void InsertBefore(const Standard_Integer Index,AdvApp2Var_SequenceOfPatch& S) ;
  
  Standard_EXPORT     void InsertAfter(const Standard_Integer Index,const AdvApp2Var_Patch& T) ;
  
        void InsertAfter(const Standard_Integer Index,AdvApp2Var_SequenceOfPatch& S) ;
  
  Standard_EXPORT    const AdvApp2Var_Patch& First() const;
  
  Standard_EXPORT    const AdvApp2Var_Patch& Last() const;
  
        void Split(const Standard_Integer Index,AdvApp2Var_SequenceOfPatch& Sub) ;
  
  Standard_EXPORT    const AdvApp2Var_Patch& Value(const Standard_Integer Index) const;
   const AdvApp2Var_Patch& operator()(const Standard_Integer Index) const
{
  return Value(Index);
}
  
  Standard_EXPORT     void SetValue(const Standard_Integer Index,const AdvApp2Var_Patch& I) ;
  
  Standard_EXPORT     AdvApp2Var_Patch& ChangeValue(const Standard_Integer Index) ;
    AdvApp2Var_Patch& operator()(const Standard_Integer Index) 
{
  return ChangeValue(Index);
}
  
  Standard_EXPORT     void Remove(const Standard_Integer Index) ;
  
  Standard_EXPORT     void Remove(const Standard_Integer FromIndex,const Standard_Integer ToIndex) ;





protected:





private:

  
  Standard_EXPORT   AdvApp2Var_SequenceOfPatch(const AdvApp2Var_SequenceOfPatch& Other);




};

#define SeqItem AdvApp2Var_Patch
#define SeqItem_hxx <AdvApp2Var_Patch.hxx>
#define TCollection_SequenceNode AdvApp2Var_SequenceNodeOfSequenceOfPatch
#define TCollection_SequenceNode_hxx <AdvApp2Var_SequenceNodeOfSequenceOfPatch.hxx>
#define Handle_TCollection_SequenceNode Handle_AdvApp2Var_SequenceNodeOfSequenceOfPatch
#define TCollection_SequenceNode_Type_() AdvApp2Var_SequenceNodeOfSequenceOfPatch_Type_()
#define TCollection_Sequence AdvApp2Var_SequenceOfPatch
#define TCollection_Sequence_hxx <AdvApp2Var_SequenceOfPatch.hxx>

#include <TCollection_Sequence.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
