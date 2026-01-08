#include "hsh.h"

/**
 * shell_loop - bucle principal de la shell
 * 
 * Este bucle lee línea por línea, tokeniza y ejecuta comandos.
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1) /* EOF o error */
			break;

		/* Remover el salto de línea */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = tokenize(line);
		if (args == NULL)
			continue;

		execute_cmd(args);

		free_tokens(args);
	}

	free(line);
}
