/**
 * Queue Implementation
 *
 * A Queue it's a structure that handles as FIFO (First-in, First-out), and
 * will be used to Breadth First Search.
 */

/* size_t definition */
#include <stdlib.h>

/* Booleans */
#include <stdbool.h>

/* Node */
#include <8puzzle/node.h>

#ifndef _QUEUE_H_INCLUDED
#define _QUEUE_H_INCLUDED

/**
 * Queue Data Structure
 *
 * This structure isn't needed, but we'll use to mantain the code
 * cleaner and to know the amount of elements in each queue. With that
 * we don't need to implement a manual Linked List.
 */
typedef struct Queue {
  /* Head of Queue */
  Node *head;

  /* Tail of Queue */
  Node *tail;

  /* Size of Queue */
  size_t size;
} Queue;

/**
 * Create a Empty Queue
 *
 * This method will return a new Queue to store a linked list
 * of Nodes.
 * 
 * @return Queue
 */
Queue *create_queue();

/**
 * Add Node to Queue
 *
 * Picking the given node `n`, we will insert it into our Queue since it
 * implements the Node interface.
 * 
 * @param q Queue that will receive the node `n`
 * @param n Node that will be inserted
 */
void enqueue(Queue *q, Node *n);

/**
 * Remove a Node from Queue
 *
 * This method removes the head Node of Queue, since this structure it's a
 * FIFO.
 * 
 * @param  q Queue
 * @return   Node of the top
 */
Node *dequeue(Queue *q);

/**
 * Check if Queue it's Empty
 *
 * Since we have the ´size` variable, we don't need this method, but only
 * used for better description of what we are doing.
 * 
 * @param  q Queue to be checked
 * @return   is empty?
 */
bool is_queue_empty(Queue *q);

#endif
