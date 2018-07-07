#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    pid_t pid;
    //创建子进程
    if((pid = fork()) == -1){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        //child
        printf("child is run,pid is %d\n",getpid());
        sleep(5);
        exit(2);
    }else{
        //parent
        int status = 0;
        pid_t ret = waitpid(-1,&status,0);//阻塞方式等待，等待5s
        printf("this is a test for wait\n");
        if(WIFEXITED(status) && ret == pid){
            printf("wait child 5s success,child return code is %d",WEXITSTATUS(status));
        }else{
            printf("wait child failed,return\n");
            return 1;
        }
    }
    return 0;
}
