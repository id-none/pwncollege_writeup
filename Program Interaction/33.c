/*
WELCOME! This challenge makes the following asks of you:
- the challenge checks for a specific parent process : binary
- the challenge will check that input is redirected from a specific file path : /tmp/hdkihv
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char** argv = {NULL};
char** envp = {NULL};

void pwncollege(char** argv, char** envp) {
    // 程序名称 /challenge/embryoio_level33 
    // 重定向stdin：/tmp/hdkihv
    int fd = open("/tmp/hdkihv",0);
    dup2(fd,0);
    execve("/challenge/embryoio_level33",argv,envp);
    close(fd);
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