#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* Utility functions */
int execute_command(char *command);
char *read_line(void);
int check_exit(char *command);

extern char **environ;

#endif /* SIMPLE_SHELL_H */

