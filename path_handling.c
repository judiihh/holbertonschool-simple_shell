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
 * find_command_in_path - Finds the full path of a command.
 * @command: The command to search for in the PATH.
 *
 * Return:
 * - Pointer to a string containing the full path (on success).
 * - NULL if the command is not found.
 */
char *find_command_in_path(char *command)
{
	char *path, *path_copy, *token, *full_path;
	struct stat st;

	path = get_path_env();
	if (!path)
		return (NULL);

	path_copy = strdup(path); /* Create a copy of PATH */
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":"); /* Tokenize PATH */
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (stat(full_path, &st) == 0) /* Check if the command exists */
		{
			free(path_copy);
			return (full_path); /* Return the found command */
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy); /* Free the PATH copy */
	return (NULL); /* Command not found */
}

