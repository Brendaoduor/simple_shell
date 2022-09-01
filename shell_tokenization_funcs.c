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

