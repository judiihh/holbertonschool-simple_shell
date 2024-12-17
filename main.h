#ifndef MAIN_H /* Protección contra inclusión múltiple */
#define MAIN_H

/* Inclusión de librerías necesarias */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ; /* Declarar la variable global del entorno */

/* Prototipos de funciones */
int _fork(char *line);

