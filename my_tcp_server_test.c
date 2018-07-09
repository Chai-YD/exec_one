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
    if(sock <0){
        perror("sock error");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    //绑定
    if(bind(sock,(struct sockaddr*)&server,sizeof(server)) < 0 ){
        printf("bind error");
        exit(2);
    }
    //监听
    if(listen(sock,5) < 0){
        printf("listen error");
        exit(3);
    }

    printf("bind success,listen success,wait connect\n");
    struct sockaddr_in client;
    while(1){
        int client_sock;
        socklen_t len = sizeof(client);
        if((client_sock = accept(sock,(struct sockaddr*)&client,&len)) < 0){
            printf("accept error");
            continue;
        }
        printf("get connect ip is %s\n",inet_ntoa(client.sin_addr));
        while(1){
            char buf[1024];
            memset(buf,0x00,sizeof(buf));
            read(client_sock,buf,sizeof(buf));
            printf("client# %s\n",buf);
            printf("server # ");
            memset(buf,0x00,sizeof(buf));
            fgets(buf ,sizeof(buf),stdin);
            buf[strlen(buf)-1] = '\0';
            write(client_sock,buf,strlen(buf)+1);

            printf("wait....\n");
        }
    }
    close(sock);
    return 0;
}
