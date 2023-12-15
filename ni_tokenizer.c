#include "ni_shell.h"
/**
 * ni_tokenizer - splits string
 * @cm: str
 * @d: delimeter
 * Return: void
 */
void ni_tokenizer(char *cm, char *d)
{
	char *a[100];
	char *tkn;
	int i = 0;

	if (cm == NULL)
		return;
	tkn = ni_strtok(cm, d);
	while (tkn != NULL)
	{
		if (tkn[0] != '#')
		{
			if (i > 0 && strcmp(a[i - 1], ";") == 0)
			{
				a[i - 1] = NULL;
				ni_exec(a);
				i = 0;
			}
			a[i] = tkn;
			i++;
		}
		else
			break;
	}
	a[i] = NULL;
	ni_exec(a);
}
/**
 * ni_exec - executes command
 * @a: command
 * Return: ptr
 */
void ni_exec(char **a)
{
	pid_t pid;
	char **env = environ;
	int i = 0, t = 0;

	if (a == NULL || a[0] == NULL)
		return;
	if (ni_strcmp(a[0], "cd") == 0)
		ni_cd(a, i);
	else if (ni_strcmp(a[0], "exit") == 0)
		ni_exit(&a[0], i);
	else if (ni_strcmp(a[0], "ls") == 0)
		ni_ls(a, t);
	else if (ni_strcmp(a[0], "unsetenv") == 0)
	{
		if (a[1] != NULL)
			ni_unset(a[1]);
		else
			perror("Unsetting env variable failed");
	}
	else if (ni_strcmp(a[0], "env") == 0)
		ni_env();
	else if (ni_strcmp(a[0], "setenv") == 0)
	{
		if (a[1] != NULL && a[2] != NULL)
			ni_setenv(a[1], a[2], 1);
		else
			perror("Arguments invalid");;
	}
	else if (ni_strcmp(a[0], "pwd") == 0)
		ni_pwd();
	else
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			execve(a[0], a, env);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &t, 0);
	}
}
