#include "main.h"

/**
 * main - Entry point of the simple shell program.
 *
 * Description:
 * This function provides a loop that acts as a command-line interface for
 * the user. It reads commands from standard input, removes unnecessary
 * whitespace, and passes the input to `_fork` for execution. The program
 * exits gracefully when EOF (Ctrl+D) is encountered.
 *
 * Return:
 * - The exit status of the last executed command.
 */
int main(void)
{
	char *line = NULL;   /* Pointer to hold the input line */
	size_t len = 0;      /* Buffer length for getline */
	ssize_t nread;       /* Number of characters read by getline */
	int exit_status = 0; /* Stores the exit status of the last command */

	while (1) /* Infinite loop for the shell */
	{
		/* Display the prompt only if the shell is running interactively */
		if (isatty(STDIN_FILENO))
			printf("($) ");

		/* Read a line of input from the user */
		nread = getline(&line, &len, stdin);
		if (nread == -1) /* Handle EOF (Ctrl+D) or read error */
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		/* Remove the trailing newline character from the input */
		line[strcspn(line, "\n")] = '\0';

		/* Ignore empty input lines (only whitespace) */
		if (strlen(line) == 0)
			continue;

		/* Pass the input line to _fork for execution and capture exit status */
		exit_status = _fork(line);
	}

	/* Free the memory allocated for the input line buffer */
	free(line);

	/* Return the exit status of the last executed command */
	return (exit_status);
}

