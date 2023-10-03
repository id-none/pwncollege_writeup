#include <stdio.h>
#include <unistd.h>

void pwncollege(char* argv[],char *env[]){
    execve("/challenge/embryoio_level31",argv,env);//使用exec系列函数执行时不会改变新进程的父亲，相当于只是将当前进>程替换掉了
    return ;
}

int main(int argc,char* argv[],char* env[]){
    pid_t fpid;
    fpid = fork();
    if(fpid<0)
            printf("error in fork!\n");
    else if (fpid==0){
            printf("我是子进程\n");
            char *newargv[] = {"12312","pkzsntymeh",NULL};
            pwncollege(newargv,env);
    }
    else{
            printf("我是父进程\n");
            wait(NULL);
    }
    return 0;
}