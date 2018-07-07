#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid ;
    if((pid =fork()) == -1){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        sleep(20);
        exit(10);
    }else{
        int st;
        int ret = wait(&st);

        if(ret > 0 &&(st&0x7F)==0){
            printf("child exit code %d\n",(st>>8)&0xFF);
        }else if(ret>0){
            //异常退出
            printf("sig code %d\n",st&0x7F);
        }
    }
    return 0;
}
//正常退出，status的第7位为退出信息，次第8位为退出码
//异常退出，低7位为终止信息，下标为7的表示core dump标志
