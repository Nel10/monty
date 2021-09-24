#include "monty.h"

/**
 * execute_push - Add a new node at the head of the stack
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void execute_push(stack_t **stack, unsigned int line_number, char **line,
				  FILE **monty_file)
{
	char *second_argument;
	int number = 0;

	second_argument = strtok(NULL, "\n\t\r ");
	if (second_argument == NULL || check_if_is_digit(second_argument) == 0)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	number = atoi(second_argument);
	if (push_node(stack, number) == NULL)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_pall - Print the stack
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void execute_pall(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	if (*stack == NULL || stack == NULL)
	{
		return;
	}
	(void)line_number;
	(void)line;
	(void)monty_file;
	print_stack_t(*stack);
}

/**
 * execute_pint - Print the head element into the stack
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void execute_pint(stack_t **stack, unsigned int line_number, char **line,
				  FILE **monty_file)
{

	if (list_len(*stack) == 0 || *stack == NULL)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

/**
 * execute_pop - Delete the first element in the stack
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void execute_pop(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file)
{
	if (list_len(*stack) == 0 || *stack == NULL)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop_node(stack);
}

/**
 * execute_swap - swaps the top two elements of the stack.
 * @stack: Stack to work with
 * @line_number: The number of line inside of the file
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 *
 * Return: Nothing
 */
void execute_swap(stack_t **stack, unsigned int line_number, char **line,
				  FILE **monty_file)
{
	stack_t *first = *stack;
	stack_t *end = *stack;

	if (list_len(*stack) < 2)
	{
		free(*line);
		free_stack_t(*stack);

		fclose(*monty_file);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (list_len(*stack) == 2)
	{
		end = first->next;
		first->prev = first->next;
		end->next = first;
		*stack = end;
		first->next = NULL;
		end->prev = NULL;
		return;
	}
	end = first->next;
	first->prev = first->next;
	first->next = end->next;
	end->next->prev = first;
	end->prev = NULL;
	end->next = first;
	*stack = end;
}
