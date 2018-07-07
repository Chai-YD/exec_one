#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int wfd = open("tp",O_WRONLY);
    if(wfd < 0){
        perror("open");
        exit(1);
    }
    char buf[1024];
    while(1){
        //初始化数组
        buf[0] = 0;
        printf("please enter# ");
        fflush(stdout);
        size_t s =read(0,buf,sizeof(buf)-1);
        if(s > 0){
            buf[s] = 0;
            write(wfd,buf,s);
        }else if(s <= 0){
            perror("read");
            exit(1);
        }
    }
    return 0;
}
