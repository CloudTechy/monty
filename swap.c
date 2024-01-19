#include "monty.h"
/**
 * func_swap - swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty bytecode file.
 */
void func_swap(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		fclose(payload.file);
		free(payload.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
