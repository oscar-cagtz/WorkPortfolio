/**********************************************************************
 *
 *        NAME:   C_FunctionPrototypes.h
 *
 * DESCRIPTION:   The objective of this file is to define the main
 *                definitions and types to be used by the library of
 *                the function prototypes.
 *
 *      AUTHOR:   Oscar Alberto Carreño Gutierrez
 *
 *        DATE:   January 9th, 2024
 *
 **********************************************************************/
#ifndef C_FUNCTIONPROTOTYPES_H
#define C_FUNCTIONPROTOTYPES_H

/**********************************************************************
 * INCLUDES
 **********************************************************************/

// Project Includes
#include "C_CodingProject.h"

/**********************************************************************
 * DATA DEFINITIONS
 **********************************************************************/

/* Arrays & Strings Definitions ***************************************/

/* Singly-linked List Definitions *************************************/

// Singly-linked List Node
typedef struct OC_SLNODE_D
{
    OC_SINT32_T nodeValue;
    struct OC_SLNODE_D *nextNode;
} OC_SLNODE_T;

/* Doubly-linked List Definitions *************************************/

// Doubly-linked List Node
typedef struct OC_DLNODE_D
{
    OC_SINT32_T nodeValue;
    struct OC_DLNODE_D *nextNode;
    struct OC_DLNODE_D *prevNode;
} OC_DLNODE_T;

/* Trees & Graphs Definitions *****************************************/

/* Recursion Definitions **********************************************/

/* Sorting & Searching Definitions ************************************/

/* Dynamic Programming Definitions ************************************/


/**********************************************************************
 * FUNCTION DECLARATIONS
 **********************************************************************/

/* Arrays & Strings Declarations **************************************/

/* Singly-linked List Declarations ************************************/
OC_SLNODE_T* CreateNodeSL        (OC_SINT32_T   inputValue);

OC_SLNODE_T* SearchNodeByValSL   (OC_SLNODE_T*  headNode,
                                  OC_SINT32_T   inputValue);

OC_RESULT_T  PrintLinkedListSL   (OC_SLNODE_T*  headNode);

OC_RESULT_T  InsertEndNodeSL     (OC_SLNODE_T** headNode,
                                  OC_SINT32_T   inputValue);

OC_RESULT_T  InsertHeadNodeSL    (OC_SLNODE_T** headNode,
                                  OC_SINT32_T   inputValue);

OC_RESULT_T  DeleteNodeByValSL   (OC_SLNODE_T** headNode,
                                  OC_SINT32_T   inputValue);

OC_RESULT_T  DeleteLinkedListSL  (OC_SLNODE_T** headNode);

/* Doubly-linked List Declarations ************************************/
OC_DLNODE_T *CreateNodeDL(OC_SINT32_T inputValue);

/* Trees & Graphs Declarations ****************************************/

/* Recursion Declarations *********************************************/

/* Sorting & Searching Declarations ***********************************/

/* Dynamic Programming Declarations ***********************************/


#endif // C_FUNCTIONPROTOTYPES_H