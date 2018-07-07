#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    int infd = open("abc",O_RDONLY);
    if(infd == -1){
        perror("open ");
        exit(1);
    }
    mkfifo("tp",0644);
    int outfd = open("tp",O_WRONLY);
    if(outfd == -1){
        perror("open");
        exit(2);
    }
    char buf[1024];
    int n;
    while((n = read(infd,buf,1024)) > 0){
        printf("%d\n",n);
        write(outfd,buf,n);
    }
    close(infd);
    close(outfd);
    return 0;
}
