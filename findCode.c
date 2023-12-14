#include "monty.h"


/**
* opcode_finder - find opcode
* @stack: stack pointer
* @opcode: user input opcode
* @line_number: line number
* Return: Always 1 (Success) or stderr
**/
int find_opcode(stack_t **stack, char *opcode, int line_number)
{
	instruction_t opcodes[] = {
		{"pall", pall},
		{"pop_p", pop_p},
		{"swap", swap},
		{"print", print},
		{NULL, NULL}
	};

	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}


