#include "monty.h"
/**
 * executeop - receives input and compares it to opcodes
 *
 * @opcode: operation codes
 * @stack: the stack
 * @line_count: the line_counter
 */

void executeop(char *opcode, stack_t **stack, unsigned int line_count)
{
	int i;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", _pint},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_count);
			return;
		}
	}
	if (opcodes[i].opcode == NULL)
	{
		dprintf(2, "L%d: unknown instruction %s\n", line_count, opcode);
		exit(EXIT_FAILURE);
	}
}
