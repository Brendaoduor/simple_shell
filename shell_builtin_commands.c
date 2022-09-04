#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("cd: missing argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd\n");
	}
	return (1);
}


int shell_help(char **args)
{
	if (args != NULL)
	{
	char *helptext =
		"The following are the only commands available\n"
		"cd 	change the working directory\n"
		"exit	exits the shell.\n"
		"help	print this help text\n";

	printf("%s", helptext);
	}

	return (1);
}


int shell_exit(char **args __attribute__((unused)))
{
		exit(0);
	return (1);
}


int exec_builtin_commands(char **argv)
{
	int builtin_size, i;
	struct builtins my_builtin[] = {
		{"exit", shell_exit},
		{"cd", shell_cd},
		{"help", shell_help},
	};

	builtin_size = sizeof(my_builtin) / sizeof(struct builtins);

	for (i = 0; i < builtin_size; i++)
	{
		if (_strcmp(argv[0], my_builtin[i].command) == 0)
		{
			my_builtin[i].func(argv);
			return (0);
		}
	}
	return (-1);
}
