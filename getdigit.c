#include "monty.h"
/**
 * getdigit - checks if string is a number
 *
 * @digit: string
 *
 * Return: 1 if string is a number, 0 otherwise
 */

int getdigit(char *digit)
{
	char *numbers = "0123456789";
	int i = 0, j;

	if (digit[0] == '-')
	{
		i = 1;
	}
	for (; digit[i] != '\0'; i++)
	{
		for (j = 0; numbers[j] != '\0'; j++)
		{
			if (numbers[j] == digit[i])
			{
				break;
			}
			if (j == 9)
			{
				return (0);
			}
		}
	}
	return (1);
}
