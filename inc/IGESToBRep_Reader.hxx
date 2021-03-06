// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESToBRep_Reader_HeaderFile
#define _IGESToBRep_Reader_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_IGESData_IGESModel_HeaderFile
#include <Handle_IGESData_IGESModel.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _TopTools_SequenceOfShape_HeaderFile
#include <TopTools_SequenceOfShape.hxx>
#endif
#ifndef _Handle_IGESToBRep_Actor_HeaderFile
#include <Handle_IGESToBRep_Actor.hxx>
#endif
#ifndef _Handle_Transfer_TransientProcess_HeaderFile
#include <Handle_Transfer_TransientProcess.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class IGESData_IGESModel;
class IGESToBRep_Actor;
class Transfer_TransientProcess;
class TopoDS_Shape;


//! A simple way to read geometric IGES data. <br>
//!           Encapsulates reading file and calling transfer tools <br>
class IGESToBRep_Reader  {
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

  //! Creates a Reader <br>
  Standard_EXPORT   IGESToBRep_Reader();
  //! Loads a Model from a file.Returns 0 if success. <br>
//!           returns 1 if the file could not be opened, <br>
//!           returns -1 if an error occurred while the file was being loaded. <br>
  Standard_EXPORT     Standard_Integer LoadFile(const Standard_CString filename) ;
  //! Specifies a Model to work on <br>
//!           Also clears the result and Done status, sets TransientProcess <br>
  Standard_EXPORT     void SetModel(const Handle(IGESData_IGESModel)& model) ;
  //! Returns the Model to be worked on. <br>
  Standard_EXPORT     Handle_IGESData_IGESModel Model() const;
  //! Allows to set an already defined TransientProcess <br>
//!           (to be called after LoadFile or SetModel) <br>
  Standard_EXPORT     void SetTransientProcess(const Handle(Transfer_TransientProcess)& TP) ;
  //! Returns the TransientProcess <br>
  Standard_EXPORT     Handle_Transfer_TransientProcess TransientProcess() const;
  //! Returns "theActor" <br>
  Standard_EXPORT     Handle_IGESToBRep_Actor Actor() const;
  //! Clears the results between two translation operations. <br>
  Standard_EXPORT     void Clear() ;
  //! Checks the IGES file that was <br>
//! loaded into memory. Displays error messages in the default <br>
//! message file if withprint is true. Returns True if no fail <br>
//! message was found and False if there was at least one fail message. <br>
  Standard_EXPORT     Standard_Boolean Check(const Standard_Boolean withprint) const;
  //! Translates root entities in an <br>
//! IGES file. Standard_True is the default value and means that only <br>
//! visible root entities are translated. Standard_False <br>
//! translates all of the roots (visible and invisible). <br>
  Standard_EXPORT     void TransferRoots(const Standard_Boolean onlyvisible = Standard_True) ;
  //! Transfers an Entity given its rank in the Model (Root or not) <br>
//!           Returns True if it is recognized as Geom-Topol. <br>
//!           (But it can have failed : see IsDone) <br>
  Standard_EXPORT     Standard_Boolean Transfer(const Standard_Integer num) ;
  //! Returns True if the LAST Transfer/TransferRoots was a success <br>
  Standard_EXPORT     Standard_Boolean IsDone() const;
  //! Returns the Tolerance which has been actually used, converted <br>
//!           in millimeters <br>
//!          (either that from File or that from Session, according the mode) <br>
  Standard_EXPORT     Standard_Real UsedTolerance() const;
  //! Returns the number of shapes produced by the translation. <br>
  Standard_EXPORT     Standard_Integer NbShapes() const;
  //!  Returns the num the resulting shape in a translation operation. <br>
  Standard_EXPORT     TopoDS_Shape Shape(const Standard_Integer num = 1) const;
  //! Returns all of the results in a <br>
//! single shape which is: <br>
//! - a null shape if there are no results, <br>
//! - a shape if there is one result, <br>
//! - a compound containing the resulting shapes if there are several. <br>
  Standard_EXPORT     TopoDS_Shape OneShape() const;





protected:





private:



Handle_IGESData_IGESModel theModel;
Standard_Boolean theDone;
TopTools_SequenceOfShape theShapes;
Handle_IGESToBRep_Actor theActor;
Handle_Transfer_TransientProcess theProc;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
