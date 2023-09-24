#include "monty.h"

/**
 * checkFile - function to push data
 * @fileopen: file opened
 * @argv: arguments
 *
 * Return: no return
 */
void checkFile(FILE *fileopen, char **argv)
{
	if (fileopen == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * checkArgs - function to check the number of arguments passed
 * @argc: number of the values
 *
 * Return: no return
 */
void checkArgs(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * myFunc - function to free spaces
 * @fileopen: file itself
 * @buffer: buffer passed
 * @MStack: stack of the data
 *
 * Return: no return
 */
void myFunc(FILE *fileopen, char *buffer, stack_t *MStack)
{

	if (errno == -21)
	{
		fclose(fileopen);
		free_dlistint(MStack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_pall - function to print data
 * @stack: stack of the values
 * @line_number: line number
 *
 * Return: no return
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (*stack == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * isNum - check if a string is number
 * @str: string to check
 *
 * Return: return 1 or 0
 */
int isNum(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	if (*str == '+' || *str == '-')
	{
		str++;
	}


	while (*str != '\0')
	{

		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
