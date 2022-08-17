#include "monty.h"
/**
 * pint_op - prints the value at the top of the stack, followed by a new line
 * @stack: head of stack
 * @line_count: line that counts the stack
 * Return: 0
 */

void _pint(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;

	stack_t *head = *stack;

	if (monty_t.monty_s == 0)
	{
		dprintf(STDOUT_FILENO,"L%u: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
