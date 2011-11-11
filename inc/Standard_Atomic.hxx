// File:    Standard_Atomic.hxx
// Created: Tue Sep 04 08:52:43 2007
// Author:  Andrey BETENEV

//! @file 
//! Implementation of some atomic operations (elementary operations 
//! with data that cannot be interrupted by parallel threads in the
//! multithread process) on various platforms
//!
//! By the moment, only operations necessary for reference counter 
//! in Standard_Transient objects are implemented.
//! 
//! Currently only two x86-based configurations (Windows NT with 
//! MS VC++ compiler and Linix with GCC) are really supported.
//! Other configurations use non-atomic C equivalent.

//! @fn     void Standard_Atomic_Increment (int volatile* var)
//! @brief  Increments atomically integer variable pointed by var

//! @fn     int Standard_Atomic_DecrementTest (int volatile* var)
//! @brief  Decrements atomically integer variable pointed by var;
//!         returns 1 if result is zero, 0 otherwise

//===================================================
// Windows NT, MSVC++ compiler
//===================================================

#if defined(_MSC_VER) || defined(__BORLANDC__)
#ifdef __BORLANDC__
extern "C" {
  __declspec(dllimport) long __stdcall InterlockedIncrement ( long volatile *lpAddend);
  __declspec(dllimport) long __stdcall InterlockedDecrement ( long volatile *lpAddend);
 }
 #define _InterlockedIncrement InterlockedIncrement
 #define _InterlockedDecrement InterlockedDecrement
#elif defined(_MSC_VER)
 extern "C" {
  long _InterlockedIncrement(long volatile* lpAddend);
  long _InterlockedDecrement(long volatile* lpAddend);
 }
# pragma intrinsic (_InterlockedIncrement)
# pragma intrinsic (_InterlockedDecrement)
#endif

inline void Standard_Atomic_Increment (int volatile* var)
{
  _InterlockedIncrement (reinterpret_cast<long volatile*>(var));
}

inline int Standard_Atomic_DecrementTest (int volatile* var)
{
  return _InterlockedDecrement (reinterpret_cast<long volatile*>(var)) == 0;
}

//===================================================
// GCC compiler on x86 or x86_64
// Note: Linux kernel 2.6x provides definitions for atomic operators
//       in the header file /usr/include/asm/atomic.h,
//       however these definitions involve specific type atomic_t
// Note: The same code probably would work for Intel compiler
//===================================================
#elif defined(__GNUG__) && (defined(__i386) || defined(__x86_64))

inline void Standard_Atomic_Increment (int volatile* var)
{
  // C equivalent:
  // ++(*var);

  __asm__ __volatile__
  (
    "lock incl %0"
  : "=m"(*var) // out
  : "m" (*var) // in 
  );
}

inline int Standard_Atomic_DecrementTest (int volatile* var)
{
  // C equivalent:
  // return --(*var) == 0;

  unsigned char c;
  __asm__ __volatile__
  (
    "lock decl %0; sete %1"
  : "=m"(*var), "=qm"(c) // out
  : "m" (*var)           // in
  : "memory"
  );
  return c != 0;
}

//===================================================
// GCC extension for atomic operations
// http://gcc.gnu.org/wiki/Atomic
//===================================================
#elif defined(__GNUG__) && !defined(__sparc_v9) && !defined(__sparc_v9__) // _Atomic_word is not an int on SPARC V9

#include <ext/atomicity.h>

inline void Standard_Atomic_Increment (int* var)
{
  // C equivalent:
  // ++(*var);

  __gnu_cxx::__atomic_add_dispatch(static_cast<_Atomic_word*>(var), 1);
}

inline int Standard_Atomic_DecrementTest (int* var)
{
  // C equivalent:
  // return --(*var) == 0;

  return __gnu_cxx::__exchange_and_add_dispatch(static_cast<_Atomic_word*>(var),-1) == 1;
}

//===================================================
// Default stub implementation, not atomic actually
//===================================================
#else

inline void Standard_Atomic_Increment (int volatile* var)
{
  ++(*var);
}

inline int Standard_Atomic_DecrementTest (int volatile* var)
{
  return --(*var) == 0;
}

#endif
