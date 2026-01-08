#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes */
void shell_loop(void);
void execute_cmd(char **argv);
char **tokenize(char *line);
void free_tokens(char **tokens);
int _strcmp(const char *s1, const char *s2);

#endif /* HSH_H */
