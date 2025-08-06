/* typedef and function prototypes for stack */


#ifndef DEFS
	#define DEFS
	#include "defs.h"
#endif

typedef nodep stack; // Pointer to the beginning of the linked list

stack initstack ( ) ; // Create a new empty stack
int emptystack ( stack ) ; // Check whether the input stack is empty
int top ( stack ) ; // Return the top of a stack (if non-empty)
stack push ( stack , int ) ; // Push an integer to a stack
stack pop ( stack ) ; // Pop from a (non-empty) stack
void printstack ( stack ) ; // Print the elements of a stack from top to bottom
stack destroystack ( stack ) ; // Delete all the nodes from a stack
