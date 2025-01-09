#include "main.h"

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}


/**
 * handle_builtins - Handles built-in commands like "exit" and "env".
 * @line: Input command line.
 * @argv: Parsed arguments.
 *
 * Return: 1 if a built-in command is handled, 0 otherwise.
 */
int handle_builtins(char *line, char **argv)
{
	if (argv[0] && strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(0);
	}

	if (argv[0] && strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0);
}

