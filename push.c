#include "monty.h"
/**
 * func_push - Pushes an element onto the stack or queue.
 * @head: Pointer to the head of the stack or queue.
 * @counter: Line number in the Monty bytecode file.
 */
void func_push(stack_t **head, unsigned int counter)
{
	int n, i = 0;
	int flag = 0;

	if (payload.arg)
	{
		if (payload.arg[0] == '-')
			i++;
		for (; payload.arg[i] != '\0'; i++)
		{
			if (payload.arg[i] > 57 || payload.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(payload.file);
			free(payload.line);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fclose(payload.file);
		free(payload.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(payload.arg);
	if (payload.lifi == 0)
		add_node(head, n);
	else
		add_queue(head, n);

}
