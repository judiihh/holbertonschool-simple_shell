#include "main.h"

/**
 * _fork - Crea un proceso hijo y ejecuta un comando ingresado.
 * @line: Cadena que contiene el comando a ejecutar.
 *
 * Return: El PID del proceso hijo o -1 si falla.
 */
int _fork(char *line)
{
	pid_t pid;    /* ID del proceso hijo */
	int status;   /* Estado del proceso hijo */

	pid = fork(); /* Crear un proceso hijo */

	if (pid == 0) /* Código del hijo */
	{
		char *argv[2]; /* Array de argumentos (comando + NULL) */

		argv[0] = line;
		argv[1] = NULL;

		/* Ejecutar el comando */
		if (execve(argv[0], argv, environ) == -1)
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
	return (pid);
}
