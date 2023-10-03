#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char** argv = {"embryoio_level80",NULL};
char** envp = {NULL};

void pwncollege(char** argv, char** envp) {
    execve("/challenge/embryoio_level80",argv,envp);
}

int main(int argn,char** argv,char** envp){
    int pid = fork();
    if(pid == 0){
        // 设置第177个参数的值为aioxtvwrcm，其余参数为A
        argv[177] = "aioxtvwrcm";
        for(int i=1;i<177;i++){
            argv[i] = "A";
        }
        argv[178] = NULL;
        pwncollege(argv,envp);
    }
    else{
        wait(NULL);
    }
    return 0;
}
