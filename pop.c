#include "monty.h"
/**
 * func_pop - Removes the value at the top of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty bytecode file.
 */
void func_pop(stack_t **head, unsigned int counter)
{
	stack_t *dum;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		fclose(payload.file);
		free(payload.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	dum = *head;
	*head = dum->next;
	free(dum);
}
