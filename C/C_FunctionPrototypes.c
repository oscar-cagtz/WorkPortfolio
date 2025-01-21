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
 *        NAME:   SearchNodeByValSL
 *
 * DESCRIPTION:   This function searches for a singly-linked list node
 *                by it's value, using an input reference value.
 *
 *      INPUTS:   headNode   - (struct) Pointer to the list's head node.
 *                inputValue - (sint32) Value to be searched in the list.
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
   // Create a temporal singly-listed node pointing to the list's head.
   OC_SLNODE_T* tempNode = headNode;

   // While the temporal node is not NULL (meaning that it's the end of
   // the list) traverse the list until you find a value that matches.
   while (tempNode != NULL)
   {
      // If the temporal node's value is equal to the input value, end
      // the function and return the matching node immediately.
      if (tempNode->nodeValue == inputValue)
      {
         return tempNode;
      }
      
      // If the node's value did not match, move to the next one.
      tempNode = tempNode->nextNode;
   }

   // If no node was found return a NULL result.
   return NULL;
}


/**********************************************************************
 *
 *        NAME:   PrintLinkedListSL
 *
 * DESCRIPTION:   This function prints a singly-linked list starting
 *                from the input head node.
 *
 *      INPUTS:   headNode - (struct) Pointer to the list's head node.
 *
 *     OUTPUTS:   resultCode - (enum) Returns the function result code.
 *
 *  COMPLEXITY:   Time  - O(n): Traversing the while loop takes (n) time.
 *                Space - O(1): All operations require a constant space.
 *
 **********************************************************************/
OC_RESULT_T PrintLinkedListSL(OC_SLNODE_T* headNode)
{
   // Create a temporal singly-listed node pointing to the list's head.
   OC_SLNODE_T* tempNode = headNode;
   // Create a response code variable to return once the function exits.
   OC_RESULT_T  resCode  = OC_NO_ERROR;

   // While the temporal node is not NULL (meaning that it's the end of
   // the list) traverse the list until you find a value that matches.
   while (tempNode != NULL)
   {
      // Print the current node's value as a a decimal integer (%d).
      printf("%d", tempNode->nodeValue);

      // Move to the next node once you have printed the current.
      tempNode = tempNode->nextNode;

      // If it was not the last node print an arrow for stylization.
      if (tempNode != NULL)
      {
         printf(" -> ");
      }
   }

   // Once the whole list has been printed, add a newline and exit.
   printf("\n");

   // Return the function result code.
   return resCode;
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
   // Create a response code variable to return once the function exits.
   OC_RESULT_T  resCode = OC_NO_ERROR;

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
   return resCode;
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
   // Create a response code variable to return once the function exits.
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
   // Create a temporal singly-listed node pointing to the list's head.
   OC_SLNODE_T* tempNode = *headNode;
   // Create a previous node struct to keep track of the node's position.
   OC_SLNODE_T* prevNode = NULL;
   // Create a response code variable to return once the function exits.
   OC_RESULT_T  resCode  = OC_NO_ERROR;

   // First check if the temporal node is not NULL and the value matches
   // the input value to avoid traversing the node if it's at the start.
   if (tempNode != NULL && 
      tempNode->nodeValue == inputValue)
   {
      // If the value matches, change the head of the list to the next
      // node and immediately delete it by freeing its memory.
      *headNode = tempNode->nextNode;
      free(tempNode);

      // Exit the function and return a successful response code.
      resCode = OC_SUCCESSFUL;
      return resCode;
   }

   // If the value value was not at the start of the list, traverse each
   // node until you find a value that matches the input value.
   while (tempNode != NULL && 
          tempNode->nodeValue != inputValue)
   {
      prevNode = tempNode;
      tempNode = tempNode->nextNode;
   }

   // If the temporal node was pointing to a NULL, the list is empty and
   // no node will be found to be deleted, return a value not found code.
   if (tempNode == NULL)
   {
      return OC_ERR_VNF;
   }

   // Point the previous node's next node link to the to-be-deleted temp
   // node to effectively delete it from the list and free its memory.
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
   // Create a temporal singly-listed node pointing to the list's head.
   OC_SLNODE_T* tempNode = *headNode;
   // Create a response code variable to return once the function exits.
   OC_RESULT_T  resCode  = OC_NO_ERROR;

   // While the temporal node is not NULL (meaning that it's the end of
   // the list) traverse the list to delete each node properly.
   while (tempNode != NULL)
   {
      // Save the next node before deleting the link to it from the
      // current temporal node.
      OC_SLNODE_T* nextNode = tempNode->nextNode;

      // Free the memory allocated to the current temporal node.
      free(tempNode);

      // Move the current temporal node to the next node to delete the
      // next element in the following while cycle.
      tempNode = nextNode;
   }

   // Save the head node to a NULL pointer to indicate an empty list.
   *headNode = NULL;

   // Return the function result code.
   return resCode;
}


/* Doubly-linked List Definitions *************************************/

/**********************************************************************
 *
 *        NAME:   CreateNodeDL
 *
 * DESCRIPTION:   This function creates a doubly-linked list node with
 *                the input value and initializes its positions to NULL.
 *
 *      INPUTS:   inputValue - (sint32) Value to be assigned to the node.
 *
 *     OUTPUTS:   newNode - (struct) Newly created node to be returned.
 *
 *  COMPLEXITY:   Time  - O(1): All operations require a constant time.
 *                Space - O(1): All operations require a constant space.
 *
 **********************************************************************/
OC_DLNODE_T* CreateNodeDL(OC_SINT32_T inputValue)
{
   // Allocate memory of the size of a DL list node and create it.
    OC_DLNODE_T *newNode = (OC_DLNODE_T*)malloc(sizeof(OC_DLNODE_T));

   // Assign the node value to the input's value and set the next/prev
   // node pointers to NULL as it has not been placed in the list yet but
   // we want to initialize them properly, then return this new node back.
   // prevNode:     nodeValue:      nextNode:
   // +------+    +------------+    +------+
   // | NULL | => | inputValue | => | NULL |
   // +------+    +------------+    +------+
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