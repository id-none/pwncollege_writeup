#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

// g++ 65.c input:krdpowpt
void pwncollege(){
    return;
}

int main()
{
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    int pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(1);
    } else if (pid1 == 0) {
        // 子进程1：执行 rev 命令
        close(pipefd[0]); // 关闭读端
        dup2(pipefd[1], STDOUT_FILENO); // 将标准输出重定向到管道写端
        execl("/usr/bin/rev", "rev", NULL);
        perror("exec");
        exit(1);
    }

    int pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(1);
    } else if (pid2 == 0) {
        // 子进程2：执行 /challenge/embryoio_level65 可执行文件
        close(pipefd[1]); // 关闭写端
        dup2(pipefd[0], STDIN_FILENO); // 将标准输入重定向到管道读端
        execl("/challenge/embryoio_level65", "embryoio_level65", NULL);
        perror("exec");
        exit(1);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}
