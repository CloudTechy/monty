#include "monty.h"
/**
 * func_sub - subs the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty bytecode file.
 */
void func_sub(stack_t **head, unsigned int counter)
{
	stack_t *dum;
	int nodes, dum_n;

	dum = *head;
	for (nodes = 0; dum != NULL; nodes++)
		dum = dum->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", counter);
		fclose(payload.file);
		free(payload.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	dum = *head;
	dum_n = dum->next->n - dum->n;
	dum->next->n = dum_n;
	*head = dum->next;
	free(dum);
}
