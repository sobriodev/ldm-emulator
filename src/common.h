#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif

/* ---------------------------------------------------------------------------------------------- */
/* ----------------------------------------- Data types ----------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/* Unsigned types */
/** 8-bit unsigned type */
typedef uint8_t u8;
/** 16-bit unsigned type */
typedef uint16_t u16;
/** 32-bit unsigned type */
typedef uint32_t u32;
/** 64-bit unsigned type */
typedef uint64_t u64;

/* Signed types */
/** 8-bit signed type */
typedef int8_t i8;
/** 16-bit signed type */
typedef int16_t i16;
/** 32-bit signed type */
typedef int32_t i32;
/** 64-bit signed type */
typedef int64_t i64;

/** A type to represent size or length of something */
typedef size_t size;

#if defined(__cplusplus)
}
#endif

#endif // COMMON_H
