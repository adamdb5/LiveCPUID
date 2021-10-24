/*
 * Include common types. These would usually be found in inttypes.h, but to
 * reduce any 64-bit / 32-bit type incompatibilities, we define our own.
 */

#ifndef TYPES_H
#define TYPES_H

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int int16_t;
typedef unsigned short int uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

#endif /* TYPES_H */
