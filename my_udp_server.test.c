#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main(int argc,char* argv[]){
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock<0){
        perror("sock");
        exit(1);
    }
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(atoi(argv[2]));
    local.sin_addr.s_addr = inet_addr(argv[1]);
    //绑定
    if(bind(sock,(struct sockaddr*)&local,sizeof(local)) <0 ){
        perror("bind");
        exit(2);
    }
    char buf[1024];
    struct sockaddr_in client;
    while(1){
        socklen_t len = sizeof(client);
        size_t s = recvfrom(sock,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
        if(s> 0){
            buf[s] = 0;
            printf("client$: %s\n",buf);
        }
        sendto(sock,buf,strlen(buf),0,(struct sockaddr*)&client,sizeof(client));
    }
}
