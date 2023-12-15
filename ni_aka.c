#include "ni_shell.h"
/**
 * ni_printaka - printts alias
 * Return: null
 */
void ni_printaka(void)
{
	int c = 0, i;
	struct aka ab[MAX_A_COUNT];

	for (i = 0; i < c; i++)
		printf("%s = '%s'\n", ab[i].n, ab[i].v);
}
/**
 * ni_setaka - modify alias
 * @a: name
 * @z: string
 * Return: null
 */
void ni_setaka(char *a, char *z)
{
	int c = 0, i;
	struct aka b[MAX_A_COUNT];

	if (c >= MAX_A_COUNT)
	{
		printf("Error: Too many alias\n");
		return;
	}
	for (i = 0; i < c; i++)
	{
		if (strcmp(b[i].n, a) == 0)
		{
			ni_strcpy(b[i].v, z);
			return;
		}
	}
	ni_strcpy(b[c].n, a);
	ni_strcpy(b[c].v, z);
	c++;
}
/**
 * ni_handleaka - handles alias command
 * @b: string
 * Return: null
 */
void ni_handleaka(char *b)
{
	char *tkn;
	int i, c = 0;
	char n[MAX_A_NAME];
	char v[MAX_A_VALUE];
	struct aka a[MAX_A_COUNT];

	if (ni_strl(b) == 5)
	{
		ni_printaka();
		return;
	}
	tkn = strtok(b + 6, "=");
	ni_strcpy(n, tkn);
	tkn = strtok(NULL, "=");
	if (tkn == NULL)
	{
		for (i = 0; i < c; i++)
		{
			if (strcmp(a[i].n, n) == 0)
			{
				printf("%s = '%s'\n", a[i].n, a[i].v);
			}
		}
	}
	else
	{
		ni_strcpy(v, tkn);
		ni_setaka(n, v);
	}
}
