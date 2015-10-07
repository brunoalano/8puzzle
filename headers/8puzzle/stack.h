/**
 * Stack Structure
 *
 * The Stack it's a structure that implements a LIFO (last in, first out),
 * where we have 2 main methods: push and pop. Also we provide the `peek` to
 * allow the access into top element of our stack.
 *
 * @author Bruno Alano Medina <bruno@appzlab.com>
 * @license LGPL
 * @version 1.0
 */

#ifndef _STACK_H_INCLUDED
#define _STACK_H_INCLUDED

/**
 * Node
 */
#include <8puzzle/node.h>

/**
 * Stack
 *
 * This is the data structure where store the Nodes as a
 * linked list, but implement that on a Node
 */
typedef struct Stack {
	/* Top element on Stack */
	Node *head;

	/* Size of the Stack */
	size_t size;
} Stack;

/**
 * Add Element into Stack
 *
 * This will add the element into the top of the stack, being the next
 * element to be popped.
 * 
 * @param s       Stack that will be inserted
 * @param element Element data to be inserted
 */
void push(Stack *s, void *element);

/**
 * Remove Top element of Stack
 *
 * This will remove the top element of the stack, and the new head will
 * became to be the next one.
 * 
 * @param  s Stack that will be removed a element
 * @return   Element content of the top
 */
void *pop(Stack *s);

/**
 * Get Top Element Value of Stack
 *
 * This won't remove the top element like pop.
 * 
 * @param  s Stack that will be fetched
 * @return   Top element data
 */
void *peek(Stack *s);

#endif