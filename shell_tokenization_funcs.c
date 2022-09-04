#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "shell.h"
#include <unistd.h>

/**
 * count_token - Finds the number of substrings in a string
 * @buffer: Pointer to the string to tokenize
 * @delim: Delimiter to be used for tokenization
 * Return: Number of substrings or tokens
 */

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

/**
 * tokenize_line - A function to break strings into substrings
 * @buffer: Pointer to string to be tokenized
 * @delim: Delimiters to be used for tokenization
 * Return: Array of pointers containing the substrings
 */

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


/**
 * ctrl_C - Assigning ctrl C as kill signal
 * @signum: signum
 * Return: Nothing
 */

void ctrl_C(int signum)
{
	if (signum == SIGINT)
		print("\n$ ", STDIN_FILENO);
}


/**
 * print - A function that prints to a file descriptor
 * @var: Variable to be printed
 * @fd: File descriptor
 * Return: 0 0n success, -1 0n failure
 */

int print(char *var, int fd)
{
	return (write(fd, var, _strlen(var)));
}
