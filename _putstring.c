#include "shell.h"

/**
 * @brief _putstring prints a string
 * 
 * @param string the string to be printed
 * @return ** void 
 */
void _putstring(char *string)
{
int count = 0;
while (string[count])
{
	_putchar(string[count++]);
}
}