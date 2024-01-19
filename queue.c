#include "monty.h"
/**
 * func_queue - Sets the stack to queue mode.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty bytecode file.
 *
 * This function sets the stack to queue mode.
 * It does not modify the stack itself.
 */
void func_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	payload.lifi = 1;
}

/**
 * add_queue - Adds a new node to the end of the queue.
 * @head: Pointer to the head of the queue.
 * @n: Integer value to be added to the new node.
 */
void add_queue(stack_t **head, int n)
{
	stack_t *n_node, *dum;

	dum = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
		return;
	}
	n_node->n = n;
	n_node->next = NULL;
	if (dum)
	{
		while (dum->next)
			dum = dum->next;
	}
	if (!dum)
	{
		*head = n_node;
		n_node->prev = NULL;
	}
	else
	{
		dum->next = n_node;
		n_node->prev = dum;
	}
}
