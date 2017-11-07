/*
 * xcore/core/x86/memory.h
 * Copyright (C) 2015 xent
 * Project is distributed under the terms of the GNU General Public License v3.0
 */

#ifndef XCORE_CORE_INTEL_MEMORY_H_
#define XCORE_CORE_INTEL_MEMORY_H_
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <xcore/core/x86/asm.h>
#include <xcore/helpers.h>
/*----------------------------------------------------------------------------*/
#define TO_BIG_ENDIAN_16(value) \
    ((((value) & 0x00FFU) << 8) | (((value) & 0xFF00U) >> 8))
#define TO_LITTLE_ENDIAN_16(value)      (value)
#define FROM_BIG_ENDIAN_16(value)       TO_BIG_ENDIAN_16(value)
#define FROM_LITTLE_ENDIAN_16(value)    TO_LITTLE_ENDIAN_16(value)

#define TO_BIG_ENDIAN_32(value) \
    ((((value) & 0x000000FFUL) << 24) | (((value) & 0x0000FF00UL) << 8) \
        | (((value) & 0x00FF0000UL) >> 8) | (((value) & 0xFF000000UL) >> 24))
#define TO_LITTLE_ENDIAN_32(value)      (value)
#define FROM_BIG_ENDIAN_32(value)       TO_BIG_ENDIAN_32(value)
#define FROM_LITTLE_ENDIAN_32(value)    TO_LITTLE_ENDIAN_32(value)
/*----------------------------------------------------------------------------*/
BEGIN_DECLS

static inline uint32_t countLeadingZeros32(uint32_t value)
{
  /* If input value is 0, the result is undefined */
  return __builtin_clz(value);
}

static inline uint64_t toBigEndian64(uint64_t value)
{
  return __builtin_bswap64(value);
}

static inline uint32_t toBigEndian32(uint32_t value)
{
  return __builtin_bswap32(value);
}

static inline uint16_t toBigEndian16(uint16_t value)
{
  return __builtin_bswap16(value);
}

static inline uint64_t toLittleEndian64(uint64_t value)
{
  return value;
}

static inline uint32_t toLittleEndian32(uint32_t value)
{
  return value;
}

static inline uint16_t toLittleEndian16(uint16_t value)
{
  return value;
}

static inline uint64_t fromBigEndian64(uint64_t value)
{
  return toBigEndian64(value);
}

static inline uint32_t fromBigEndian32(uint32_t value)
{
  return toBigEndian32(value);
}

static inline uint16_t fromBigEndian16(uint16_t value)
{
  return toBigEndian16(value);
}

static inline uint64_t fromLittleEndian64(uint64_t value)
{
  return value;
}

static inline uint32_t fromLittleEndian32(uint32_t value)
{
  return value;
}

static inline uint16_t fromLittleEndian16(uint16_t value)
{
  return value;
}

static inline bool compareExchangePointer(void **pointer, void *expected,
    void *desired)
{
  return __sync_bool_compare_and_swap(pointer, expected, desired);
}

END_DECLS
/*----------------------------------------------------------------------------*/
#endif /* XCORE_CORE_INTEL_MEMORY_H_ */
