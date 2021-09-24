#include "monty.h"

/**
 * op_add - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 * Return: void
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
 * op_nop - no operation performed
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 * @line: Pointer
 * @monty_file: Pointer
 * Return: void
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
 * op_sub - subtract top element of stack from next element and push result
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 * @line: Pointer
 * @monty_file: Pointer
 * Return: void
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
 * op_div - divide second element of stack by top element
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 * @line: Pointer
 * @monty_file: Pointer
 * Return: void
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
 * op_mul - multiply top two elements of stack and push result
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 * @line: Pointer
 * @monty_file: Pointer
 * Return: void
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
