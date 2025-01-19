/**********************************************************************
 *
 *        NAME:   C_FunctionPrototypes.c
 *
 * DESCRIPTION:   The objective of this file is to define the main
 *                function prototypes of this project to be able to use
 *                them in the exercise libraries with ease and evaluate
 *                the system.
 *
 *      AUTHOR:   Oscar Alberto Carreño Gutierrez
 *
 *        DATE:   January 9th, 2024
 *
 **********************************************************************/
#ifndef C_FUNCTIONPROTOTYPES_C
#define C_FUNCTIONPROTOTYPES_C

/**********************************************************************
 * INCLUDES
 **********************************************************************/

// Project Includes
#include "C_CodingProject.h"
#include "C_FunctionPrototypes.h"

/**********************************************************************
 * FUNCTION DEFINITIONS
 **********************************************************************/

/* Arrays & Strings Definitions ***************************************/

/* Singly-linked List Definitions *************************************/

// Singly-linked List Node Creation Function Definition

/**********************************************************************
 *
 *        NAME:   CreateNodeSL
 *
 * DESCRIPTION:   This function creates a singly-linked list node with
 *                the input value and initializes its position to NULL.
 *
 *      INPUTS:   inputValue - (sint32) Value to be assigned to the node.
 *
 *     OUTPUTS:   newNode - (struct) Newly created node to be returned.
 *
 *  COMPLEXITY:   Time  - O(1): All operations require a constant time.
 *                Space - O(1): All operations require a constant space.
 *
 **********************************************************************/
OC_SLNODE_T* CreateNodeSL(OC_SINT32_T inputValue)
{
   // Allocate memory of the size of an SL list node and create it.
   OC_SLNODE_T* newNode = (OC_SLNODE_T*)malloc(sizeof(OC_SLNODE_T));

   // Assign the node value to the input's value and set the next node
   // pointer to NULL as it has not been placed in the list yet but we
   // want to initialize it properly, then return this new node back.
   //   nodeValue:      nextNode:
   // +------------+    +------+
   // | inputValue | => | NULL |
   // +------------+    +------+
   newNode->nodeValue = inputValue;
   newNode->nextNode  = NULL;

   return newNode;
}


/**********************************************************************
 *
 *        NAME:   DeleteNodeByValSL
 *
 * DESCRIPTION:   This function searches for a singly-linked list node
 *                by it's value, searching an input reference value.
 *
 *      INPUTS:   headNode   - (struct) Pointer to the list's head node.
 *                inputValue - (sint32) Value to be assigned to the node.
 *
 *     OUTPUTS:   tempNode - (struct) Return the matching node, else NULL.
 * 
 *  COMPLEXITY:   Time  - O(n): Traversing the while loop takes (n) time.
 *                Space - O(1): All operations require a constant space.
 *
 **********************************************************************/
OC_SLNODE_T* SearchNodeByValSL(OC_SLNODE_T* headNode,
                               OC_SINT32_T  inputValue)
{
   OC_SLNODE_T* tempNode = headNode;

   while (tempNode != NULL)
   {
      if (tempNode->nodeValue == inputValue)
      {
         return tempNode;
      }
      tempNode = tempNode->nextNode;
   }

   return NULL;
}


// Function to print the linked list
OC_RESULT_T PrintLinkedListSL(OC_SLNODE_T* headNode)
{
   OC_SLNODE_T* tempNode = headNode;

   while (tempNode != NULL)
   {
      printf("%d", tempNode->nodeValue);

      tempNode = tempNode->nextNode;

      if (tempNode != NULL)
      {
         printf(" -> ");
      }
   }

   printf("\n");

   // Return the function result code.
   return OC_NO_ERROR;
}


/**********************************************************************
 *
 *        NAME:   InsertEndNodeSL
 *
 * DESCRIPTION:   This function inserts a singly-linked list node to
 *                the end of the list and returns the result code.
 *
 *      INPUTS:   headNode   - (struct) Pointer to the list's head node.
 *                inputValue - (sint32) Value to be assigned to the node.
 *
 *     OUTPUTS:   newNode - (struct) Newly created node to be returned.
 * 
 *  COMPLEXITY:   Time  - O(n): Traversing the while loop takes (n) time.
 *                Space - O(1): All operations require a constant space.
 *
 **********************************************************************/
OC_RESULT_T InsertEndNodeSL(OC_SLNODE_T** headNode,
                            OC_SINT32_T   inputValue)
{
   // Create a new singly-listed node with the input value first.
   OC_SLNODE_T* newNode = CreateNodeSL(inputValue);

   // If the head of the list is NULL it means you're inserting the
   // newly-created node at the start of the list so make it the head.
   if (*headNode == NULL)
   {
      *headNode = newNode;
   }
   // If not, you're inserting the node to an already-populated list
   // so iterate through the list until you find the end of the list.
   else
   {
      // Create a temporal node to traverse the list by pointing this
      // temporal node to the list's head node.
      OC_SLNODE_T* tempNode = *headNode;

      // If the next node is not NULL there are still more elements to
      // traverse, so move the temp node to the next node and try again.
      while (tempNode->nextNode != NULL)
      {
         tempNode = tempNode->nextNode;
      }

      // Once the last node is found, set the next node of the list as
      // the new node we just created to append it at the end.
      // +------+    +------+    +---------+    +------+
      // | head | => | .... | => | newNode | => | NULL |
      // +------+    +------+    +---------+    +------+
      tempNode->nextNode = newNode;
   }

   // Return the function result code.
   return OC_NO_ERROR;
}


/**********************************************************************
 *
 *        NAME:   InsertHeadNodeSL
 *
 * DESCRIPTION:   This function inserts a singly-linked list node to
 *                the start of the list and returns the result code.
 *
 *      INPUTS:   headNode   - (struct) Pointer to the list's head node.
 *                inputValue - (sint32) Value to be assigned to the node.
 *
 *     OUTPUTS:   resultCode - (enum) Returns the function result code.
 * 
 *  COMPLEXITY:   Time  - O(1): All operations require a constant time.
 *                Space - O(1): All operations require a constant space.
 *
 **********************************************************************/
OC_RESULT_T InsertHeadNodeSL(OC_SLNODE_T** headNode,
                             OC_SINT32_T   inputValue)
{
   // Create a new singly-listed node with the input value first.
   OC_SLNODE_T* newNode = CreateNodeSL(inputValue);
   OC_RESULT_T  resCode = OC_NO_ERROR;

   // Make the next node of the new node the list's head and then set
   // the list's head as the new node, effectively replacing the head
   // of the list without modifying any of the other nodes.
   // +---------+    +---------+    +------+    +------+
   // | newNode | => | oldHead | => | .... | => | NULL |
   // +---------+    +---------+    +------+    +------+
   newNode->nextNode = *headNode;
   *headNode = newNode;

   // Return the function response code back.
   return resCode;
}


/**********************************************************************
 *
 *        NAME:   DeleteNodeByValSL
 *
 * DESCRIPTION:   This function deletes a singly-linked list node by
 *                it's value, searching an input reference value.
 *
 *      INPUTS:   headNode   - (struct) Pointer to the list's head node.
 *                inputValue - (sint32) Value to be assigned to the node.
 *
 *     OUTPUTS:   newNode - (struct) Newly created node to be returned.
 * 
 *  COMPLEXITY:   Time  - O(1): All operations require a constant time.
 *                Space - O(1): All operations require a constant space.
 *
 **********************************************************************/
OC_RESULT_T DeleteNodeByValSL(OC_SLNODE_T** headNode,
                              OC_SINT32_T   inputValue)
{
   OC_SLNODE_T* tempNode = *headNode;
   OC_SLNODE_T* prevNode = NULL;
   OC_RESULT_T  resCode  = OC_NO_ERROR;

   if (tempNode != NULL && 
      tempNode->nodeValue == inputValue)
   {
      *headNode = tempNode->nextNode;
      free(tempNode);
      return OC_NO_ERROR;
   }

   while (tempNode != NULL && 
          tempNode->nodeValue != inputValue)
   {
      prevNode = tempNode;
      tempNode = tempNode->nextNode;
   }

   if (tempNode == NULL) return OC_NO_ERROR;

   prevNode->nextNode = tempNode->nextNode;
   free(tempNode);

   // Return the function response code back.
   return resCode;
}


/**********************************************************************
 *
 *        NAME:   DeleteLinkedListSL
 *
 * DESCRIPTION:   This function deletes the singly-linked list input
 *                and frees the allocated memory it had.
 *
 *      INPUTS:   headNode - (struct) Pointer to the list's head node.
 *
 *     OUTPUTS:   resultCode - (enum) Returns the function result code.
 * 
 *  COMPLEXITY:   Time  - O(n): Traversing the while loop takes (n) time.
 *                Space - O(1): All operations require a constant space.
 *
 **********************************************************************/
OC_RESULT_T DeleteLinkedListSL(OC_SLNODE_T** headNode)
{
   OC_SLNODE_T* tempNode = *headNode;
   OC_RESULT_T  resCode  = OC_NO_ERROR;

   // 
   while (tempNode != NULL)
   {
      OC_SLNODE_T* nextNode = tempNode->nextNode;
      free(tempNode);
      tempNode = nextNode;
   }

   *headNode = NULL;

   // Return the function result code.
   return resCode;
}


/* Doubly-linked List Definitions *************************************/

// Singly-linked List Node Creation Function Definition
OC_DLNODE_T* CreateNodeDL(OC_SINT32_T inputValue)
{
   // Allocate memory of the size of a DL list node and create it.
    OC_DLNODE_T *newNode = (OC_DLNODE_T*)malloc(sizeof(OC_DLNODE_T));

   // Assign the input value to the node value and set the next/prev node
   // pointers to NULL as it has not been placed in the list yet but we
   // want to initialize then properly, then return this new node back.
   newNode->nodeValue = inputValue;
   newNode->nextNode  = NULL;
   newNode->prevNode  = NULL;

   return newNode;
}

/* Trees & Graphs Definitions *****************************************/

/* Recursion Definitions **********************************************/

/* Sorting & Searching Definitions ************************************/

/* Dynamic Programming Definitions ************************************/


/**********************************************************************
 * MAIN APPLICATION
 **********************************************************************/
OC_SINT32_T main(void)
{
   OC_UINT8_T resultCode = OC_NO_ERROR;

   printf("%i\n", resultCode);
}


#endif // C_FUNCTIONPROTOTYPES_C