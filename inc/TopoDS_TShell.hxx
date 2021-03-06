// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopoDS_TShell_HeaderFile
#define _TopoDS_TShell_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_TopoDS_TShell_HeaderFile
#include <Handle_TopoDS_TShell.hxx>
#endif

#ifndef _TopoDS_TShape_HeaderFile
#include <TopoDS_TShape.hxx>
#endif
#ifndef _TopAbs_ShapeEnum_HeaderFile
#include <TopAbs_ShapeEnum.hxx>
#endif
#ifndef _Handle_TopoDS_TShape_HeaderFile
#include <Handle_TopoDS_TShape.hxx>
#endif
class TopoDS_TShape;



class TopoDS_TShell : public TopoDS_TShape {

public:

  //! Creates an empty TShell. <br>
      TopoDS_TShell();
  //! Returns SHELL. <br>
  Standard_EXPORT     TopAbs_ShapeEnum ShapeType() const;
  //! Returns an empty TShell. <br>
  Standard_EXPORT     Handle_TopoDS_TShape EmptyCopy() const;




  DEFINE_STANDARD_RTTI(TopoDS_TShell)

protected:




private: 




};


#include <TopoDS_TShell.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
