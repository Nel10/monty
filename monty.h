#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
/*#include <sys/types.h>*/
/*#include <sys/stat.h>*/

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
	void (*f)(stack_t **stack, unsigned int line_number, char **line,
		  FILE **monty_file);
} instruction_t;

/*These functions are in the create__stack_t.c file*/
size_t print_stack_t(const stack_t *h);
stack_t *push_node(stack_t **head, const int n);
stack_t *enqueue_node(stack_t **head, const int n);
int pop_node(stack_t **head);
size_t list_len(const stack_t *h);

/*These functions are in the print_error_message.c file*/
void print_error_1(void);
void print_error_2(char *file_name);

/*This function is in the check_instruction.c file*/
void check_instruction(stack_t **stack, unsigned int line_number, char *token,
		       char **line, FILE **monty_file);

/*These function are in the instruction_functions.c file*/
void execute_push(stack_t **stack, unsigned int line_number, char **line,
		  FILE **monty_file);
void execute_pall(stack_t **stack, unsigned int line_number, char **line,
		 FILE **monty_file);
void execute_pint(stack_t **stack, unsigned int line_number, char **line,
		 FILE **monty_file);
void execute_pop(stack_t **stack, unsigned int line_number, char **line,
		 FILE **monty_file);
void execute_swap(stack_t **stack, unsigned int line_number, char **line,
		 FILE **monty_file);

/*These function are in the instruction_functions_1.c file*/
void execute_add(stack_t **stack, unsigned int line_number, char **line,
		 FILE **monty_file);
void execute_nop(stack_t **stack, unsigned int line_number, char **line,
		 FILE **monty_file);
void execute_sub(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);
void execute_div(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);
void execute_mul(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);

/*These function are in the instruction_functions_2.c file*/
void execute_mod(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);
void execute_pchar(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);
void execute_pstr(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);
void execute_rotl(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);
void execute_rotr(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);
/*These function are in the instruction_functions_3.c file*/
void execute_stack(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);
void execute_queue(stack_t **stack, unsigned int line_number, char **line,
				 FILE **monty_file);

/*This function is in free_stack_t_list.c*/
void free_stack_t(stack_t *head);

/*This function is in auxiliar_functions.c*/
int check_if_is_digit(char *arg);

#endif /* MONTY_H */
