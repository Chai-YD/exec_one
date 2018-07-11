//只检测标准输入
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    //文件描述符集的定义与初始化
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(0,&read_fds);
    //进行等待就绪文件
    for(;;){
        printf(">");
        fflush(stdout);
        int ret = select(1,&read_fds,NULL,NULL,NULL);
        if(ret < 0){
            perror("select");
            continue;
        }
        if(FD_ISSET(0,&read_fds)){
            char buf[1024]= {0};
            read(0,buf,sizeof(buf)-1);
            printf("%s\n",buf);
        }else{
            printf("error\n");
            continue;
        }
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
    }
    return 0;
}
