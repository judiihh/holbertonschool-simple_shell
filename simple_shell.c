#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ; /* Variable global para el entorno */

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
	pid_t pid;           /* ID del proceso hijo */
	int status;          /* Estado del proceso hijo */

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

		pid = fork(); /* Crear un proceso hijo */

		if (pid == 0) /* Código del hijo */
		{
			char *argv[2]; /* Array de argumentos (comando + NULL) */
			argv[0] = line;
			argv[1] = NULL;

			if (execve(argv[0], argv, environ) == -1) /* Ejecutar el comando */
			{
				perror("./shell"); /* Imprimir mensaje de error si execve falla */
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0) /* Código del padre */
		{
			wait(&status); /* Esperar a que el proceso hijo termine */
		}
		else /* Error en fork */
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}

	free(line); /* Liberar la memoria asignada por getline */
	return (0);
}
