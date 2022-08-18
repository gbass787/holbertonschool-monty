#include "monty.h"


/**
 * main - monty bytecode interpreter
 * @argc: argument count
 * @filename: path to the file containing Monty byte code
 *Return: EXIT_SUCEEE or EXIT_FALILURE
 */
int main(int argc, char **filename)
{
	char *line = NULL;
	FILE *file = NULL;
	int input = 1;
	size_t stack_amount;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	line = NULL;
	while (getline(&line, &stack_amount, file) > 0)
	{
		if (executeop(stack,input, line, file) == 1)
		{
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		input++;
	}
	free(line);
	_fdlist(stack);
	fclose(file);
	return (0);
}





