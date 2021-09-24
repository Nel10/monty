#include "monty.h"
/**
 * op_add - Add the 2 first (top) elements of the stack
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void op_add(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	int n = 0;

	if (list_len(*stack) < 2)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop_node(stack);
	(*stack)->n += n;

}

/**
 * op_nop - Do nothing
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void op_nop(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	(void)stack;
	(void)line_number;
	(void)line;
	(void)monty_file;
}

/**
 * op_sub - subtracts the top element of the stack from the
 * second top element of the stack.
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void op_sub(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	int n = 0;

	if (list_len(*stack) < 2)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop_node(stack);
	(*stack)->n = (*stack)->n - n;
}

/**
 * op_div - divides the second top element of
 * the stack by the top element of the stack.
 * second top element of the stack.
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void op_div(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	int n = 0;

	if (list_len(*stack) < 2)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	pop_node(stack);
	(*stack)->n = (*stack)->n / n;
}

/**
 * op_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * second top element of the stack.
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void op_mul(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	int n = 0;

	if (list_len(*stack) < 2)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop_node(stack);
	(*stack)->n = (*stack)->n * n;
}
