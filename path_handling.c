#include "main.h"

/**
 * get_path_env - Retrieves the value of the PATH environment variable.
 *
 * Return: Pointer to the value of the PATH variable, or NULL if not found.
 */
char *get_path_env(void)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5); /* Skip "PATH=" */
		i++;
	}
	return (NULL);
}

/**
 * check_command_permissions - Checks if a command has execution permission.
 * @command: The command to check.
 * @st: The stat structure containing file info.
 *
 * Return: 1 if the command is executable, 0 otherwise.
 */
int check_command_permissions(char *command, struct stat *st)
{
	if (!(st->st_mode & S_IXUSR))
	{
		fprintf(stderr, "%s: Permission denied\n", command);
		return (0);
	}
	return (1);
}

/**
 * find_command_in_path - Finds the full path of a command.
 * @command: The command to search for.
 *
 * Return: Pointer to a string containing the full path, or NULL if not found.
 */
char *find_command_in_path(char *command)
{
	struct stat st;
	char *path, *path_copy, *token, *full_path;

	if (stat(command, &st) == 0 && check_command_permissions(command, &st))
		return (strdup(command));

	path = get_path_env();
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (stat(full_path, &st) == 0 && check_command_permissions(command, &st))
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}




