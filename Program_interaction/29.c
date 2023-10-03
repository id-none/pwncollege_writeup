#include <stdio.h>
#include <unistd.h>

void pwncollege(char* argv[],char *env[]){
    execve("/challenge/embryoio_level29",argv,env);//使用exec系列函数执行时不会改变新进程的父亲，相当于只是将当前进>程替换掉了
    return ;
}

int main(int argc,char* argv[],char* env[]){
    pid_t fpid;

    fpid=fork();//fork()执行之后，会复制一个基本一样的进程作为子进程，然后两个进程会分别执行后面的代码
    if(fpid<0)//如果fpid为-1，说明fork失败
            printf("error in fork!\n");
    else if (fpid==0){//成功则会出现两个进程，fpid==0的是子进程
            printf("我是子进程\n");
            pwncollege(argv,env);
    }
    else{//fpid==1的是父进程
            printf("我是父进程\n");
            wait(NULL);
    }
    return 0;
}