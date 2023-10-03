#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char** argv = {"embryoio_level83",NULL};
char** envp = {NULL};

void pwncollege(char** argv, char** envp) {
    execve("/challenge/embryoio_level83",argv,envp);
}

int main(int argn,char** argv,char** envp){
    int pid = fork();
    if(pid == 0){
        for(int i=1;i<200;i++){
            argv[i] = "A";
        }
        argv[136]="hxlejjdago";
        envp[0] = "143=qncnpfqyuj";
        pwncollege(argv,envp);
    }
    else{
        wait(NULL);
    }
    return 0;
}
