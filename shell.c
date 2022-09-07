#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <signal.h>
#include <unistd.h>

/**
 * main - Enrty point for our unix command line interpreter
 * Return: 0 on succes
 */

int main(void)
{
	char *buffer = NULL;
	char duplicate_buffer[1024];
	char **argv;
	ssize_t num_read;
	size_t n = 0;
	int int_mode, num_tokens;

	signal(SIGINT, ctrl_C);

	while (1)
	{

		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
			print("$ ", STDIN_FILENO);
		num_read = getline(&buffer, &n, stdin);

		if (num_read == -1)
		{
			free(buffer);
			return (-1);
		}

		_strcpy(duplicate_buffer, buffer);
		num_tokens = count_token(duplicate_buffer, DELIM);
		argv = tokenize_line(buffer, DELIM, num_tokens);

		if (argv[0] != NULL)
		exec_argv(argv);
	}

	free(buffer);
	return (0);
}
