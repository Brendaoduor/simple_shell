<F3><F3><F3><F3><F3><F3><F3>#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

/**
 * shell_cd - Function to change working directory
 * @args: Array of commands
 * Return: Nothing
 */

void shell_cd(char **args)
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
}


void shell_help(char **args)
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
}


void shell_exit(char **args)
{
	if (args != NULL)
	exit(0);
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
		if (_strcmp(my_builtin[i].command, argv[0]) == 0)
		{
			my_builtin[i].func(argv);
			return (0);
		}
	}
	return (-1);
}
