#include "monty.h"

/**
 * free_stack - free da stack
 *
 * @status: status signal
 * @line: element were closing
 */

void free_stack(int status, void *line)
{
	stack_t **stack;
	stack_t *temp;
	(void) status;

	stack = (stack_t **) line;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * close_file - closes file
 *
 * @status: status signal
 * @line: file to close
 */

void close_file(int status, void *line)
{
	FILE *file;
	(void) status;
	file = (FILE *) line;
	fclose(file);
}

/**
 * free_line - frees lines
 *
 * @status: status signal
 * @line: element to free bro
 */

void free_line(int status, void *line)
{
	char **liner = line;
	(void) status;

	if (*liner != NULL)
	{
		free(*liner);
	}
}
