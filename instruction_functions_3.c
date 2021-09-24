#include "monty.h"

/**
 * execute_stack - ets the format of the data to a stack (LIFO). This is the
 * default behavior of the program.
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void execute_stack(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	(void)stack;
	(void)line_number;
	(void)line;
	(void)monty_file;
}
/**
 * execute_queue - sets the format of the data to a queue (FIFO).
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void execute_queue(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	(void)stack;
	(void)line_number;
	(void)line;
	(void)monty_file;
}
