#include "monty.h"
char *glovar;

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 *
 * @stack: the stack
 * @line_count: line counter
 */

void mod(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	unsigned int length = 0, num_1 = 0, num_2 = 0, mod = 0;

	length = count(*stack);
	temp = *stack;
	if (length < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	num_1 = temp->n;
	if (num_1 == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
	}
	num_2 = temp->next->n;
	mod = num_1 % num_2;
	temp->next->n = mod;
	*stack = temp->next;
	free(temp);
}
