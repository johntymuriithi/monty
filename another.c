#include "monty.h"

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
