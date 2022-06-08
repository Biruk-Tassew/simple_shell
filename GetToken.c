#include "shell.h"

/**
 * @brief count_space counts the nuber of space chrs in a string
 * 
 * @param string the string from which spaces are counted
 * @return ** unsigned int number of spaces
 */
unsigned int count_space(char *string)
{
    int count = 0;
    int i;

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == ' ')
        {
            count++;
        }
    }
    return count;

}

/**
 * @brief Get the Token object
 * 
 * @param string string to be tokenized
 * @return ** char** the tokesn and 1 is there is an allocation error
 */
char **GetToken(char *string)
{
    int count = 0;
    const char delim[] = " ";
    int spaces = count_space(string);
    char **tokens = malloc(sizeof(char*)*(spaces + 1));
    char *token;

    if (!tokens)
    {
	fprintf(stderr, "sh: allocation error\n");
	exit(1);
    }

    token = strtok(string, delim);

    while (token != NULL)
    {
    	tokens[count++] = token;
    	token = strtok(NULL, delim);
    }
    tokens[count] = NULL;

    return (tokens);
}