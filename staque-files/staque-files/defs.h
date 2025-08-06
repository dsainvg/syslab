/* declare a datatype for one node of a link list */

typedef struct _node {
	int data;
	struct _node *next;
} node;
typedef node *nodep;
