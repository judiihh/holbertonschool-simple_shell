#include "main.h"

/**
 * get_path_env -Retrieves the value of the PATH or PATH1 environment variable.
 *
 * Return: Pointer to the value of PATH or PATH1, or NULL if not found.
 */
char *get_path_env(void)
{
	int i = 0;

	/* Buscar PATH primero */
	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5); /* Omitir "PATH=" */
		i++;
	}

	/* Si PATH no existe, buscar PATH1 */
	i = 0;
	while (environ[i])
	{
		if (strncmp(environ[i], "PATH1=", 6) == 0)
			return (environ[i] + 6); /* Omitir "PATH1=" */
		i++;
	}

	return (NULL); /* Ninguna ruta encontrada */
}

/**
 * find_command_in_path - Finds the full path of a command.
 * @command: The command to search for.
 *
 * Return: Pointer to a string containing the full path, or NULL if not found.
 */
char *find_command_in_path(char *command)
{
	char *path, *token, *full_path;
	struct stat st;

	/* If command is already an absolute path */
	if (command[0] == '/' && stat(command, &st) == 0)
		return (strdup(command));

	/* Get PATH environment variable */
	path = get_path_env();
	if (!path)
		return (NULL);

	/* Tokenize and search */
	token = strtok(strdup(path), ":");
	while (token)
	{
		full_path = get_full_path(token, command);
		if (stat(full_path, &st) == 0)
		{
			free(token);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * get_full_path - Constructs the full path for a command in a given directory.
 * @dir: Directory path.
 * @command: Command name.
 *
 * Return: Pointer to the constructed full path (must be freed by the caller).
 */
char *get_full_path(char *dir, char *command)
{
	char *full_path;
	size_t len;

	len = strlen(dir) + strlen(command) + 2; /* +2 for '/' and null terminator */
	full_path = malloc(len);
	if (full_path)
		snprintf(full_path, len, "%s/%s", dir, command);

	return (full_path);
}
