/**********************************************************************
 *
 *        NAME:   C_CodingProject.h
 *
 * DESCRIPTION:   The objective of this file is to define the main
 *                definitions and types to be used by this project that
 *                are to be consumed by all the exercise files.
 *
 *      AUTHOR:   Oscar Alberto Carreño Gutierrez
 *
 *        DATE:   January 9th, 2024
 *
 **********************************************************************/
#ifndef C_CODINGPROJECT_H
#define C_CODINGPROJECT_H

/**********************************************************************
 * INCLUDES
 **********************************************************************/

/* NOTE: I'm defining all of the standard C libraries in the main coding
 *       project header to avoid having to define them per file and
 *       because this project is so low-usage that the implications and
 *       size constrains that may impact this project by including all
 *       libraries in every file, even the unused ones, is not a concern.
 *
 *       Do not do this for higher-complexity projects, there is a lot
 *       of value of only including the libraries you need per file and
 *       also of not depending on a single file to have all the headers
 *       you may require. Always aim for code independence and modularity.
 */

// Standard Includes
#include <ctype.h>  // Character Classification/Conversion
#include <limits.h> // Integer Type Limit Definitions
#include <math.h>   // Common Mathematical Functions
#include <stddef.h> // Pointer/Structure/Memory Definitions
#include <stdio.h>  // Input/Output Operation Functions
#include <stdlib.h> // General-Purpose Operation Functions
#include <string.h> // String Manipulation Functions
#include <time.h>   // Time Manilupation Functions


/**********************************************************************
 * DATA DEFINITIONS
 **********************************************************************/

// Datatype Definitions

/* NOTE: I'm redefining types just to have a cheatsheet of the
 *       sizes and to compress the long type names into an easy-
 *       to-write redefinition. These should be used project-wide.
 *
 *       For the CMake compiler of macOS the long is an 8-byte
 *       datatype, for other compilers this could need a long long
 *       definition instead to have an 8-byte definition.
 */

//      Datatype:           | Redef:         | Size:   |            Min:            |            Max:            | Format:
typedef signed char           OC_SINT8_T;   // 1 byte  |                       -128 |                        127 | %c
typedef unsigned char         OC_UINT8_T;   // 1 byte  |                          0 |                        255 | %c
typedef signed short int      OC_SINT16_T;  // 2 bytes |                    −32,768 |                     32,767 | %i
typedef unsigned short int    OC_UINT16_T;  // 2 bytes |                          0 |                     65,635 | %i
typedef signed int            OC_SINT32_T;  // 4 bytes |             -2,147,483,648 |              2,147,483,647 | %d
typedef unsigned int          OC_UINT32_T;  // 4 bytes |                          0 |              4,294,967,295 | %d
typedef signed long           OC_SINT64_T;  // 8 bytes | -9,223,372,036,854,775,808 |  9,223,372,036,854,775,807 | %li
typedef unsigned long         OC_UINT64_T;  // 8 bytes |                          0 | 18,446,744,073,709,551,615 | %li
typedef float                 OC_FLOAT32_T; // 4 bytes |                  3.4E +/- 38 (7 digits)                 | %f
typedef double                OC_FLOAT64_T; // 8 bytes |                 1.7E +/- 308 (15 digits)                | %d

typedef enum OC_BOOL_D // NOTE: We're enumerating this definition to use it as a datatype instead of just defining it below.
{
   OC_FALSE = 0,
   OC_TRUE  = 1
} OC_BOOL_T;

typedef enum OC_RESULT_D // NOTE: These enumerals are just for error handling this project, they're not standarized outside of 0.
{
   OC_ERR_UNDEF = -1, // Undefined behavior error.
   OC_NO_ERROR  = 0,  // No error scenario.
   OC_ERR_OORL  = 1,  // Out-of-range Low error scenario.
   OC_ERR_OORH  = 2   // Out-of-range High error scenario.
} OC_RESULT_T;

// Boolean Definitions
#define AND          &&
#define OR           ||
#define IS           =
#define NOT          !
#define MOD          %
#define LESSTHAN     <
#define MORETHAN     >
#define LESSOREQUAL  <=
#define MOREOREQUAL  >=
#define EQUALS       ==
#define NOTEQUALS    !=
#define BAND         &
#define BOR          |
#define BXOR         ^
#define BNOT         ~
#define BLSHIFT      <<
#define BRSHIFT      >>

// Math Definitions
#define ZERO         0
#define PI           3.14159265                 // Definition of PI
#define E            2.71828182                 // Definition of Euler's constant
#define RAD2DEG(x)   ((x) / PI * 180)           // Conver radians to degrees
#define DEG2RAD(x)   ((x) * PI / 180)           // Convert degrees to radians
#define MIN(x, y)    (((x) < (y)) ?  (x) : (y)) // Minimum value of the inputs
#define MAX(x, y)    (((x) > (y)) ?  (x) : (y)) // Maximum value of the inputs
#define ABS(x)       (((x) <   0) ? -(x) : (x)) // Absolute value of the input
#define DIFF(a,b)    ABS((a)-(b))               // Absolute difference between inpus


/**********************************************************************
 * FUNCTION DECLARATIONS
 **********************************************************************/


#endif // C_CODINGPROJECT_H