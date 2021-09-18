
#ifndef _RFPS_DTYPES_H_
#define _RFPS_DTYPES_H_


#ifndef Char  // char
  typedef char Char;
#endif  // Char

#ifndef UChar  // unsigned char
  typedef unsigned char UChar;
#endif  // UChar


#ifndef Int8  // char
  typedef char Int8;
#endif // Int8

#ifndef UInt8  // unsigned char
  typedef unsigned char UInt8;
#endif // UInt8


/* CASM_BOOL datatype */
#ifndef CASM_BOOL

  typedef UChar CASM_BOOL;  // boolean

  #define CASM_TRUE  1U      // true
  #define CASM_FALSE 0U      // false
#endif // CASM_BOOL


#ifndef CChar  // const char
  typedef const char CChar;
#endif  // CChar


#ifndef Int16  // signed short (2 bytes)
  typedef signed short Int16;
#endif // Int16


#ifndef CInt16  // signed short (2 bytes)
  typedef const signed short CInt16;
#endif // Int16


#ifndef UInt16  // unsigned short (2 bytes)
  typedef unsigned short UInt16;
#endif // UInt16


#ifndef Int32  // signed integer (4 bytes)
  typedef signed int Int32;
#endif // Int32


#ifndef CInt32  // const signed integer (4 bytes)
  typedef const signed int CInt32;
#endif // Int32


#ifndef UInt32 // unsigned integer (4 bytes)
  typedef unsigned int UInt32;
#endif


#ifndef Int64 // long (8 bytes)
  typedef long Int64;
#endif // Int64


#ifndef UInt64 // long (8 bytes)
  typedef unsigned long UInt64;
#endif // UInt64


#ifndef Dbl // double (8 bytes)
  typedef double Dbl;
#endif // CDbl


#ifndef CDbl  // const double (8 bytes)
  typedef const Dbl CDbl;
#endif // CDbl

#ifndef Float  // const float (8 bytes)
  typedef float Float;
#endif // CDbl

#endif  // _RFPS_DTYPES_H_
