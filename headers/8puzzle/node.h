/**
 * Queue Node
 *
 * This is a generic datatype that handles a Linked List and supports any
 * type of data (since it's a pointer to void).
 */

#ifndef _NODE_H_INCLUDED
#define _NODE_H_INCLUDED

typedef struct Node {
  /* Next Node */
  struct Node *next;

  /* Previous node */
  struct Node *prev;

  /* Content */
  void *data;
} Node;

#endif
