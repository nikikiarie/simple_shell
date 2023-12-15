#include "ni_shell.h"
/**
 * ni_setenv - set env
 * @a: string
 * z: env
 * r: str to set
 * Return: int
 */
int ni_setenv(char *a, char *r, int z)
{
	int i = setenv(a, r, z);

	if (i == -1)
		perror("Error setting env");
	return (0);

}
