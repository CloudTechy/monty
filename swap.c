#include "monty.h"
/**
 * func_swap - swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty bytecode file.
 */
void func_swap(stack_t **head, unsigned int counter)
{
	stack_t *dum;
	int len = 0, dum_n;

	dum = *head;
	while (dum)
	{
		dum = dum->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		fclose(payload.file);
		free(payload.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	dum = *head;
	dum_n = dum->n;
	dum->n = dum->next->n;
	dum->next->n = dum_n;
}
