#include "hsh.h"

/**
 * tokenize - splits line into arguments
 * @line: input line
 * Return: array of strings (arguments)
 */
char **tokenize(char *line)
{
    char **args = malloc(64 * sizeof(char *));
    char *token;
    int i = 0;

    if (!args)
        exit(EXIT_FAILURE);

    token = strtok(line, " \t\n");
    while (token)
    {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return args;
}
