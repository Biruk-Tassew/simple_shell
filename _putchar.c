#include "shell.h"

/**
 * @brief puts a character into stdout
 * 
 * @param c the character needed in stdout
 * @return ** int -1 if there is an error or 0
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}