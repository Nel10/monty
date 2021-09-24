#include "monty.h"

/**
* free_stack_t - frees a stack_t list
* @head: Pointer to the head to a double linked list
* Return: void
*/
void free_stack_t(stack_t *head)
{
	stack_t *aux = head;

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
	free(head);
}
