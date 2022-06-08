#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



int _putchar(char c);
void _putstring(char *string);
int _strlen(const char *string);
char *_strcpy(char *dest, const char *src);
unsigned int count_space(char *string);
char **GetToken(char *string);

#endif