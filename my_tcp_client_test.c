#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main(int argc,char* argv[]){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock< 0){
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    int ret = connect(sock,(struct sockaddr*)&server,sizeof(server));
    if(ret < 0){
        perror("connect");
        exit(2);
    }
    printf("connect success..\n");
    while(1){
        char buf[1024];
        //初始化数组
        memset(buf,0x00,sizeof(buf));
        printf("enter# ");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = '\0';
        write(sock,buf,sizeof(buf));
        if(strncasecmp(buf,"quit",4) == 0){
            printf("quit\n");
            break;
        }
        printf("wait..\n");
        read(sock,buf,sizeof(buf));
        printf("server# %s\n",buf);
    }
    close(sock);
    return 0;
}
