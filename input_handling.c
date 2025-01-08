#include "main.h"

/**
 * tokenize_input - Tokenizes the input string into arguments.
 * @line: Input string containing the command.
 * @argv: Array to store the arguments.
 *
 * Return: Number of tokens parsed.
 */
int tokenize_input(char *line, char **argv)
{
	int i = 0;

	argv[i] = strtok(line, " ");
	while (argv[i] != NULL && i < 99)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	return (i);
}
