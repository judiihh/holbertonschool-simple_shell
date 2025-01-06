#include "main.h"

/**
 * _fork - Creates a child process and executes a command.
 * @line: Input string containing the command.
 *
 * Return: PID of the child process, or -1 on failure.
 */
int _fork(char *line)
{
	pid_t pid;    /* Child process ID */
	int status;   /* Child process status */

	pid = fork(); /* Create a child process */

	if (pid == 0) /* Child process code */
	{
		char *argv[2]; /* Command arguments */

		argv[0] = line; /* Command */
		argv[1] = NULL; /* NULL-terminate arguments */

		/* Execute the command */
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell"); /* Print error if execve fails */
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) /* Parent process code */
	{
		wait(&status); /* Wait for child process to complete */
	}
	else /* Error in fork */
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return (pid);
}
