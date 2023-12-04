#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    pid_t cpid = fork();
    char *args[] = {"./fact", "./p", NULL};
    if (cpid == -1)
    {
        printf("FOrk failed");
        exit(EXIT_FAILURE);
    }
    else if (cpid == 0)
    {
        printf("Process ID of child : %d\n", getpid());
        execv(args[0], args);
    }
    else
    {
        printf("Process ID of parent : %d\n", getpid());
        execv(args[1], args);
    }
    printf("ENd of fork system call");
}
