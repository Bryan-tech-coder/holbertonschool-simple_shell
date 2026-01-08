#include "hsh.h"

/**
 * _strlen - returns length of string
 * @s: input string
 * Return: length
 */
int _strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

/**
 * _strcpy - copies string from src to dest
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
