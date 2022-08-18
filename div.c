#include "monty.h"
char *glovar;

/**
 * d_ivision - divides the top 2 elements
 *
 * @stack: the stack
 * @line_count: line counter
 */

void d_ivision(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	unsigned int length = 0, num_1 = 0, num_2 = 0, div = 0;

	length = count(*stack);
	temp = *stack;
	if (length < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	num_1 = temp->n;
	if (num_1 == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
	}
	num_2 = temp->next->n;
	div = num_1 / num_2;
	temp->next->n = div;
	*stack = temp->next;
	free(temp);
}
