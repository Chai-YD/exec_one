#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int value = 100;

int main(){
    pid_t pid;
    if((pid = vfork())== -1){
        perror("fork");
        return 1;
    }
    if(pid == 0){
        //child
        sleep(3);
        value = 200;
        printf("child value = %d\n",value);
        exit(0);
    }else {
        //parent
        printf("parent value = %d\n",value);
    }
    return 0;
}
//等待3秒之后，子进程先输出value值，然后父进程才输出value值
//value值均为200，可见子进程直接改变了父进程的变量值，因为
//子进程在父进程的地址空间中运行
