#include "monty.h"

/**
 * op_mul - multiply the top element from the second top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script.
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	int num2, num1, result;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num2 = (*stack)->n;
	num1 = (*stack)->next->n;
	result = num1 * num2;

	op_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * op_div - divide the top element from the second top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script.
 */
void op_div(stack_t **stack, unsigned int line_number)
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
	result = num1 / num2;

	op_pop(stack, line_number); 
	(*stack)->n = result;
}

/**
 * op_sub - Subtract the top element from the second top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script.
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	int num2, num1, result;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num2 = (*stack)->n;
	num1 = (*stack)->next->n;
	result = num1 - num2;

	op_pop(stack, line_number); 
	(*stack)->n = result;
}

/**
 * op_nop - No operation (does nothing).
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script (unused).
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * op_add - Add the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in Monty script.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int num1, num2, result;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num2 = (*stack)->n;
	num1 = (*stack)->next->n;
	result = num1 + num2;

	op_pop(stack, line_number); 
	(*stack)->n = result;
}
