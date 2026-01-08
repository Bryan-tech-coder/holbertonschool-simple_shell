#include "hsh.h"

/**
 * tokenize - divide una línea en tokens (argumentos)
 * @line: línea de entrada
 * Return: array de strings terminado en NULL
 */
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

char **tokenize(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position++] = token;

		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
