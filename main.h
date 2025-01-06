#ifndef MAIN_H
#define MAIN_H

/* Include necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Declare external variables */
extern char **environ;

/* Function prototypes */
int _fork(char *line);

#endif /* MAIN_H */
