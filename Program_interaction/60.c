#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
 
void pwncollege()
{
    return;
}
 
int main()
{
    int fd[2];
    if( pipe(fd)==-1 )
    {
        perror("pipe");
        exit(1);
    }

    int pid = fork();
    if(pid < 0)
        perror("fork");
    else if(pid == 0)
    {   
        printf("in child 1, pid = %d\n", getpid()); 
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        if(execl("/usr/bin/cat", "cat", NULL) == -1)
        { 
            perror("exec");
            exit(1);
        }
    }
    else
    {
        int pid2 = fork();
        if(pid2 < 0)
            perror("fork");
        else if(pid2 == 0)
        {
            printf("in child 2, pid = %d\n", getpid()); 
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            if(execl("/challenge/embryoio_level60", "embryoio_level60", NULL) == -1)
                perror("exec");
        }
        else
            wait(NULL);
    }

    return 0;
}


