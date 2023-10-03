#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char** argv = {NULL};
char** envp = {NULL};

void pwncollege(char** argv, char** envp) {
    mkfifo("/tmp/pipe",0666);
    int fd = open("/tmp/pipe",O_RDWR);
    write(fd,"uctvokry",8);
    dup2(fd,86);
    execve("/challenge/embryoio_level120",argv,envp);
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
