/**
 * Test Queue Data Structure
 *
 * This will run some tests into Queue data structure to make sure that
 * it will works like a Queue
 */

/* Standard Library */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Queue */
#include <8puzzle/queue.h>

/* Main */
int main(void)
{
	/* Creates a new Queue */
	Queue *q = create_queue();

	/* Create new Nodes */
	for (int i = 0; i < 10; i++)
	{
		Node *n = malloc(sizeof(Node));
		int *x = malloc(sizeof(int));
		*x = i;
		n->data = x;
		enqueue(q, n);
	}

	/* Assetions */
	assert( *((int*)(dequeue(q)->data)) == 0 );
	assert( *((int*)(dequeue(q)->data)) == 1 );
	assert( *((int*)(dequeue(q)->data)) == 2 );
	assert( *((int*)(dequeue(q)->data)) == 3 );
	assert( *((int*)(dequeue(q)->data)) == 4 );
	assert( *((int*)(dequeue(q)->data)) == 5 );
	assert( *((int*)(dequeue(q)->data)) == 6 );
	assert( *((int*)(dequeue(q)->data)) == 7 );
	assert( *((int*)(dequeue(q)->data)) == 8 );
	assert( *((int*)(dequeue(q)->data)) == 9 );

	/* Operating System */
	return 0;
}
