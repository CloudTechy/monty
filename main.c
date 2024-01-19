#include "monty.h"

payload_t payload = {NULL, NULL, NULL, 0};

/**
 * main - monty interpreter
 * @argc: arguments count
 * @argv: monty bytecode location
 * Return: returns 0 on success
 */
int main(int argc, char *argv[])
{
	char content_buffer[1024];
	FILE *file_pointer;
/*	size_t buffer_size;
	ssize_t readLineResult = 1; */
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty fiile\n");
		exit(EXIT_FAILURE);
	}

	file_pointer = fopen(argv[1], "r");
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	payload.file = file_pointer;
	/*content_buffer = NULL;	*/
	while (fgets(content_buffer, sizeof(content_buffer), file_pointer) != NULL)
	{
	        payload.line = content_buffer;
		counter++;
		op_execute(content_buffer, &stack, counter, file_pointer);
	}
	/**
	while (readLineResult > 0)
	{
		readLineResult = getline(&content_buffer, &buffer_size, file_pointer);
		payload.line = content_buffer;

		if (readLineResult > 0)
		{
			op_execute(content_buffer, &stack, counter, file_pointer);
		} 
	}
	*/

	free_stack(stack);
	fclose(file_pointer);
	return (0);
}
