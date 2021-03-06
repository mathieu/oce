// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOP_Draw_HeaderFile
#define _BOP_Draw_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class TopTools_ListOfShape;
class TopoDS_Face;
class TopoDS_Edge;



//!  auxiliary class to display intermediate results <br>
//!  in  Draw's winowds for the debugging purposes <br>
//! <br>
class BOP_Draw  {
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

  
//! Display in  3D-view shapes from the ListOfShape  <aList> <br>
//! aName is base name of shape. Actual name for  each <br>
//! subsequent shape  will  be  aName+"_#",  where <br>
//! # - is ordered index of the shape in <aList> <br>
  Standard_EXPORT   static  void DrawListOfShape(const TopTools_ListOfShape& aList,const Standard_CString aName) ;
  
//! Display in  2D-view the edges from the ListOfShape  <aList>, <br>
//! that have P-curves for  the face <aFace> <br>
//! aName is base name of shape. Actual name for  each <br>
//! subsequent shape  will  be  aName+"_#",  where <br>
//! # -  is ordered index of the shape in <aList> <br>
  Standard_EXPORT   static  void DrawListOfEdgesWithPC(const TopoDS_Face& aFace,const TopTools_ListOfShape& aList,const Standard_CString aName) ;
  
//! Display in  2D-view the edges from the ListOfShape  <aList>, <br>
//! that have P-curves for  the face <aFace> <br>
//! aName is base name of shape. Actual name for  each <br>
//! shape  will  be  aName+"_anInd" <br>
  Standard_EXPORT   static  void DrawListOfEdgesWithPC(const TopoDS_Face& aFace,const TopTools_ListOfShape& aList,const Standard_Integer anInd,const Standard_CString aName) ;
  
//! Display in  2D-view the edge, <br>
//! that has  P-curve for  the face <aFace> <br>
//! aName is the name of shape. <br>
  Standard_EXPORT   static  void DrawEdgeWithPC(const TopoDS_Face& aFace,const TopoDS_Edge& aEdge,const Standard_CString aName) ;
  
//! Wait  for  user's keystroke <br>
  Standard_EXPORT   static  void Wait() ;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
