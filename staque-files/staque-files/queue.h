/* typedef and function prototypes for queue */

#ifndef DEFS
	#define DEFS
	#include "defs.h"
#endif

typedef struct {
	nodep front; // Pointer to the beginning of the linked list
	nodep back; // Pointer to the end of the linked list
} queue;

queue initqueue ( ) ; // Create a new empty queue
int emptyqueue ( queue ) ; // Check whether a queue is empty
int front ( queue ) ; // Return the element at the front of a queue (if non-empty)
queue enqueue ( queue , int ) ; // Insert an integer at the front of a queue
queue dequeue ( queue ) ; // Delete an element from the back of a (non-empty) queue
void printqueue ( queue ) ; // Print the elements of a queue from front to back
queue destroyqueue ( queue ) ; // Delete all the nodes from a queue
