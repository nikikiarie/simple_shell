#include "ni_shell.h"
/**
 * ni_cd - change direcrory
 * @a: double pointer
 * @i: index
 * Return: void
 */
void ni_cd(char **a, int i)
{
	char c[1024];
	char *d = NULL;
	char *l;

	if (i == 1 || strcmp(a[1], "~") == 0)
		d = ni_getenv("HOME");
	else if (strcmp(a[1], "-") == 0)
	{
		d = getenv("OLDPWD");
		if (d == NULL)
		{
			fprintf(stderr, "OLDPWD not set\n");
			return;
		}
		d = ni_getenv("OLDPWD");
	}
	else
		d = a[1];
	l = getenv("PWD");
	if (l == NULL)
	{
		fprintf(stderr, "PWD not set\n");
		return;
	}
	setenv("OLDPWD", l, 1);
	if (chdir(d) != 0)
		perror("error");
	else
	{
		if (getcwd(c, sizeof(c)) != NULL)
			setenv("PWD", c, 1);
		else
			perror("Error finding current working directory");
	}
}
/**
 * ni_exit - exits command
 * @p: pointer
 * @i: index
 * Return: void
 */
void ni_exit(char *p[], int i)
{
	int t;

	if (ni_strcmp(p[0], "exit") == 0)
	{
		if (i == 1)
			exit (0);
		if (i == 2 && ni_num(p[1]))
		{
			t = ni_atoi(p[1]);
			exit(t);
		}
	}
}
/**
 * ni_ls - runs ls
 * @a: pointer
 * @t: PID
 * Return: null
 */
void ni_ls(char **a, int t)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork not successful");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(a[0], a);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &t, 0);
}
/**
 * ni_env - prints env
 * Return: null
 */
void ni_env(void)
{
	ni_penv();
}
/**
 * ni_pwd - prints pwd
 * Return: null
 */
void ni_pwd(void)
{
	size_t d = 1024;
	char *c;
	char *c_d = (char *) malloc(d);

	if (c_d == NULL)
	{
		perror("Unable to allocate memory");
		exit(EXIT_FAILURE);
	}
	c = getcwd(c_d, d);
	if (c ==  NULL)
	{
		perror("Error finding current directory");
		free(c_d);
		exit(EXIT_FAILURE);
	}
	setenv("PWD", c, 1);
	write(STDOUT_FILENO, c, ni_strl(c));
	write(STDOUT_FILENO, "\n", 1);
	free(c_d);
}
