#include "hsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	int status;
	char *line = NULL;
	size_t n = 0;

	while (1)
	{
		printf("$ "); /* prompt */
		if (getline(&line, &n, stdin) == -1)
		{
			printf("\n");
			break;
		}

		/* Aquí llamarás a shell_loop o tokenize según tu implementación */
		status = shell_loop(line);
		if (status == -1) /* condición para salir del shell */
			break;
	}

	free(line);
	return (0);
}
