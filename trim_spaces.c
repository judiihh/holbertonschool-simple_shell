#include "main.h"

/**
 * trim_spaces - Trims leading and trailing spaces from a string.
 * @line: The string to trim.
 *
 * Return: Pointer to the trimmed string.
 */
char *trim_spaces(char *line)
{
	char *start = line, *end;

	/* Trim leading spaces */
	while (*start && isspace((unsigned char)*start))
		start++;

	/* If the string is all spaces, return an empty string */
	if (*start == '\0')
		return (start);

	/* Trim trailing spaces */
	end = start + strlen(start) - 1;
	while (end > start && isspace((unsigned char)*end))
		end--;

	*(end + 1) = '\0'; /* Null-terminate the trimmed string */

	return (start);
}

