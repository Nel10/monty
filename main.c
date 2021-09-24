#include "monty.h"

/**
 * main - Main function to execute monty
 * @argc: Number of arguments supplied to the program including ./monty string
 * @argv: Arguments to be processed into the executable ./monty
 *
 * Return: If success EXIT_SUCCESS and if error EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	FILE *monty_file = NULL;
	char *line = NULL, *token = NULL;
	size_t line_length = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
		print_error();
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		free(monty_file);
		print_errors(argv[1]);
	}
	while (getline(&line, &line_length, monty_file) != -1)
	{
		line_number++;
		token = strtok(line, " \n\t\r");
		if (token != NULL && token[0] != '#')
			get_op_instruc(&stack, line_number, token, &line,
					  &monty_file);
	}
	free(line);
	free_stack_t(stack);
	fclose(monty_file);
	exit(EXIT_SUCCESS);
}
