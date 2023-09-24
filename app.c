#include "monty.h"
/**
 * main - Entry Point for the program
 * @argc: number of arguments
 * @argv: Array of arguments
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	FILE *fileopen;
	char *buffer = NULL, *cmd;
	size_t buffsize = 0;
	stack_t *MStack = NULL;
	int line_num = 1, i, flag;
	instruction_t op_codes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{NULL, NULL}};

	checkArgs(argc);
	fileopen = fopen(argv[1], "r");
	checkFile(fileopen, argv);
	while (getline(&buffer, &buffsize, fileopen) != -1)
	{
		flag = 0;
		errno = 0;
		cmd = strtok(buffer, " \n");
		for (i = 0; op_codes[i].opcode != NULL; i++)
		{
			if (strcmp(cmd, op_codes[i].opcode) == 0)
			{
				flag = 1;
				op_codes[i].f(&MStack, line_num);
				myFunc(fileopen, buffer, MStack);
			}
		}
		if (flag == 0)
		{
			printf("L%d: unknown instruction %s\n", line_num, cmd);
			fclose(fileopen);
			free_dlistint(MStack);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}
	fclose(fileopen);
	free_dlistint(MStack);
	free(buffer);
	return (0);
}
