#include "shell.h"

/**
 * @brief run - excutes an incomming command
 * 
 * @param cmd - the command
 * @return ** int 0 for success -1 and 1 for error exits
 */
int run(char **cmd){
    int status;
    pid_t pid;

    if (strncmp("exit", cmd[0], 4) == 0)
        return(-1);

    pid = fork();

    if (!pid && execve(cmd[0], cmd, NULL) == -1){
            perror("Error");
            exit(-1);
    }else if (pid == -1)
    {
        perror("Error");
        return (1);
    }
    
    else
        wait(&status);
    
    return(0);

}

/**
 * @brief main the main shell logic
 * 
 * @param argc no of arguments
 * @param argv  list of arguments
 * @return ** int 0 unless there is an error if so -1
 */
int main(int argc, char **argv)
{
    char **tokens;
    int response;
    size_t buflen = BUFSIZ;
    int isTerminal = 0;
    char *newBuffer;

    if (argc >= 2)
    {
        if (execve(argv[1], argv, NULL) == -1)
        {
            perror("Error");
            exit(-1);
        }
        return (0);
    }

    newBuffer = (char*)malloc(buflen * sizeof(char));
    if (newBuffer == NULL)
    {
        perror("Error");
		exit(1);
    }

    do
    {
        if (isatty(fileno(stdin)))
        {
            isTerminal = 1;
            _putstring("cisfun#: ");
        }

        getline(&newBuffer, &buflen, stdin);
        newBuffer[_strlen(newBuffer) - 1] = '\0';
        tokens = GetToken(newBuffer);
        response = run(tokens);
    }while (response != -1 && isTerminal);

    return (0);

    
}