#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_token(char *buffer, char *delim)
{
	char *token;
	int token_no = 0;


		if (buffer == NULL)
		return (token_no);

	token = strtok(buffer, delim);
	token_no++;

	while (token != NULL)
	{
		token = strtok(NULL, delim);
		token_no++;
	}
	free(token);
	return (token_no);
}
char **tokenize_line(char *buffer, char *delim, int token_no)
{
	char *token = NULL;
	char **argv;
	int a = 0;

	argv = malloc(sizeof(char *) * token_no);

	if (argv == NULL)
	{
		perror("no space allocated\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	
	token = strtok(buffer, delim);
	
	while (token)
	{
		argv[a] = token;
		a++;
		token = strtok(NULL, delim);
	}
	argv[a] = NULL;
	
	return (argv);
}
char *_strncpy(char *dest, char *src)
{
	char *copy = dest;

	while (*src)
	{
		*dest++ = *src++;
		return (copy);
	}
}

int _strcmp(char *s1, char *s2)
{
	while ((s1 && s2) != NULL)
	{
		if (s1 != s2)
		{
			return (*s1 - *s2)
		}
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}

