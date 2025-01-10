#include "main.h"

/**
 * get_path_env - Retrieves the value of the PATH or PATH1
 * environment variable.
 *
 * Return: Pointer to the value of PATH or PATH1, or NULL if not found.
 */
char *get_path_env(void)
{
	int i = 0;

	/* Check for PATH */
	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5); /* Skip "PATH=" */
		i++;
	}

	/* Check for PATH1 */
	i = 0;
	while (environ[i])
	{
		if (strncmp(environ[i], "PATH1=", 6) == 0)
			return (environ[i] + 6); /* Skip "PATH1=" */
		i++;
	}

	return (NULL); /* No valid path found */
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

	/* Check if the command is an absolute or relative path */
	if (strchr(command, '/') && stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
		return (strdup(command));

	/* Get PATH or PATH1 */
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

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path); /* Command found */
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL); /* Command not found */
}
