#include "monty.h"

/**
 * _fdlist- free node
 * @stack: top of the stack
 * Return: none
 */
void _fdlist(stack_t *stack)
{
	stack_t *point;

	if (stack == NULL)
		return;

	while (stack)
	{
		point = stack;
		stack = (*stack).next;
		free(point);
	}
	stack = NULL;
}


