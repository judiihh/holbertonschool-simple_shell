#include "main.h"

/**
 * _fork - Creates a child process to execute a command.
 * @line: The input string containing the command to execute.
 *
 * Description:
 * This function uses the `fork` system call to create a child process.
 * The child process executes the given command using the `execve` system call.
 * If the `execve` call fails, an error message is displayed using `perror`,
 * and the child process exits with `EXIT_FAILURE`.
 * The parent process waits for the child process to finish execution.
 *
 * Return:
 * - On success: The PID of the created child process.
 * - On failure: The function prints an error and exits the program.
 */
int _fork(char *line)
{
	pid_t pid;
	int status;

	pid = fork(); /* Create a child process */
	if (pid == 0) /* Child process */
	{
		char *argv[2]; /* Declare an array for the command and arguments */

		argv[0] = line; /* Assign the command */
		argv[1] = NULL; /* Null-terminate the argument list */

		if (execve(argv[0], argv, environ) == -1) /* Execute the command */
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) /* Parent process */
	{
		wait(&status); /* Wait for the child process to finish */
	}
	else /* Fork failed */
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return (pid);
}
