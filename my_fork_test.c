#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t pid;
    printf("before pid id %d\n",getpid());
    if((pid = fork()) == -1){
        perror("fork");
        return -1;
    }
    printf("after pid is %d;fork return %d\n",getpid(),pid);
    sleep(1);//等待父子进程都结束后再退出
    return 0;
}
//这里可以看到三行输出，一行before，两行after。进程先打印before，
//当fork之后，父子两个执行流分别执行。
//注意：fork之后，谁先执行完全由调度器决定。
