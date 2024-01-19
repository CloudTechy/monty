#ifndef _MONTY_H
#define _MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct payload_s - Payload structure for program values
 * @arg: Argument value
 * @file: Pointer to a monty file
 * @line: Content of a line
 * @lifi: Flag to change between stack and queue
 * Description: "This payload structure acts as a container,
 * allowing the program to carry and manage essential information
 * as it progresses through its execution.
 */
typedef struct payload_s
{
	char *arg;
	FILE *file;
	char *line;
	int lifi;
} payload_t;

extern payload_t payload;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *global_stack; /* Global stack variable */

void func_push(stack_t **stack, unsigned int line_number);
void func_pall(stack_t **stack, unsigned int line_number);
int op_execute(char *content_buffer, stack_t **head, unsigned int counter, FILE *file_pointer);
void free_stack(stack_t *head);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void func_queue(stack_t **head, unsigned int counter);
void func_stack(stack_t **head, unsigned int counter);
void func_pint(stack_t **head, unsigned int counter);
void func_pop(stack_t **head, unsigned int counter);
void func_swap(stack_t **head, unsigned int counter);
void func_add(stack_t **head, unsigned int counter);
#endif /* _MONTY_H */
