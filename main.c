#include "main.h"

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("($) ");
}

/**
 * main - Entry point of the Simple Shell program
 *
 * Return: Exit status of the last executed command.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int exit_status = 0;

	while (1)
	{
		display_prompt();
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (strlen(line) == 0)
			continue;

		exit_status = _fork(line);
	}

	free(line);
	return (exit_status);
}

