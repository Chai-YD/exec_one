#include<stdio.h>
#include<unistd.h>

int main(){
    char *const argv[] = {"ls","-a",NULL};
    //execl("/bin/ls","ls","-a",NULL);
    ////带p的，可以使用环境变量PATH，无需写全路径
    //execlp("ls","ls","-a",NULL);

    //execv("/bin/ls",argv);
    ////带p的，可以使用环境变量PATH，无需写全路径
    execvp("ls",argv);
}

//事实上，只有execve是真正的系统调用，其他五个函数最终都调用execve，
//所以execve在man手册的第2节，其他函数在man手册的第3节。
