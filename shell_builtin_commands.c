#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
	if (args[1] != NULL)
	{
	char *helptext =
		"the following are the only commands available\n"
		"cd	change the working directory\n"
		"exit	exits the shell.\n"
		"help	print this help text\n";
	printf("%s", helptext);
	}

return (1);
}

int shell_exit(char **args)
{
	if (args[1] == NULL)
		return (0);
	return (0);
}
