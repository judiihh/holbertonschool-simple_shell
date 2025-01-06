#include "main.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;   /* Buffer for input line */
	size_t len = 0;      /* Buffer size */
	ssize_t nread;       /* Number of characters read */

		while (1)
		{
			/* Display the prompt if input is interactive */
			if (isatty(STDIN_FILENO))
				printf("($) ");
			
			/* Read user input */
			nread = getline(&line, &len, stdin);
			
			/* Handle EOF (Ctrl+D) */
			if (nread == -1)
			{
				if (isatty(STDIN_FILENO))
					printf("\nExiting shell...\n");
				break;
			}
			
			/* Remove trailing newline */
			line[strcspn(line, "\n")] = '\0';
			
			/* Skip empty lines */
			if (line[0] == '\0')
				continue;
			
			/* Execute the command */
			_fork(line);
		}
		
		free(line); /* Free memory allocated by getline */
		return (0);
}
