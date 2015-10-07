/**
 * Queue Implementation
 *
 * A Queue it's a structure that handles as FIFO (First-in, First-out), and
 * will be used to Breadth First Search.
 */

/* Standard Library */
#include <stdio.h>
#include <stdlib.h>

/* Node */
#include <8puzzle/queue.h>
#include <8puzzle/node.h>

Queue *create_queue()
{
  Queue *q = malloc(sizeof(Queue));
  if (!q) { return NULL; }
  q->head = NULL;
  q->size = 0;

  return q;
}

void enqueue(Queue *q, Node *n)
{
  /* Check if Queue exists */
  if (!q) { printf("Queue não existe\n"); exit(0); }

  /* Check if Queue it's empty */
  if (q->head == NULL)
  {
    /* Add it to Queue */
    q->head = n;
    q->tail = n;
  } else {
    q->tail->next = n;
    q->tail = n;
  }

  /* Increment size of Queue */
  q->size++;

  /* Setup the Node */
  n->next = NULL;
}

void *dequeue(Queue *q)
{
  /* Check if Queue exists */
  if (q == NULL) { printf("Queue não existe\n"); exit(0); }

  /* Check if Queue it's empty */
  if (q->head == NULL) { printf("Queue vazia\n"); exit(0); }

  /* Create Temporary Node */
  Node *temp_node = q->head;
  void *temp_state = temp_node->data;

  /* Go to next element of Queue */
  q->head = q->head->next;

  /* Free the node */
  free(temp_node);

  /* Decrement size of Queue */
  q->size--;

  /* Return temporary Node */
  return temp_state;
}

bool is_queue_empty(Queue *q)
{
  return q->size == 0;
}
