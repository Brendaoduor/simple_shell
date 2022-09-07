#include <stdio.h>
#include <string.h>
#include "shell.h"
#include <stdlib.h>

/**
 * _strchr - function that finds the character we are seaching
 * @str: the string we are using to parse for the character
 * @c: the character we are searching
 * Return: returns the character on success and NULL if it fails
 */
char *_strchr(char *str, int c)
{
	char *ptr;

	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr == c)
			return (ptr);
	}
	return (NULL);
}

