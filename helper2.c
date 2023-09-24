#include "monty.h"


/**
 * op_swap - swap the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script (unused).
 *
 * Return: no return
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int swa, num;
	stack_t *current = *stack;

	while (current != NULL)
	{
		num++;
		printf("%d\n", current->n);
		current = current->next;
	}
	if (num < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swa = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swa;
}

/**
 * op_pint - Print the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script (unused).
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

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

/**
 * op_pop - Remove the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script (unused).
 * 
 * Return: no return
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *popNode;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	popNode = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(popNode);
}
