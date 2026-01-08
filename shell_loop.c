#include "hsh.h"

/**
 * shell_loop - Reads a line, tokenizes it, and executes command
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	args = tokenize(line);
	if (args)
		execute_cmd(args);

	free_tokens(args);
	free(line);
}
