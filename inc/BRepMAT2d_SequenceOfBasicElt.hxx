// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepMAT2d_SequenceOfBasicElt_HeaderFile
#define _BRepMAT2d_SequenceOfBasicElt_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BaseSequence_HeaderFile
#include <TCollection_BaseSequence.hxx>
#endif
#ifndef _Handle_MAT_BasicElt_HeaderFile
#include <Handle_MAT_BasicElt.hxx>
#endif
#ifndef _Handle_BRepMAT2d_SequenceNodeOfSequenceOfBasicElt_HeaderFile
#include <Handle_BRepMAT2d_SequenceNodeOfSequenceOfBasicElt.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_NoSuchObject;
class Standard_OutOfRange;
class MAT_BasicElt;
class BRepMAT2d_SequenceNodeOfSequenceOfBasicElt;



class BRepMAT2d_SequenceOfBasicElt  : public TCollection_BaseSequence {
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

  
      BRepMAT2d_SequenceOfBasicElt();
  
  Standard_EXPORT     void Clear() ;
~BRepMAT2d_SequenceOfBasicElt()
{
  Clear();
}
  
  Standard_EXPORT    const BRepMAT2d_SequenceOfBasicElt& Assign(const BRepMAT2d_SequenceOfBasicElt& Other) ;
   const BRepMAT2d_SequenceOfBasicElt& operator =(const BRepMAT2d_SequenceOfBasicElt& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void Append(const Handle(MAT_BasicElt)& T) ;
  
        void Append(BRepMAT2d_SequenceOfBasicElt& S) ;
  
  Standard_EXPORT     void Prepend(const Handle(MAT_BasicElt)& T) ;
  
        void Prepend(BRepMAT2d_SequenceOfBasicElt& S) ;
  
        void InsertBefore(const Standard_Integer Index,const Handle(MAT_BasicElt)& T) ;
  
        void InsertBefore(const Standard_Integer Index,BRepMAT2d_SequenceOfBasicElt& S) ;
  
  Standard_EXPORT     void InsertAfter(const Standard_Integer Index,const Handle(MAT_BasicElt)& T) ;
  
        void InsertAfter(const Standard_Integer Index,BRepMAT2d_SequenceOfBasicElt& S) ;
  
  Standard_EXPORT    const Handle_MAT_BasicElt& First() const;
  
  Standard_EXPORT    const Handle_MAT_BasicElt& Last() const;
  
        void Split(const Standard_Integer Index,BRepMAT2d_SequenceOfBasicElt& Sub) ;
  
  Standard_EXPORT    const Handle_MAT_BasicElt& Value(const Standard_Integer Index) const;
   const Handle_MAT_BasicElt& operator()(const Standard_Integer Index) const
{
  return Value(Index);
}
  
  Standard_EXPORT     void SetValue(const Standard_Integer Index,const Handle(MAT_BasicElt)& I) ;
  
  Standard_EXPORT     Handle_MAT_BasicElt& ChangeValue(const Standard_Integer Index) ;
    Handle_MAT_BasicElt& operator()(const Standard_Integer Index) 
{
  return ChangeValue(Index);
}
  
  Standard_EXPORT     void Remove(const Standard_Integer Index) ;
  
  Standard_EXPORT     void Remove(const Standard_Integer FromIndex,const Standard_Integer ToIndex) ;





protected:





private:

  
  Standard_EXPORT   BRepMAT2d_SequenceOfBasicElt(const BRepMAT2d_SequenceOfBasicElt& Other);




};

#define SeqItem Handle_MAT_BasicElt
#define SeqItem_hxx <MAT_BasicElt.hxx>
#define TCollection_SequenceNode BRepMAT2d_SequenceNodeOfSequenceOfBasicElt
#define TCollection_SequenceNode_hxx <BRepMAT2d_SequenceNodeOfSequenceOfBasicElt.hxx>
#define Handle_TCollection_SequenceNode Handle_BRepMAT2d_SequenceNodeOfSequenceOfBasicElt
#define TCollection_SequenceNode_Type_() BRepMAT2d_SequenceNodeOfSequenceOfBasicElt_Type_()
#define TCollection_Sequence BRepMAT2d_SequenceOfBasicElt
#define TCollection_Sequence_hxx <BRepMAT2d_SequenceOfBasicElt.hxx>

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
