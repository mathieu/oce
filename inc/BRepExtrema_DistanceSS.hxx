// File generated by CPPExt (Value)
//
//                     Copyright (C) 1991 - 2000 by  
//                      Matra Datavision SA.  All rights reserved.
//  
//                     Copyright (C) 2001 - 2004 by
//                     Open CASCADE SA.  All rights reserved.
// 
// This file is part of the Open CASCADE Technology software.
//
// This software may be distributed and/or modified under the terms and
// conditions of the Open CASCADE Public License as defined by Open CASCADE SA
// and appearing in the file LICENSE included in the packaging of this file.
//  
// This software is distributed on an "AS IS" basis, without warranty of any
// kind, and Open CASCADE SA hereby disclaims all such warranties,
// including without limitation, any warranties of merchantability, fitness
// for a particular purpose or non-infringement. Please see the License for
// the specific terms and conditions governing rights and limitations under the
// License.

#ifndef _BRepExtrema_DistanceSS_HeaderFile
#define _BRepExtrema_DistanceSS_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BRepExtrema_SeqOfSolution_HeaderFile
#include <BRepExtrema_SeqOfSolution.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Extrema_ExtFlag_HeaderFile
#include <Extrema_ExtFlag.hxx>
#endif
#ifndef _Extrema_ExtAlgo_HeaderFile
#include <Extrema_ExtAlgo.hxx>
#endif
#ifndef _Precision_HeaderFile
#include <Precision.hxx>
#endif
class TopoDS_Shape;
class Bnd_Box;
class TopoDS_Vertex;
class TopoDS_Edge;
class TopoDS_Face;


//!  This class allows to compute minimum distance between two shapes <br>
//! (face edge vertex) and is used in DistShapeShape class. <br>
class BRepExtrema_DistanceSS
{
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

  //! computes the distance between two Shapes ( face edge vertex). <br>
  Standard_EXPORT BRepExtrema_DistanceSS(const TopoDS_Shape& S1, const TopoDS_Shape& S2,
                                         const Bnd_Box& B1, const Bnd_Box& B2,
                                         const Standard_Real DstRef,
                                         const Extrema_ExtFlag F = Extrema_ExtFlag_MINMAX,
                                         const Extrema_ExtAlgo A = Extrema_ExtAlgo_Grad)
  : myDstRef(DstRef), myModif(Standard_False), myEps(Precision::Confusion()), myFlag(F), myAlgo(A)
  {
    Perform(S1, S2, B1, B2);
  }
  //! computes the distance between two Shapes ( face edge vertex). <br>
  //! Parameter theDeflection is used to specify a maximum deviation <br>
  //! of extreme distances from the minimum one. <br>
  //! Default value is Precision::Confusion(). <br>
  Standard_EXPORT BRepExtrema_DistanceSS(const TopoDS_Shape& S1, const TopoDS_Shape& S2,
                                         const Bnd_Box& B1, const Bnd_Box& B2,
                                         const Standard_Real DstRef, const Standard_Real aDeflection,
                                         const Extrema_ExtFlag F = Extrema_ExtFlag_MINMAX,
                                         const Extrema_ExtAlgo A = Extrema_ExtAlgo_Grad)
  : myDstRef(DstRef), myModif(Standard_False), myEps(aDeflection), myFlag(F), myAlgo(A)
  {
    Perform(S1, S2, B1, B2);
  }
  //! True if the distance has been computed <br>
  Standard_EXPORT Standard_Boolean IsDone() const
  {
    return myModif;
  }
  //! returns the distance value <br>
  Standard_EXPORT Standard_Real DistValue() const
  {
    return myDstRef;
  }
  //! returns the list of solutions on the first shape <br>
  Standard_EXPORT const BRepExtrema_SeqOfSolution& Seq1Value() const
  {
    return SeqSolShape1;
  }
  //! returns the list of solutions on the second shape <br>
  Standard_EXPORT const BRepExtrema_SeqOfSolution& Seq2Value() const
  {
    return SeqSolShape2;
  }
  //! sets the flag controlling minimum and maximum search
  Standard_EXPORT void SetFlag(const Extrema_ExtFlag F)
  {
    myFlag = F;
  }
  //! sets the flag controlling ...
  Standard_EXPORT void SetAlgo(const Extrema_ExtAlgo A)
  {
    myAlgo = A;
  }

 private:

  //! computes the distance between two Shapes ( face edge vertex) <br>
  void Perform(const TopoDS_Shape& S1,const TopoDS_Shape& S2,const Bnd_Box& B1,const Bnd_Box& B2);

  //! computes the distance between two vertices <br>
  void Perform(const TopoDS_Vertex& S1,const TopoDS_Vertex& S2);
  //! computes the minimum distance between a vertex and an edge <br>
  void Perform(const TopoDS_Vertex& S1,const TopoDS_Edge& S2,const Bnd_Box& B1,const Bnd_Box& B2);
  //! computes the minimum distance between a vertex and a face <br>
  void Perform(const TopoDS_Vertex& S1,const TopoDS_Face& S2,const Bnd_Box& B1,const Bnd_Box& B2);

  //! computes the minimum distance between an edge and a vertex <br>
  void Perform(const TopoDS_Edge& S1,const TopoDS_Vertex& S2,const Bnd_Box& B1,const Bnd_Box& B2);
  /*{
    Perform(S2, S1, B2, B1);
  }*/
  //! computes the minimum distance between two edges <br>
  void Perform(const TopoDS_Edge& S1,const TopoDS_Edge& S2,const Bnd_Box& B1,const Bnd_Box& B2);
  //! computes the minimum distance an edge and a face <br>
  void Perform(const TopoDS_Edge& S1,const TopoDS_Face& S2,const Bnd_Box& B1,const Bnd_Box& B2);

  //! computes the minimum distance betwwen a face and a vertex <br>
  void Perform(const TopoDS_Face& S1,const TopoDS_Vertex& S2,const Bnd_Box& B1,const Bnd_Box& B2);
  /*{
    Perform(S2, S1, B2, B1);
  }*/
  //! computes the minimum distance between a face and an edge <br>
  void Perform(const TopoDS_Face& S1,const TopoDS_Edge& S2,const Bnd_Box& B1,const Bnd_Box& B2);
  /*{
    Perform(S2, S1, B2, B1);
  }*/
  //! computes the minimum distance between two faces <br>
  void Perform(const TopoDS_Face& S1,const TopoDS_Face& S2,const Bnd_Box& B1,const Bnd_Box& B2);

  BRepExtrema_SeqOfSolution SeqSolShape1;
  BRepExtrema_SeqOfSolution SeqSolShape2;
  Standard_Real myDstRef;
  Standard_Boolean myModif;
  Standard_Real myEps;
  Extrema_ExtFlag myFlag;
  Extrema_ExtAlgo myAlgo;
};

#endif
