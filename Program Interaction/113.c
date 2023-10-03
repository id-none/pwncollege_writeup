#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char** argv = {NULL};
char** envp = {NULL};

void pwncollege(char** argv, char** envp) {
    execve("/challenge/embryoio_level113",argv,envp);
}

int main(int argn,char** argv,char** envp){
    int pid = fork();
    if(pid == 0){
        pwncollege(argv,envp);
    }
    else{
        wait(NULL);
    }
    return 0;
}
