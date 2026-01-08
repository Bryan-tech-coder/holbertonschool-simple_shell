#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/* main */
int main(void);

/* shell loop */
void shell_loop(void);

/* execute */
void execute_cmd(char **argv);

/* tokenizer */
char **tokenize(char *line);

#endif
