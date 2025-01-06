#include "commands.h"
#include "main.h"

/**
 * execute_commands - Executes a list of commands separated by spaces.
 * @line: The input line containing commands to execute.
 *
 * Description: This function tokenizes the input line into separate commands,
 * creates a child process for each command, and executes them.
 * Each command is assumed to be a valid path to an executable.
 * If a command fails, an error message is printed using perror.
 */

void execute_commands(char *line)
{
	char *command;
	char *delim = " ";

	/* Split input line into commands */
	command = strtok(line, delim);
	while (command != NULL)
	{
		if (fork() == 0)
		{
			char *argv[2];

			argv[0] = command;
			argv[1] = NULL;

			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL); /* Wait for child process */
		}

		/* Get the next command */
		command = strtok(NULL, delim);
	}
}
