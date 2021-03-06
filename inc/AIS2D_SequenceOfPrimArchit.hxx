// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS2D_SequenceOfPrimArchit_HeaderFile
#define _AIS2D_SequenceOfPrimArchit_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BaseSequence_HeaderFile
#include <TCollection_BaseSequence.hxx>
#endif
#ifndef _Handle_AIS2D_PrimitiveArchit_HeaderFile
#include <Handle_AIS2D_PrimitiveArchit.hxx>
#endif
#ifndef _Handle_AIS2D_SequenceNodeOfSequenceOfPrimArchit_HeaderFile
#include <Handle_AIS2D_SequenceNodeOfSequenceOfPrimArchit.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_NoSuchObject;
class Standard_OutOfRange;
class AIS2D_PrimitiveArchit;
class AIS2D_SequenceNodeOfSequenceOfPrimArchit;



class AIS2D_SequenceOfPrimArchit  : public TCollection_BaseSequence {
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

  
      AIS2D_SequenceOfPrimArchit();
  
  Standard_EXPORT     void Clear() ;
~AIS2D_SequenceOfPrimArchit()
{
  Clear();
}
  
  Standard_EXPORT    const AIS2D_SequenceOfPrimArchit& Assign(const AIS2D_SequenceOfPrimArchit& Other) ;
   const AIS2D_SequenceOfPrimArchit& operator =(const AIS2D_SequenceOfPrimArchit& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void Append(const Handle(AIS2D_PrimitiveArchit)& T) ;
  
        void Append(AIS2D_SequenceOfPrimArchit& S) ;
  
  Standard_EXPORT     void Prepend(const Handle(AIS2D_PrimitiveArchit)& T) ;
  
        void Prepend(AIS2D_SequenceOfPrimArchit& S) ;
  
        void InsertBefore(const Standard_Integer Index,const Handle(AIS2D_PrimitiveArchit)& T) ;
  
        void InsertBefore(const Standard_Integer Index,AIS2D_SequenceOfPrimArchit& S) ;
  
  Standard_EXPORT     void InsertAfter(const Standard_Integer Index,const Handle(AIS2D_PrimitiveArchit)& T) ;
  
        void InsertAfter(const Standard_Integer Index,AIS2D_SequenceOfPrimArchit& S) ;
  
  Standard_EXPORT    const Handle_AIS2D_PrimitiveArchit& First() const;
  
  Standard_EXPORT    const Handle_AIS2D_PrimitiveArchit& Last() const;
  
        void Split(const Standard_Integer Index,AIS2D_SequenceOfPrimArchit& Sub) ;
  
  Standard_EXPORT    const Handle_AIS2D_PrimitiveArchit& Value(const Standard_Integer Index) const;
   const Handle_AIS2D_PrimitiveArchit& operator()(const Standard_Integer Index) const
{
  return Value(Index);
}
  
  Standard_EXPORT     void SetValue(const Standard_Integer Index,const Handle(AIS2D_PrimitiveArchit)& I) ;
  
  Standard_EXPORT     Handle_AIS2D_PrimitiveArchit& ChangeValue(const Standard_Integer Index) ;
    Handle_AIS2D_PrimitiveArchit& operator()(const Standard_Integer Index) 
{
  return ChangeValue(Index);
}
  
  Standard_EXPORT     void Remove(const Standard_Integer Index) ;
  
  Standard_EXPORT     void Remove(const Standard_Integer FromIndex,const Standard_Integer ToIndex) ;





protected:





private:

  
  Standard_EXPORT   AIS2D_SequenceOfPrimArchit(const AIS2D_SequenceOfPrimArchit& Other);




};

#define SeqItem Handle_AIS2D_PrimitiveArchit
#define SeqItem_hxx <AIS2D_PrimitiveArchit.hxx>
#define TCollection_SequenceNode AIS2D_SequenceNodeOfSequenceOfPrimArchit
#define TCollection_SequenceNode_hxx <AIS2D_SequenceNodeOfSequenceOfPrimArchit.hxx>
#define Handle_TCollection_SequenceNode Handle_AIS2D_SequenceNodeOfSequenceOfPrimArchit
#define TCollection_SequenceNode_Type_() AIS2D_SequenceNodeOfSequenceOfPrimArchit_Type_()
#define TCollection_Sequence AIS2D_SequenceOfPrimArchit
#define TCollection_Sequence_hxx <AIS2D_SequenceOfPrimArchit.hxx>

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
