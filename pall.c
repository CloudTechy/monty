#include "monty.h"
/**
 * func_pall - Prints all elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file.
 */
void func_pall(stack_t **head, unsigned int counter)
{
	stack_t *dum;
	(void)counter;

	dum = *head;
	if (dum == NULL)
		return;
	while (dum)
	{
		printf("%d\n", dum->n);
		dum = dum->next;
	}
}
