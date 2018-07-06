#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(){
    //打开文件，有则打开，没有就创建
    int fd = open("myfile",O_WRONLY|O_CREAT,644);
    if(fd < 0){
        //打开失败
        perror("open");
        return 0;
    }
    int count = 5;
    const char *msg = "chaiyandong\n";
    while(count--){
        write(fd,msg,strlen(msg));
    }
    close(fd);
    return 0;
}
