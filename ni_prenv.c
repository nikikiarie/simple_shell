#include "ni_shell.h"
/**
 * ni_penv - prints env
 * Return: void
 */
void ni_penv(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
