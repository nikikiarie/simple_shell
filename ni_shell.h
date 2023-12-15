#ifndef NI_SHELL_H
#define NI_SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_A_COUNT 100
#define MAX_A_NAME 50
#define MAX_A_VALUE 100

struct aka
{
	char n[MAX_A_NAME];
	char v[MAX_A_VALUE];
};

extern char **environ;

char *ni_strcpy(char *a, char *z);
void ni_printaka(void);
void ni_handleaka(char *i);
void ni_setaka(char *a, char *z);
void ni_penv(void);
char *ni_strchr(const char *c, int i);
void ni_tokenizer(char *cm, char *d);
void ni_exec(char **a);
char *ni_strtok(char *s, const char *d);
size_t ni_strcspn(const char *p, const char *z);
size_t ni_strspn(const char *s, const char *d);
int ni_strlen(char *a);
char *ni_line(char *l, int *i, int s);
char *ni_getline(char *b, int *p, int by, int *l);
int ni_input(char *b);
int ni_num(char *c);
void ni_memcpy(char *a, const char *z, size_t i);
int ni_atoi(char *s);
void ni_env(void);
void ni_pwd(void);
void ni_ls(char **a, int t);
void ni_exit(char *p[], int i);
void ni_cd(char **a, int i);
int ni_unset(char *s);
int ni_setenv(char *a, char *r, int z);
size_t ni_strln(const char *s);
char *ni_getenv(const char *a);
unsigned int ni_strl(const char *a);
int ni_strcmp(const char *a, const char *z);
int ni_strncmp(const char *a, const char *z, size_t i);
#endif
