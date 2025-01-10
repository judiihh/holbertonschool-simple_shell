#include "main.h"

/**
 * execute_command - Executes a command in a child process.
 * @cmd: The full path to the command.
 * @argv: The arguments for the command.
 *
 * Return: Exit status of the executed command.
 */
int execute_command(char *cmd, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) /* Child process */
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror("./shell");
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) /* Parent process */
	{
		wait(&status); /* Wait for the child process */

		/* Return the exit status of the child process */
		if (WIFEXITED(status))
			return (WEXITSTATUS(status)); /* Exit status of the child */
	}
	else /* Fork failed */
	{
		perror("fork");
		free(cmd);
		exit(EXIT_FAILURE);
	}

	return (0);
}

/**
 * _fork - Handles the execution of a command, including built-ins.
 * @line: The input string containing the command to execute.
 *
 * Return: Exit status of the executed command, or 127 if command not found.
 */
int _fork(char *line)
{
	char *argv[100], *cmd;

	tokenize_input(line, argv);

	if (handle_builtins(line, argv))
		return (0);

	cmd = find_command_in_path(argv[0]);
	if (!cmd)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (127); /* Código estándar para "command not found" */
	}

	return (execute_command(cmd, argv));
}
