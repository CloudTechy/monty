#include "monty.h"
/**
 * add_node - Adds a new node at the beginning of the stack.
 * @head: Pointer to the head of the stack.
 * @n: Integer value to be added to the new node.
 */
void add_node(stack_t **head, int n)
{
	stack_t *n_node, *dum;

	dum = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (dum)
		dum->prev = n_node;
	n_node->n = n;
	n_node->next = *head;
	n_node->prev = NULL;
	*head = n_node;
}
