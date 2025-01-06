#include "main.h"

/**
 * _fork - Creates a child process and executes a command.
 * @line: Input string containing the command to execute.
 *
 * Return: The PID of the child process, or -1 on failure.
 */
int _fork(char *line)
{
	pid_t pid;
	int status;

	pid = fork(); /* Create a child process */

	if (pid == 0) /* Child process */
	{
		char *argv[2]; /* Array of arguments (command + NULL) */

		argv[0] = line;
		argv[1] = NULL;

		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) /* Parent process */
	{
		wait(&status); /* Wait for the child process to terminate */
	}
	else /* Error in fork */
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return (pid);
}
