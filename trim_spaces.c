#include "main.h"

/**
 * _isspace - Checks if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if the character is a whitespace, 0 otherwise.
 */
int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r');
}

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
	while (*start && _isspace(*start))
		start++;

	/* If the string is all spaces, return an empty string */
	if (*start == '\0')
		return (start);

	/* Trim trailing spaces */
	end = start + strlen(start) - 1;
	while (end > start && _isspace(*end))
		end--;

	*(end + 1) = '\0'; /* Null-terminate the trimmed string */

	return (start);
}
