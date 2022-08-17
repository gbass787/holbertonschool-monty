#include "monty.h"
char *glovar;
/**
 * push - pushes an element into a stack
 *
 * @stack: the stack
 * @line_count: line counter
 */

void push(stack_t **stack, unsigned int line_count)
{
	stack_t *new = NULL;
	unsigned int converter = 0;

	if (glovar == NULL)
	{
		fprintf(2, "L%d: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	if (getdigit(glovar) == 0)
	{
		fprintf(2, "L%d: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	converter = atoi(glovar);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = converter;
	if (*stack != NULL)
	{
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		*stack = new;
	}
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
}
