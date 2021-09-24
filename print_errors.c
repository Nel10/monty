#include "monty.h"

/**
 * print_error - Print error when the number of arguments is different to two
 * Return: void function
 */
void print_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * print_errors - Print error when file can't be opened
 * @file_name: Pointer to the name of the file
 * Return: void function
 */
void print_errors(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}
