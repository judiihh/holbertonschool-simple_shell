#include <string.h>

/**
 * trim_spaces - Removes leading and trailing spaces from a string
 * @line: Input string
 *
 * Return: Pointer to the trimmed string
 */
char *trim_spaces(char *line)
{
	char *start = line;
	char *end;

	/* Trim leading spaces */
	while (*start == ' ')
		start++;

	/* Trim trailing spaces */
	end = start + strlen(start) - 1;
	while (end > start && *end == ' ')
		*end-- = '\0';

	return (start);
}
