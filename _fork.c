#include "main.h"

/**
 * execute_command - Executes a command by forking a child process.
 * @cmd: Full path to the command.
 * @argv: Array of arguments.
 *
 * Return: PID of the child process, or -1 on failure.
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
		wait(&status);
	else /* Fork failed */
	{
		perror("fork");
		free(cmd);
		exit(EXIT_FAILURE);
	}

	free(cmd);
	return (pid);
}

/**
 * handle_builtins - Handles built-in commands like "exit" and "env".
 * @line: Input line.
 * @argv: Tokenized arguments.
 *
 * Return: 1 if a built-in command was executed, 0 otherwise.
 */
int handle_builtins(char *line, char **argv)
{
	if (argv[0] && strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(0); /* Exit the shell */
	}

	if (argv[0] && strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0);
}

/**
 * _fork - Handles the execution of a command, including built-ins.
 * @line: The input string containing the command to execute.
 *
 * Return: PID of the child process, or -1 on failure.
 */
int _fork(char *line)
{
	char *argv[100], *cmd;

	/* Tokenize input */
	tokenize_input(line, argv);

	/* Handle built-in commands */
	if (handle_builtins(line, argv))
		return (0);

	/* Find command in PATH */
	cmd = find_command_in_path(argv[0]);
	if (!cmd)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		return (-1);
	}

	/* Execute the command */
	return (execute_command(cmd, argv));
}
