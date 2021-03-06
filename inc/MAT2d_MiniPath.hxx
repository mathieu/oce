// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _MAT2d_MiniPath_HeaderFile
#define _MAT2d_MiniPath_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _MAT2d_DataMapOfIntegerSequenceOfConnexion_HeaderFile
#include <MAT2d_DataMapOfIntegerSequenceOfConnexion.hxx>
#endif
#ifndef _MAT2d_DataMapOfIntegerConnexion_HeaderFile
#include <MAT2d_DataMapOfIntegerConnexion.hxx>
#endif
#ifndef _MAT2d_SequenceOfConnexion_HeaderFile
#include <MAT2d_SequenceOfConnexion.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_MAT2d_Connexion_HeaderFile
#include <Handle_MAT2d_Connexion.hxx>
#endif
class MAT2d_SequenceOfSequenceOfGeometry;
class MAT2d_SequenceOfConnexion;
class MAT2d_Connexion;


//! MiniPath computes a path to link all the  lines in <br>
//!          a set of lines. The path is described as a  set of <br>
//!          connexions. <br>
//! <br>
//!          The set of connexions can be  seen as an arbitrary Tree. <br>
//!          The node of the  tree are the  lines.  The arcs of the <br>
//!          tree are the connexions.  The ancestror  of  a line is <br>
//!          the connexion which ends on it. The children of a line <br>
//!          are the connexions which start on it. <br>
//! <br>
//!          The children of a line are ordered by the relation <br>
//!          <IsAfter> defined on the connexions. <br>
//!          (See MAT2s_Connexion.cdl). <br>
class MAT2d_MiniPath  {
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

  
  Standard_EXPORT   MAT2d_MiniPath();
  //! Computes the path  to link the  lines in <Figure>. <br>
//!          the path   starts on the  line  of index <IndStart> <br>
//!          <Sense>  = True    if  the Circuit turns in the <br>
//!          trigonometric  sense. <br>
  Standard_EXPORT     void Perform(const MAT2d_SequenceOfSequenceOfGeometry& Figure,const Standard_Integer IndStart,const Standard_Boolean Sense) ;
  //! Run on the set of connexions to compute the path. <br>
//!          the path is an exploration of the tree which contains <br>
//!          the connexions and their reverses. <br>
//!          if the tree of connexions is <br>
//!                  A <br>
//!                 / \ <br>
//!                B   E <br>
//!               / \   \ <br>
//!              C   D   F <br>
//! <br>
//!          the path is A->B, B->C, C->B, B->D, D->B, B->A, A->E, <br>
//!                      E->F, F->E, E->A. <br>
  Standard_EXPORT     void RunOnConnexions() ;
  //! Returns  the  sequence of  connexions corresponding to <br>
//!          the  path. <br>
  Standard_EXPORT    const MAT2d_SequenceOfConnexion& Path() const;
  //! Returns <True> if there is one Connexion which starts <br>
//!          on line designed by <Index>. <br>
  Standard_EXPORT     Standard_Boolean IsConnexionsFrom(const Standard_Integer Index) const;
  //! Returns    the  connexions  which   start  on line <br>
//!          designed  by <Index>. <br>
//! <br>
  Standard_EXPORT     MAT2d_SequenceOfConnexion& ConnexionsFrom(const Standard_Integer Index) ;
  //! Returns <True> if the line designed by <Index> is <br>
//!          the root. <br>
  Standard_EXPORT     Standard_Boolean IsRoot(const Standard_Integer Index) const;
  //! Returns    the  connexion  which ends  on line <br>
//!          designed  by <Index>. <br>
  Standard_EXPORT     Handle_MAT2d_Connexion Father(const Standard_Integer Index) ;





protected:





private:

  //! Add a connexion to the path. <br>
  Standard_EXPORT     void Append(const Handle(MAT2d_Connexion)& Connexion) ;
  
  Standard_EXPORT     void ExploSons(MAT2d_SequenceOfConnexion& aPath,const Handle(MAT2d_Connexion)& aConnexion) ;
  //! Returns the connexion which realises the minimum of <br>
//!          distance between the lines of index <L1> and <L2> in <br>
//!          <aFigure>. The connexion is oriented from <L1> to <L2>. <br>
  Standard_EXPORT     Handle_MAT2d_Connexion MinimumL1L2(const MAT2d_SequenceOfSequenceOfGeometry& Figure,const Standard_Integer L1,const Standard_Integer L2) const;


MAT2d_DataMapOfIntegerSequenceOfConnexion theConnexions;
MAT2d_DataMapOfIntegerConnexion theFather;
MAT2d_SequenceOfConnexion thePath;
Standard_Real theDirection;
Standard_Integer indStart;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
