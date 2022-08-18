#include "monty.h"
char *glovar;

/**
 * mul - multiplies the top 2 elements
 *
 * @stack: da spicy stack
 * @line_count: line counter
 */

void mul(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	unsigned int length = 0, num_1 = 0, num_2 = 0, sum = 0;

	length = count(*stack);
	temp = *stack;
	if (length < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	num_1 = temp->n;
	num_2 = temp->next->n;
	sum = num_1 * num_2;
	temp->next->n = sum;
	*stack = temp->next;
	free(temp);
}
