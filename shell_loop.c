#include "hsh.h"
#include <stdio.h>
#include <stdlib.h>

void shell_loop(void)
{
    char *line = NULL;
    char **args;
    size_t n;
    int status;

    while (1)
    {
        printf("$ ");
        if (getline(&line, &n, stdin) == -1)
            break;

        args = tokenize(line); // tu función tokenize
        if (!args)
            continue;

        status = execute_cmd(args);
        free(args);
    }

    free(line);
}
