#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <signal.h>
#include <unistd.h>

/**
 * main - Enrty point for our unix command line interpreter
 * @argc: Argument counter
 * @argv: Argument vectors
 * Return: 0 on succes
 */

int main(int argc __attribute__((unused)), char **argv)
{

	char *buffer = NULL;
	char duplicate_buffer[1024];
	char **arg;
	ssize_t num_read;
	size_t n = 0;
	int num_tokens, count = 0;

	if  (argc < 1)
		return (-1);

	signal(SIGINT, ctrl_C);

	while (1)
	{
		count++;
		prompt();
		num_read = getline(&buffer, &n, stdin);

		if (num_read == -1)
		{
			return (-1);
		}

		_strcpy(duplicate_buffer, buffer);
		num_tokens = count_token(duplicate_buffer, DELIM);
		arg = tokenize_line(buffer, DELIM, num_tokens);

		if (argv[0] != NULL)
		exec_argv(arg, argv, count);
	}
	if (num_read < 0 && flag.interactive)
		write(STDERR_FILENO, "\n", 1);

	free(arg);
	free(buffer);
	return (0);
}
