/**********************************************************************
 *
 *        NAME:   LCG_ArraysAndStrings.c
 *
 * DESCRIPTION:   The objective of this file is to document the
 *                author's responses to the Arrays & Strings exercises
 *                of the LeetCode Google Interview section.
 *
 *      AUTHOR:   Oscar Alberto Carreño Gutierrez
 *
 *        DATE:   January 9th, 2024
 *
 **********************************************************************/

/**********************************************************************
 * INCLUDES
 **********************************************************************/

// Standard Includes
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Project Includes
#include "../../C_CodingProject.h"

// LeetCode Includes
#include "LCG_ArraysAndStrings.h"

/**********************************************************************
 * DATA DEFINITIONS
 **********************************************************************/



/**********************************************************************
 * FUNCTION DEFINITIONS
 **********************************************************************/

// Longest Substring Without Repeating Characters
OC_SINT32 LengthOfLongestSubstring(OC_UINT8 stringTest[])
{
   /* NOTE: I am casting the stringTest to a const char* to get the compiler
    *       to stop complaining, however the strlen() function works just fine
    *       with the pass by reference string pointer as an "unsigned char*".
    */
   OC_UINT8 stringSize           IS strlen((const char*)stringTest);
   OC_UINT8 charToNextIndex[256] IS {ZERO};
   OC_UINT8 maxLength            IS ZERO;
   OC_UINT8 leftPosition         IS ZERO;
   OC_UINT8 rightPosition        IS ZERO;

   // Move the right-positioned index from the 0 position while the value is smaller
   // than the string size by 1 each cycle.
   for (rightPosition IS ZERO; rightPosition LESSTHAN stringSize; rightPosition++)
   {
      // Set the current character to the right-positioned value in the test string.
      OC_UINT8 charIndex = (OC_UINT8)stringTest[rightPosition];

      if (charToNextIndex[charIndex] MORETHAN ZERO)
      {
         leftPosition IS MAX(leftPosition, charToNextIndex[charIndex]);
      }

      // Compare the maximum value saved vs the difference between the right and left
      // position. (Add a +1 because they are zero-starting values)
      maxLength = MAX(maxLength, rightPosition - leftPosition + 1);

      charToNextIndex[charIndex] IS rightPosition + 1;
      printf("%i\n", charToNextIndex[charIndex]);
   }

   return maxLength;
}


/**********************************************************************
 * MAIN APPLICATION
 **********************************************************************/
int main(void)
{
   OC_UINT8 stringTest[10] IS "sstringg";
   OC_UINT8 testResult     IS ZERO;

   // Google Interview LeetCode: Arrays And String Exercises
   testResult IS LengthOfLongestSubstring(stringTest);

   printf("Longest Substring Length: %i\n", testResult);
}