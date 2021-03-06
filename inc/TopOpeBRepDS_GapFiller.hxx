// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopOpeBRepDS_GapFiller_HeaderFile
#define _TopOpeBRepDS_GapFiller_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_TopOpeBRepDS_HDataStructure_HeaderFile
#include <Handle_TopOpeBRepDS_HDataStructure.hxx>
#endif
#ifndef _Handle_TopOpeBRepDS_GapTool_HeaderFile
#include <Handle_TopOpeBRepDS_GapTool.hxx>
#endif
#ifndef _Handle_TopOpeBRepDS_Association_HeaderFile
#include <Handle_TopOpeBRepDS_Association.hxx>
#endif
#ifndef _Handle_TopOpeBRepDS_Interference_HeaderFile
#include <Handle_TopOpeBRepDS_Interference.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class TopOpeBRepDS_HDataStructure;
class TopOpeBRepDS_GapTool;
class TopOpeBRepDS_Association;
class TopOpeBRepDS_Interference;
class TopOpeBRepDS_ListOfInterference;
class TopoDS_Shape;
class TopoDS_Face;
class TopoDS_Edge;
class TColStd_MapOfInteger;



class TopOpeBRepDS_GapFiller  {
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

  
  Standard_EXPORT   TopOpeBRepDS_GapFiller(const Handle(TopOpeBRepDS_HDataStructure)& HDS);
  
  Standard_EXPORT     void Perform() ;
  //! Recherche parmi  l'ensemble  des points  d'Interference <br>
//!          la Liste <LI> des points qui correspondent au point d'indice <Index> <br>
  Standard_EXPORT     void FindAssociatedPoints(const Handle(TopOpeBRepDS_Interference)& I,TopOpeBRepDS_ListOfInterference& LI) ;
  //!Enchaine les sections   via  les points d'Interferences  deja <br>
//!         associe; Renvoit  dans   <L> les points extremites des Lignes. <br>//! Methodes pour  construire la liste des Points qui <br>
//!          peuvent correspondre a une Point donne. <br>
  Standard_EXPORT     Standard_Boolean CheckConnexity(TopOpeBRepDS_ListOfInterference& LI) ;
  
  Standard_EXPORT     void AddPointsOnShape(const TopoDS_Shape& S,TopOpeBRepDS_ListOfInterference& LI) ;
  //!  Methodes pour  reduire la liste des Points qui <br>
//!          peuvent correspondre a une Point donne. <br>
  Standard_EXPORT     void AddPointsOnConnexShape(const TopoDS_Shape& F,const TopOpeBRepDS_ListOfInterference& LI) ;
  
  Standard_EXPORT     void FilterByFace(const TopoDS_Face& F,TopOpeBRepDS_ListOfInterference& LI) ;
  
  Standard_EXPORT     void FilterByEdge(const TopoDS_Edge& E,TopOpeBRepDS_ListOfInterference& LI) ;
  
  Standard_EXPORT     void FilterByIncidentDistance(const TopoDS_Face& F,const Handle(TopOpeBRepDS_Interference)& I,TopOpeBRepDS_ListOfInterference& LI) ;
  //! Return TRUE si I a ete obtenu par une intersection <br>
//!          avec <F>. <br>
  Standard_EXPORT     Standard_Boolean IsOnFace(const Handle(TopOpeBRepDS_Interference)& I,const TopoDS_Face& F) const;
  //! Return TRUE  si I ou une  de  ses representaions a <br>
//!          pour support <E>. <br>//! Methodes de  reconstructions des  geometries des point <br>
//!          et des courbes de section <br>
  Standard_EXPORT     Standard_Boolean IsOnEdge(const Handle(TopOpeBRepDS_Interference)& I,const TopoDS_Edge& E) const;
  
  Standard_EXPORT     void BuildNewGeometries() ;
  
  Standard_EXPORT     void ReBuildGeom(const Handle(TopOpeBRepDS_Interference)& I1,TColStd_MapOfInteger& Done) ;





protected:





private:



Handle_TopOpeBRepDS_HDataStructure myHDS;
Handle_TopOpeBRepDS_GapTool myGapTool;
Handle_TopOpeBRepDS_Association myAsso;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
