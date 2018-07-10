#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

typedef struct s_arg{
    int client_fd;
    struct sockaddr_in client;
} Arg;

void ProcessRequest(int client_fd,struct sockaddr_in *client){
    char buf[1024] = {0};
    for(;;){
        int s = read(client_fd,buf,sizeof(buf)-1);
        if(s > 0){
            buf[s] = '\0';
            printf("client# %s\n",buf);
            write(client_fd,buf,strlen(buf));
        }else if(s == 0){
            printf("client exit\n");
            break;
        }else {
            perror("read");
            exit(2);
        }
    }
}

void* createWorker(void* arg){
    Arg* ptr = (Arg*)arg;
    ProcessRequest(( ptr->client_fd ),&( ptr->client ));
}

int main(int argc,char *argv[]){
    //创建套接字
    int sock = socket(AF_INET,SOCK_STREAM,0);
    //创建结构体
    struct sockaddr_in server;
    //初始化结构体
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    //绑定
    if(bind(sock,(struct sockaddr*)&server,sizeof(server)) < 0){
        perror("bind");
        return 1;
    }
    //监听
    int ret = listen(sock,10);
    if(ret < 0){
        perror("listen");
        return 2;
    }
    printf("bind success,listen success,wait accept\n");
    //开始连接
    for(;;){
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        int client_fd;
        //进行连接
        if((client_fd = accept(sock,(struct sockaddr*)&client,&len)) < 0){
            printf("accept error\n");
            continue;
        }
        //连接成功
        pthread_t tid = 0;
        Arg* arg = (Arg *)malloc(sizeof(Arg));
        arg->client_fd = client_fd;
        arg->client = client;
        pthread_create(&tid,NULL,createWorker,(void *)arg);
        //线程分离，不关主结果，避免等待
        pthread_detach(tid);
    }
}
