#include "monty.h"

/**
 * check_if_is_digit - Check if a gived char pointer correspond to a number
 * @arg: String to check
 *
 * Return: 1 if it is number - otherwise 0
 */
int check_if_is_digit(char *arg)
{
	int i;

	for (i = 0 ; arg[i] != '\0'; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (0);
	}
	return (1);
}
