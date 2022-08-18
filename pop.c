#include "monty.h"
char *glovar;

/**
 * pop - removes top element
 *
 * @stack: da stack
 * @line_count: line counter
 */

void pop(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
