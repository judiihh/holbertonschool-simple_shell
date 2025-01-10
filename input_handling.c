#include "main.h"

/**
 * tokenize_input - Splits the input string into tokens based on spaces.
 * @line: Input string containing the command and arguments.
 * @argv: Array to store the tokens (arguments).
 *
 * Description:
 * This function uses `strtok` to tokenize the input string `line` by spaces.
 * It stores the tokens in the `argv` array, which is later used for command
 * execution.
 *
 * Return:
 * - The number of tokens parsed and stored in `argv`.
 */
int tokenize_input(char *line, char **argv)
{
	int i = 0; /* Counter for the number of tokens */

	/* Tokenize the input string */
	argv[i] = strtok(line, " ");
	while (argv[i] != NULL && i < 99) /* Limit tokens to 99 */
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}

	return (i); /* Return the number of tokens */
}
