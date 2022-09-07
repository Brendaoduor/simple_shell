#include <stdio.h>
#include <string.h>
#include "shell.h"

char *_strchr(char *str, int c)
{
	char *ret;

	ret = _strchr(str, c);

	if (ret != NULL)
		printf("%s\n", ret);
	else
		printf("no such character\n");
	return (NULL);
}
	
