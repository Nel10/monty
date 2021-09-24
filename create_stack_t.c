#include "monty.h"

/**
* print_stack_t - prints all the elements of a stack_t list
* @h: Pointer to the head to a double linked list
*
* Return: The number of nodes
*/
size_t print_stack_t(const stack_t *h)
{
	const stack_t *current = h;
	size_t num_nodes = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		num_nodes++;
	}
	return (num_nodes);
}

/**
* push_node - adds a new node at the beginning of a stack_t list
* @head: Pointer to the head to a double linked list
* @n: Integer as a data for the new node
*
* Return: The address of the new element, or NULL if it failed
*/

stack_t *push_node(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (new_node);
}

/**
* enqueue_node - adds a new node at the end of a stack_t list
* @head: Pointer to the head to a double linked list
* @n: Integer as a data for the new node
*
* Return: The address of the new element, or NULL if it failed
*/
stack_t *enqueue_node(stack_t **head, const int n)
{
	stack_t *current = *head;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		new_node->prev = current;
		new_node->next = NULL;
		current->next = new_node;
		current = NULL;
	}
	return (new_node);
}

/**
 * pop_node - removes the top element of the stack.
 * @head: Pointer to the head of a stack.
 *
 * Return: 1 if it succeeded.
 */
int pop_node(stack_t **head)
{
	stack_t *current = *head;

	if (current->next != NULL)
	{
		*head = current->next;
		current->next->prev = NULL;
	}
	else
		*head = NULL;
	free(current);
	return (1);
}

/**
 * list_len - prints the len of a double linked list
 * @h: pointer to the head node
 *
 * Return: Number of nodes
 */

size_t list_len(const stack_t *h)
{
	unsigned int i = 0;
	const stack_t *current;

		current = h;

	while (current)
	{
		current = (*current).next;
		i++;
	}
	return (i);
}
