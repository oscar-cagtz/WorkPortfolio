/**************************************************************
 *
 *        NAME:   C_CodingProject.h
 * DESCRIPTION:   The objective of this file is to define the
 *                main variables and types to be used by this
 *                project that are to be consumed by all the
 *                exercise files.
 *      AUTHOR:   Oscar Alberto Carreño Gutierrez
 *        DATE:   January 9th, 2024
 *
 **************************************************************/

/**************************************************************
 * INCLUDES
 **************************************************************/

// Standard includes
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**************************************************************
 * DATA DEFINITIONS
 **************************************************************/

/* NOTE: I'm redefining types just to have a cheatsheet of the
 *       sizes and to compress the long type names into an easy-
 *       to-write redefinition. These should be used project-wide.
 *
 *       For the CMake compiler of macOS the long is an 8-byte
 *       datatype, for other compilers this could need a long long
 *       definition instead to have an 8-byte definition.
 */

//      Datatype:           | Redef:       | Size:   |            Min:            |            Max:            | Format:
typedef signed char           OC_SINT8;   // 1 byte  |                       -128 |                        127 | %c
typedef unsigned char         OC_UINT8;   // 1 byte  |                          0 |                        127 | %c
typedef signed short int      OC_SINT16;  // 2 bytes |                    −32,768 |                     32,767 | %i
typedef unsigned short int    OC_UINT16;  // 2 bytes |                          0 |                     65,635 | %i
typedef signed int            OC_SINT32;  // 4 bytes |             -2,147,483,648 |              2,147,483,647 | %i
typedef unsigned int          OC_UINT32;  // 4 bytes |                          0 |              4,294,967,295 | %i
typedef signed long           OC_SINT64;  // 8 bytes | -9,223,372,036,854,775,808 |  9,223,372,036,854,775,807 | %li
typedef unsigned long         OC_UINT64;  // 8 bytes |                          0 | 18,446,744,073,709,551,615 | %li
typedef float                 OC_FLOAT32; // 4 bytes |                  3.4E +/- 38 (7 digits)                 | %f
typedef double                OC_FLOAT64; // 8 bytes |                 1.7E +/- 308 (15 digits)                | %d

