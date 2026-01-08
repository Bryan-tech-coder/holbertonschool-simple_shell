#include "hsh.h"

/**
 * shell_loop - lee una línea, tokeniza y ejecuta comandos
 */
void shell_loop(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    char **args;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        free(line);
        exit(EXIT_SUCCESS);  /* Ctrl+D termina la shell */
    }

    args = tokenize(line);     /* Separa en tokens */
    if (args[0] != NULL)
        execute_cmd(args);     /* Ejecuta el comando */

    free_tokens(args);
    free(line);
}
