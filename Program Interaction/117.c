#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char** argv = {NULL};
char** envp = {NULL};

void pwncollege(char** argv, char** envp) {
    int fd = open("/tmp/fifo",O_RDWR);
    dup2(fd,1);
    execve("/challenge/embryoio_level117",argv,envp);
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
