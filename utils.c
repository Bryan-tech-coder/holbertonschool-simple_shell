#include "hsh.h"

/**
 * free_args - libera array de strings
 * @args: array de strings
 */
void free_args(char **args)
{
	free(args);
}

/**
 * _strcmp - compara dos strings
 * @s1: primer string
 * @s2: segundo string
 * Return: 0 si son iguales, != 0 si no
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
