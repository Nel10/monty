#include "monty.h"

/**
 * get_op_instruc - check op against valid opcodes
 * @stack: double pointer to the beginnig of the stack
 * @line_number: script line number
 * @token: Instruction to check
 * @line: Pointer to a line in a file
 * @monty_file: Pointer to a file to be readed.
 */
void get_op_instruc(stack_t **stack, unsigned int line_number, char *token,
		       char **line, FILE **monty_file)
{
	int i = 0;
	instruction_t instruct_op[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},
		{NULL, NULL}};
	for (i = 0; instruct_op[i].opcode != NULL; i++)
	{
		if (strcmp(instruct_op[i].opcode, token) == 0)
			break;
	}
	if (instruct_op[i].opcode != NULL)
	{
		instruct_op[i].f(stack, line_number, line, monty_file);
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
