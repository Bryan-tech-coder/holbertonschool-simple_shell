#include "hsh.h"

/**
 * tokenize - separa una línea en tokens usando espacio como delimitador
 * @line: línea de entrada
 * 
 * Return: arreglo de strings terminado en NULL
 */
char **tokenize(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	size_t i = 0, count = 0;

	if (line == NULL)
		return (NULL);

	/* contar tokens */
	token = strtok(line, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}

	if (count == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);

	/* volver a tokenizar para llenar el arreglo */
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * free_tokens - libera memoria de un arreglo de tokens
 * @tokens: arreglo de strings terminado en NULL
 */
void free_tokens(char **tokens)
{
	size_t i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}
