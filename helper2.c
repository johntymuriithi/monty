#include "monty.h"


/**
 * op_push - function to push data
 * @stack: stack of the values
 * @line_number: line number
 * 
 * Return: no return
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg = strtok(NULL, " \n");

	if (arg == NULL || isNum(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		errno = -21;
		return;
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		errno = -21;
		return;
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * free_dlistint - free
 * @head: head pointer
 *
 * Return: no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}


