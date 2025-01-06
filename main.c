#include "main.h"
#include "commands.h"

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
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		/* Display the prompt */
		printf("($) ");

		/* Read user input */
		nread = getline(&line, &len, stdin);

		/* Handle EOF (Ctrl+D) */
		if (nread == -1)
		{
			printf("\n");
			break;
		}

		/* Remove trailing newline and trim spaces */
		line[strcspn(line, "\n")] = '\0';
		line = trim_spaces(line);

		/* Ignore empty input */
		if (strlen(line) == 0)
			continue;

		/* Execute commands */
		execute_commands(line);
	}

	free(line);
	return (0);
}
