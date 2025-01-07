#include "main.h"
#include <sys/stat.h>

/**
 * tokenize_input - Tokenizes the input string into arguments.
 * @line: Input string containing the command.
 * @argv: Array to store the arguments.
 *
 * Return: Number of tokens parsed.
 */
int tokenize_input(char *line, char **argv)
{
	int i = 0;

	argv[i] = strtok(line, " ");
	while (argv[i] != NULL && i < 99)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	return (i);
}

/**
 * find_command - Finds the full path of the command.
 * @argv: Array of arguments, with the command as argv[0].
 *
 * Return: Pointer to the command path, or NULL if not found.
 */
char *find_command(char **argv)
{
	static char full_cmd[1024];
	struct stat st;
	char *path = getenv("PATH"), *token;

	if (stat(argv[0], &st) == 0)
		return (argv[0]);

	if (path)
	{
		char *path_copy = strdup(path);

		if (!path_copy)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		token = strtok(path_copy, ":");
		while (token)
		{
			snprintf(full_cmd, sizeof(full_cmd), "%s/%s", token, argv[0]);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_copy);
				return (full_cmd);
			}
			token = strtok(NULL, ":");
		}
		free(path_copy);
	}

	return (NULL);
}

/**
 * _fork - Creates a child process to execute a command.
 * @line: The input string containing the command to execute.
 *
 * Return: On success, the PID of the created child process.
 *         On failure, -1.
 */
int _fork(char *line)
{
	pid_t pid;
	int status;
	char *argv[100];
	char *cmd;

	tokenize_input(line, argv);
	cmd = find_command(argv);

	if (!cmd)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		return (-1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		wait(&status);
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return (pid);
}
