#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    pid_t pid;
    if((pid = fork()) == -1){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        printf("child is run,pid is %d\n",getpid());
        sleep(5);
        exit(2);
    }else{
        int status = 0;
        pid_t ret = 0;
        do{
            ret = waitpid(-1,&status,WNOHANG);//非阻塞式等待
            if(ret == 0){
                printf("child is running\n");
            }
            sleep(1);
        }while(ret == 0);//条件为真时继续
        if(WIFEXITED(status) && ret == pid){
            printf("wait child 5s success,child return code is %d\n",WEXITSTATUS(status));
        }else{
            printf("wait child failed,return \n");
            return 1;
        }
    }
    return 0;
}
