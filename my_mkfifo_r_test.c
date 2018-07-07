#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int outfd = open("abc.bak",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(outfd == -1){
        perror("open");
        exit(1);
    }
    int infd = open("tp",O_RDONLY);
    if(infd == -1){
        perror("open");
        exit(2);
    }
    char *buf[1024];
    int n;
    while((n= read(infd,buf,1024)) > 0){
        write(outfd,buf,n);
    }
    close(outfd);
    close(infd);
    return 0;
}
