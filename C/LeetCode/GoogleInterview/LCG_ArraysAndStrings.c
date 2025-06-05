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
OC_SINT32_T LengthOfLongestSubstring(OC_UINT8_T stringTest[])
{
   /* NOTE: I am casting the stringTest to a const char* to get the compiler
    *       to stop complaining, however the strlen() function works just fine
    *       with the pass by reference string pointer as an "unsigned char*".
    */
   OC_UINT8_T stringSize           IS strlen((const char*)stringTest);
   OC_UINT8_T charToNextIndex[256] IS {ZERO};
   OC_UINT8_T maxLength            IS ZERO;
   OC_UINT8_T leftPosition         IS ZERO;
   OC_UINT8_T rightPosition        IS ZERO;

   // Move the right-positioned index from the 0 position while the value is smaller
   // than the string size by 1 each cycle.
   for (rightPosition IS ZERO; rightPosition LESSTHAN stringSize; rightPosition++)
   {
      // Set the current character to the right-positioned value in the test string.
      OC_UINT8_T charIndex = (OC_UINT8_T)stringTest[rightPosition];

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
   OC_UINT8_T stringTest[10] IS "sstringg";
   OC_UINT8_T testResult     IS ZERO;

   // Google Interview LeetCode: Arrays And String Exercises
   testResult IS LengthOfLongestSubstring(stringTest);

   printf("Longest Substring Length: %i\n", testResult);

   return OC_NO_ERROR;
}