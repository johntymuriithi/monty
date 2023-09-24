#include "monty.h"

/**
 * op_add - Add the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int num1, num2, sum;
	stack_t *new_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num1 = (*stack)->n;
	num2 = (*stack)->next->n;
	sum = num1 + num2;

	op_pop(stack, line_number);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = sum;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

