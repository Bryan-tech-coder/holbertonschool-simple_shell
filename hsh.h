#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Prototipos */
int execute_cmd(char **argv);
void shell_loop(void);
char **tokenize(char *line);
void free_args(char **args);
int _strcmp(const char *s1, const char *s2);

#endif /* HSH_H */
