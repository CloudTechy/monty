#include "monty.h"
/**
 * free_stack - Frees a stack.
 * @head: Pointer to the head of the stack.
 *
 * This function frees the memory occupied by each node in the stack.
 * It iterates through the stack, freeing each node until the stack is empty.
 */
void free_stack(stack_t *head)
{
	stack_t *dum;

	dum = head;
	while (head)
	{
		dum = head->next;
		free(head);
		head = dum;
	}
}
