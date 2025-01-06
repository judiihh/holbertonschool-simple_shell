#ifndef MAIN_H /* Include guard */
#define MAIN_H

/* Include necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ; /* Global environment variable */

/* Function prototypes */
/**
 * _fork.c - Creates a child process and executes a command.
 * @line: Input string containing the command.
 *
 * Return: PID of the child process, or -1 on failure.
 */
int _fork(char *line);

#endif /* MAIN_H */
