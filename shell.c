#include "hsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/**
 * execute_cmd - ejecuta un comando usando fork y execvp
 * @argv: arreglo de argumentos, argv[0] es el comando
 * 
 * Return: estado de salida del hijo, o -1 si hubo error
 */
int execute_cmd(char **argv)
{
	pid_t pid;
	int status;

	if (argv == NULL || argv[0] == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0) /* proceso hijo */
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else /* proceso padre */
	{
		waitpid(pid, &status, 0);
	}

	return (status);
}
