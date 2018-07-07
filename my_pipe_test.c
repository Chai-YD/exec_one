/******************
 * 管道
 * ****************/
//管道是unix中最古老的进程通信的形式
//我们把一个进程到另一个进程的 数据流 称为一个管道
//int pipe(int fd[2]); 匿名管道
//返回值：成功返回0，失败返回错误码
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fds[2];
    int len;
    char buf[100];
    //创建管道
    if(pipe(fds) != 0){
        perror("make pipe");
        exit(1);
    }
    //从标准输入读取数据
    while(fgets(buf,100,stdin)){
        len = strlen(buf);
        //将所读数据写入管道
        if(write(fds[1],buf,len) != len){
            perror("write to pipe");
            exit(2);
        }
        //清空buf数组
        memset(buf,0x00,sizeof(buf));
        //从管道中读取数据
        if((len = read(fds[0],buf,len)) == -1){
            perror("read from pipe");
            exit(3);
        }
        //将从管道中读取的文件输入至标准输出
        if(write(1,buf,len) != len){
            perror("write to stdout");
            exit(4);
        }
    }
    return 0;
}
