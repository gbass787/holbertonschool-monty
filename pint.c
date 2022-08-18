#include "monty.h"
/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: head of stack
 * @line_count: line that counts the stack
 * Return: 0
 */

void _pint(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	printf("%d\n", temp->n);
}
