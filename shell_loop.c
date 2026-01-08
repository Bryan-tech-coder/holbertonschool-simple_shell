#include "hsh.h"

/**
 * shell_loop - Bucle principal del shell
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	char **args;
	int status;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &bufsize, stdin) == -1)
			break;

		args = tokenize(line);
		if (args == NULL)
			continue;

		status = execute_cmd(args);
		(void)status; /* Evita warning si no usamos status */

		free_args(args);
	}
	free(line);
}
