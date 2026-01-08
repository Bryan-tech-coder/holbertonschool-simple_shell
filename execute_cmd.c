#include "hsh.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * execute_cmd - Ejecuta un comando externo
 * @argv: array de argumentos, argv[0] es el comando
 * Return: 0 si éxito, otro valor si error
 */
int execute_cmd(char **argv)
{
	pid_t pid;
	int status;

	if (argv[0] == NULL)
		return (1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}
