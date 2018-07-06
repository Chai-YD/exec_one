#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    //关闭文件描述符1
    //新创建文件，根据文件描述符的分配规则，使的新创建的文件
    //描述符为1，在输出时候，默认输出文件符是1，从而达到文件
    //重定向的目的
    close(1);
    int fd = open("myfile",O_WRONLY|O_CREAT,644);
    //判断文件打开是否失败 
    if(fd <0){
        //打开文件失败
        perror("open");
        return 1;
    }
    printf("fd:%d\n",fd);
    fflush(stdout);
    close(fd);
    return 0;
}
