#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char* argv[]){
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock<0){
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    char buf[1024];
    struct sockaddr_in local;
    while(1){
        socklen_t len = sizeof(local);
        printf("enter:");
        fflush(stdout);
        size_t s = read(0,buf,sizeof(buf)-1);
        if(s > 0){
            buf[s-1] = 0;
            sendto(sock,buf,strlen(buf),0,(struct sockaddr*)&server,sizeof(server));
            size_t s = recvfrom(sock,buf,sizeof(buf)-1,0,(struct sockaddr*)&local,&len);
            if(s > 0){
                buf[s] = 0;
                printf("client# %s\n",buf);
            }
        }
    }
    return 0;
}
