#include "main.h"

/**
 * main - Entry point of the Simple Shell program
 *
 * Description: This function provides a command-line interface for the user.
 * It continuously displays a prompt, reads user input, trims spaces,
 * and executes the commands using child processes. The program exits
 * gracefully when EOF (Ctrl+D) is encountered.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	char *line = NULL;
	char *trimmed_line; /* Declare variable at the top of the block */
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		/* Display the prompt only if the shell is interactive */
		if (isatty(STDIN_FILENO))
			printf("($) ");

		/* Read user input */
		nread = getline(&line, &len, stdin);

		/* Handle EOF (Ctrl+D) */
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		/* Remove trailing newline */
		line[strcspn(line, "\n")] = '\0';

		/* Trim leading and trailing spaces */
		trimmed_line = trim_spaces(line);

		/* Ignore empty input */
		if (strlen(trimmed_line) == 0)
			continue;

		/* Execute commands using _fork */
		_fork(trimmed_line);
	}

	free(line); /* Free the original buffer allocated by getline */
	return (0);
}
