#include "main.h"

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

