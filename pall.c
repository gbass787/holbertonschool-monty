#include "monty.h"
/**
 * pall - prints all the values on the stack,
 * starting from the top.
 *
 * @stack: the stack
 * @line_count: line counter
 */

void pall(stack_t **stack, __atrribute__((unused))unsigned int line_count)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
