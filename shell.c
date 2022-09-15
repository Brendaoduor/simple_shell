#include "shell.h"
#include <errno.h>
/**
 * main - Enrty point for our unix command line interpreter
 * @argc: Argument counter
 * @argv: Argument vectors
 * Return: 0 on succes
 */

int main(int argc __attribute__((unused)), char **argv)
{

	char *buffer = NULL;
	char *duplicate_buffer = NULL;
	char **arg = NULL;
	ssize_t num_read;
	size_t n = 0;
	int num_tokens, count = 0, exit_loop = 1;

	if  (argc < 1)
		return (-1);

	signal(SIGINT, ctrl_C);

	while (exit_loop)
	{

		count++;
		exit_loop = prompt();
		num_read = getline(&buffer, &n, stdin);

		if (num_read == -1)
		{
			errno = 0;
			return (-1);
		}

		duplicate_buffer = _strdup(buffer);
		num_tokens = count_token(duplicate_buffer, DELIM);
		arg = tokenize_line(buffer, DELIM, num_tokens);

		if (arg[0] != NULL)
			exec_cmd(arg, argv, count);
	}
	if (num_read < 0 && flag.interactive)
		write(STDERR_FILENO, "\n", 1);

	free(duplicate_buffer);
	return (0);
}
