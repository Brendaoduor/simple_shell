#ifndef _MAIN_H_
#define _MAIN_H_

#define DELIM " \n\t\a\r:"
#include <string.h>

extern char **__environ;
int count_token(char *buffer, char *delim);
char **tokenize_line(char *buffer, char *delim, int token_no);
void exec_argv(char **argv);
char *_getenv(const char *name);
char *_strchr(char *str, int c);
void print_PATH(char *envVar, char *delim);

/**
 * struct builtins - it shows the builtins in our shell
 * @command: the command we entered
 * @func : function pointer to the actual command in the shell
 * that would be displayed
 * Description: structure for my_builtins
 */
typedef struct builtins
{
	char *command;
	void (*func)(char **);
} builtins;

/**
 * struct aliases - description for the aliases in our shell
 * @alias_name: the name we are searching for
 * @real_name: the actual name that would be returned from the shell
 */
typedef struct aliases
{
	char *alias_name;
	char *real_name;
} alias;

int builtin_size(void);
void shell_exit(char **args);
void shell_cd(char **args);
void shell_help(char **args);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int exec_builtin_commands(char **argv);
char **tokenize_PATH(char *envVar, char *delim);
char *find_path(char **pathTokens, char **argv);
char *append_to_directory(char *directory, char **argv, char *character);
void prompt(void);
void ctrl_C(int signum);
int print(char *var, int fd);
char *command_dir(char **cmd);

#endif
