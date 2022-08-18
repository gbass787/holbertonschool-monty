#include "monty.h"
char *glovar;

/**
 * main - monty interpreter
 *
 * @argv: arg vector
 * @argc: arg count
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *input = NULL, *tokens = NULL, *number = NULL;
	size_t str_len = 0;
	unsigned int line_count;
	int num_check = 0;
	char *opcode = NULL, *delim = " \t\n";
	FILE *file = NULL;
	stack_t *stack = NULL;

	opcode = argv[1];
	file = fopen(opcode, "r");
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_stack, &stack);
	on_exit(close_file, file);
	on_exit(free_line, &input);
	for (line_count = 1; getline(&input, &str_len, file) != -1; line_count++)
	{
		tokens = strtok(input, delim);
		if (tokens == NULL)
		{
			continue;
		}
		if (strcmp(tokens, "#") != 0)
		{
			number = strtok(NULL, delim);
			while (number != NULL)
			{
				num_check = atoi(number);
				if (num_check == 0 && strcmp(number, "0") != 0)
				{
					number = strtok(NULL, delim);
				}
				else
				{
					glovar = number;
					executeop(tokens, &stack, line_count);
					break;
				}
			}
			if (number ==  NULL)
			{
				glovar = number;
				executeop(tokens, &stack, line_count);
			}
		}
	}
	exit(EXIT_SUCCESS);
}
