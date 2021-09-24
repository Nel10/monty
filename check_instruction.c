#include "monty.h"

/**
 * check_instruction - Gests the corresponding function acording to an
 * instruction
 * @stack: Pointer to the head of a stack
 * @line_number: Number of line inside of the file
 * @token: Instruction to check
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 */

void check_instruction(stack_t **stack, unsigned int line_number, char *token,
		       char **line, FILE **monty_file)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", execute_push},
		{"pall", execute_pall},
		{"pint", execute_pint},
		{"pop", execute_pop},
		{"swap", execute_swap},
		{"add", execute_add},
		{"nop", execute_nop},
		{"sub", execute_sub},
		{"div", execute_div},
		{"mul", execute_mul},
		{"mod", execute_mod},
		{"pchar", execute_pchar},
		{"pstr", execute_pstr},
		{"rotl", execute_rotl},
		{"rotr", execute_rotr},
		{"stack", execute_stack},
		{"queue", execute_queue},
		{NULL, NULL}};
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, token) == 0)
			break;
	}
	if (instructions[i].opcode != NULL)
	{
		instructions[i].f(stack, line_number, line, monty_file);
		return;
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		free(*line);
		fclose(*monty_file);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}
}
