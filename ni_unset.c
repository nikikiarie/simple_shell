#include "ni_shell.h"
/**
 * ni_unset - unsets env
 * s: env
 * Return: 0
 */
int ni_unset(char *s)
{
	int i = unsetenv(s);

	if (i == -1)
	{
		perror("Error unsetting env");
		return (1);
	}
	return (0);
}
