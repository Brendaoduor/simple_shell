#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"


/**
 * prompt - pritns the prompt for our simple shell
 * Return: Nothing
 */

void prompt(void)
{
	char cwd[1024], *username;

	getcwd(cwd, sizeof(cwd));
	username = _getenv("USER");
	printf("@%s:", username);
	printf("%s$ ", cwd);
}

/**
 * _getenv - A function that gets env path passed to it
 * @name: Env name to get the path
 * Return: A pointer containing the path for the env passed to it
 */

char *_getenv(const char *name)
{
	int len, i = 0;

	if (name == NULL)
		return (NULL);
	len = _strlen(name);

	while (__environ[i] != NULL)
	{
		if (_strncmp(name, __environ[i], len) == 0)
		break;
		i++;
	}
	return (__environ[i]);
}

/**
 * tokenize_PATH - Tokenizes the string into substrings using delim
 * @envVar: A pointer to the string to be tokeni
 * @delim: Array of characters containing delimiters for tokenization
 * Return: Array of tokenized substings
 */

char **tokenize_PATH(char *envVar, char *delim)
{
	char **tokenized_path = NULL;
	ssize_t num_substrings;
	char envVar_duplicate[1024];

	_strcpy(envVar_duplicate, envVar);
	num_substrings = count_token(envVar_duplicate, delim);

	tokenized_path = malloc(sizeof(char *) * num_substrings);
	if (tokenized_path == NULL)
	{
		perror("Malloc unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	tokenized_path = tokenize_line(envVar, delim, num_substrings);

	return (tokenized_path);
}

/**
 * append_to_directory - Append a '/' and command name to the end of a dir
 * @directory: Command directory where character and command is to be appended
 * @argv: Array of command passed by user
 * @character: Character to be appended to directory
 * Return: Pointer to newly created string
 */

char *append_to_directory(char *directory, char **argv, char *character)
{
	char *temp;
	int buff_size;

	if (directory == NULL)
		return (argv[0]);

	buff_size = (_strlen(directory) + _strlen(argv[0]) + 1);
	temp = malloc(sizeof(char) * buff_size);
	if (temp == NULL)
	{
		perror("malloc unable to allocate space\n");
		exit(EXIT_FAILURE);
	}
	_strcpy(temp, directory);
	_strcat(temp, character);
	_strcat(temp, argv[0]);

	return (temp);
}

/**
 * exec_argv - Function to execute command
 * @argv: An array of commands to be executed
 * Return: Nothing
 */

void exec_argv(char **argv)
{
	pid_t pid;
	char *cmd_path;
	int ch = '/';

	if (exec_builtin_commands(argv) == 0)
		return;
	/*cmd_path = command_dir(argv);*/
	cmd_path = argv[0];
	if (strchr(argv[0], ch) == NULL)
		cmd_path = append_to_directory("/bin", argv, "/");

	cmd_path = append_to_directory("/bin", argv, "/");

	pid = fork();
	if (pid == -1)
	{
		perror("Unable to create child process\n");
		return;
	}
	else if (pid == 0)
	{
		if (execve(cmd_path, argv, __environ) == -1)
		{
			printf("%s: command not found\n", argv[0]);
			return;
		}
	}
	else
	{
		wait(NULL);
	}
}
