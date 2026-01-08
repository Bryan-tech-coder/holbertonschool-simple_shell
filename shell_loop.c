#include "shell.h"

/**
 * shell_loop - reads input, tokenizes and executes commands
 */
void shell_loop(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args;
    int status;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(1, "($) ", 4);

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }

        line[nread - 1] = '\0'; /* remove newline */
        args = tokenize(line);
        if (args[0] != NULL)
            status = execute_cmd(args);

        free(args);
    }
}
