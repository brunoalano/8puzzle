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

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Data Structure: Stack */
#include <8puzzle/stack.h>

void push(Stack *s, void *element)
{
	/* Check if the stack it's empty */
	if (s == NULL)
	{
		s = malloc(sizeof(Stack));
		s->head = NULL;
		s->size = 0;
	}

	/* Create a new element */
	Node *node = malloc(sizeof(Node));
	node->data = element;
	node->next = NULL;

	/* Assign the node as the top element of stack */
	if (s->head == NULL)
		s->head = node;
	else
	{
		node->next = s->head;
		s->head = node;
	}

	/* Increment size of Stack */
	s->size++;
}

void *pop(Stack *s)
{
	/* Check if the stack exists */
	if (s == NULL || s->head == NULL)
	{
		printf("[Error] Trying to remove from empty stack\n");
		exit(0);
	}

	/* Store the top element */
	void *temp = s->head->data;

	/* Go to the next element */
	s->head = s->head->next;
	s->size--;

	/* Return the value */
	return temp;
}

void *peek(Stack *s)
{
	/* Check if the stack exists */
	if (s == NULL || s->head == NULL)
	{
		printf("[Error] Trying to peek from empty stack\n");
		exit(0);
	}

	/* Return the top element */
	return s->head->data;
}
