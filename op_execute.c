#include "monty.h"
/**
 * op_execute - Execute a Monty bytecode instruction.
 * @content_buffer: Buffer containing the instruction and arguments.
 * @stack: Pointer to the stack.
 * @counter: Line number in the Monty bytecode file.
 * @file_pointer: Pointer to the Monty bytecode file.
 *
 * This function executes a Monty bytecode instruction based on the provided
 * content buffer, updating the stack accordingly. It uses a predefined set of
 * instructions specified in the opcode_stack array.
 *
 * Return:
 * - 0 on successful execution of an opcode.
 * - 1 if the opcode is not recognized or an error occurs.
 */
int op_execute(char *content_buffer, stack_t **stack,
		unsigned int counter, FILE *file_pointer)
{
	instruction_t opcode_stack[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content_buffer, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	payload.arg = strtok(NULL, " \n\t");
	while (opcode_stack[i].opcode && opcode)
	{
		if (strcmp(opcode, opcode_stack[i].opcode) == 0)
		{
			opcode_stack[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opcode && opcode_stack[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file_pointer);
		free(content_buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);

}
