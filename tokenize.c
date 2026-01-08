#include "hsh.h"

/**
 * tokenize - Splits line into array of arguments
 * @line: Input string
 * Return: Array of tokens
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

/**
 * free_tokens - Frees tokenized array
 * @tokens: Array to free
 */
void free_tokens(char **tokens)
{
	if (tokens)
		free(tokens);
}
