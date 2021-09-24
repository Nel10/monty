#include "monty.h"

/**
 * print_error_1 - Print error when the number of arguments is different to two
 *
 * Return: Nothing
 */
void print_error_1(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * print_error_2 - Print error when file can't be opened
 * @file_name: Pointer to the name of the file
 *
 * Return: Nothing
 */
void print_error_2(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}
