#include "monty.h"

/**
 * op_mod - modulus the top element from the second top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script.
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	int num2, num1, result;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num2 = (*stack)->n;
	if (num2 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	num1 = (*stack)->next->n;
	result = num1 % num2;

	op_pop(stack, line_number);
	(*stack)->n = result;
}
