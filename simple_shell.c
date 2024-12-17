#include "main.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;   /* Buffer para la línea ingresada */
	size_t len = 0;      /* Tamaño del buffer */
	ssize_t nread;       /* Número de caracteres leídos */
		while (1)
	{
		/* Mostrar el prompt solo si la entrada es interactiva */
		if (isatty(STDIN_FILENO))
			printf("($) ");

		/* Leer la entrada del usuario */
		nread = getline(&line, &len, stdin);

		/* Manejar EOF (Ctrl+D) */
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\nExiting shell...\n");
			break;
		}

		/* Eliminar el salto de línea al final */
		line[strcspn(line, "\n")] = '\0';

		/* Ignorar líneas vacías */
		if (strlen(line) == 0)
			continue;

		/* Llamar a _fork para ejecutar el comando */
		_fork(line);
	}

	free(line); /* Liberar la memoria asignada por getline */
	return (0);
}
