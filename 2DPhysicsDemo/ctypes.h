#ifndef __C_TYPES_H__
#define __C_TYPES_H__

#include <pmmintrin.h> // SSE3 header

typedef float f32; // float
typedef double f64; // 64bit float

typedef char c8;
typedef unsigned char uc8;

#ifdef _WIN32
typedef __int8 i8;
typedef unsigned __int8 u8;

typedef __int16 i16;
typedef unsigned __int16 u16;

typedef __int32 i32;
typedef unsigned __int32 u32;

typedef __int64 i64;
typedef unsigned __int64 u64;

#else

#include <inttypes.h> // non-windows platforms

typedef int8_t i8;
typedef uint8_t u8;

typedef int16_t i16;
typedef uint16_t u16;

typedef int32_t i32;
typedef uint32_t u32;

typedef int64_t i64;
typedef uint64_t u64;

#endif

#endif