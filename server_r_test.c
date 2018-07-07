#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    if(mkfifo("tp",0644) <0){
        perror("mkfifo");
        exit(1);
    }
    int rfd;
    rfd = open("tp",O_RDONLY);
    if(rfd < 0){
        perror("open");
        exit(2);
    }
    int n;
    while(1){
        char buf[1024];
        //初始化数组
        buf[0]=0;
        printf("please wait...\n");
        size_t s = read(rfd,buf,sizeof(buf)-1);
        if(s>0){
            buf[s-1] = 0;
            printf("client say# %s\n",buf);
        }else if(s == 0){
            printf("client quit,exit now\n");
            exit(EXIT_SUCCESS);
        }else{
            perror("read");
            exit(2);
        }
    }
    return 0;
}
