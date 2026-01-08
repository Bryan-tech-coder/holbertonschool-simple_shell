#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Prototipos */
int execute_cmd(char **argv);
void shell_loop(void);
char **tokenize(char *line);
void free_tokens(char **tokens);

#endif /* HSH_H */
