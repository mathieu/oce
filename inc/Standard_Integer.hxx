#ifndef _Standard_Integer_HeaderFile
#define _Standard_Integer_HeaderFile

#ifndef _Standard_TypeDef_HeaderFile
#include <Standard_TypeDef.hxx>
#endif

#ifndef _Standard_values_HeaderFile
# include <Standard_values.h>
#endif

class Handle_Standard_Type;

__Standard_API Handle_Standard_Type& Standard_Integer_Type_();
// ===============================================
// Methods from Standard_Entity class which are redefined:  
//    - Hascode
//    - IsEqual
//    - IsSimilar
//    - Shallowcopy
//    - ShallowDump
// ===============================================

// ==================================
// Methods implemeted in Standard_Integer.cxx
// ==================================
__Standard_API Standard_Integer NextPrimeForMap(const Standard_Integer anInt ) ;
__Standard_API long             NextPrime   (const long               me);
__Standard_API Standard_Integer CharToInt   (const Standard_Character me); 
__Standard_API Standard_Integer CharToInt   (const Standard_CString   me); 
__Standard_API Standard_Integer ShallowCopy (const Standard_Integer   me);   
//__Standard_API Standard_Integer HashCode    (const Standard_Integer, const Standard_Integer);

// ===============
// Inline methods
// ===============

// ------------------------------------------------------------------
// Abs : Returns the absolute value of an Integer
// ------------------------------------------------------------------
inline  Standard_Integer Abs (const Standard_Integer Value) 
{ 
  return Value >= 0 ? Value : -Value;
}

// ------------------------------------------------------------------
// Hascode : Computes a hascoding value for a given Integer
// ------------------------------------------------------------------
inline Standard_Integer HashCode(const Standard_Integer me,
			         const Standard_Integer Upper)
{
//   return (Abs(me) % Upper) + 1;
   return ( ( me & 0x7fffffff ) % Upper) + 1;
}

// ------------------------------------------------------------------
// IsEqual : Returns Standard_True if two integers are equal
// ------------------------------------------------------------------
inline Standard_Boolean IsEqual(const Standard_Integer One
			       ,const Standard_Integer Two)
{ return One == Two; }

// ------------------------------------------------------------------
// IsSimilar : Returns Standard_True if two integers are equal
// ------------------------------------------------------------------
inline Standard_Boolean IsSimilar (const Standard_Integer One, 
				   const Standard_Integer Two)
{ return One == Two; }


// ------------------------------------------------------------------
// IsEven : Returns Standard_True if an integer is even
// ------------------------------------------------------------------
inline Standard_Boolean IsEven (const Standard_Integer Value) 
{ return Value % 2 == 0; }


// ------------------------------------------------------------------
// IsOdd : Returns Standard_True if an integer is odd
// ------------------------------------------------------------------
inline Standard_Boolean IsOdd (const Standard_Integer Value) 
{ return Value % 2 == 1; }

// ------------------------------------------------------------------
// Max : Returns the maximum integer between two integers
// ------------------------------------------------------------------
inline Standard_Integer  Max (const Standard_Integer Val1,
			      const Standard_Integer Val2) 
{
  return Val1 >= Val2 ? Val1 : Val2;
}

// ------------------------------------------------------------------
// Min : Returns the minimum integer between two integers
// ------------------------------------------------------------------
inline Standard_Integer  Min (const Standard_Integer Val1, 
			      const Standard_Integer Val2) 
{
  return Val1 <= Val2 ? Val1 : Val2;
}

// ------------------------------------------------------------------
// Modulus : Returns the remainder of division between two integers
// ------------------------------------------------------------------
inline Standard_Integer  Modulus (const Standard_Integer Value, 
				  const Standard_Integer Divisor) 
{ return Value % Divisor; }

// ------------------------------------------------------------------
// Square : Returns the square of an integer
// ------------------------------------------------------------------
inline Standard_Integer Square(const Standard_Integer Value) 
{ return Value * Value; }

// ------------------------------------------------------------------
// IntegerFirst : Returns the minimum value of an integer
// ------------------------------------------------------------------
inline Standard_Integer  IntegerFirst()     
{ return INT_MIN; }

// ------------------------------------------------------------------
// IntegerLast : Returns the maximum value of an integer
// ------------------------------------------------------------------
inline Standard_Integer  IntegerLast()     
{ return INT_MAX; }

// ------------------------------------------------------------------
// IntegerSize : Returns the size in digits of an integer
// ------------------------------------------------------------------
inline Standard_Integer  IntegerSize()     
{ return BITS(Standard_Integer); }

#endif 
