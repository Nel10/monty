#include "monty.h"

/**
 * op_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 * Return: void
 */
void op_stack(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	(void)stack;
	(void)line_number;
	(void)line;
	(void)monty_file;
}
/**
 * op_queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 * Return: void
 */
void op_queue(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	(void)stack;
	(void)line_number;
	(void)line;
	(void)monty_file;
}
