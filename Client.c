#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/select.h>
#include<sys/time.h>
#include<unistd.h>

int main(){
    int cfd = socket(AF_INET,SOCK_STREAM,0);
    if(cfd == -1){
        perror("socket");
        exit(2);
    }
    struct sockaddr_in add;
    add.sin_family = AF_INET;
    add.sin_port = htons(8080);
    add.sin_addr.s_addr = htonl(INADDR_ANY);
    int r = connect(cfd,(struct sockaddr*)&add,sizeof(add));
    if(r == -1){
        perror("connect");
        exit(1);
    }
    int kfd = fileno(stdin);
    int maxfd = kfd>cfd?kfd:cfd;
    fd_set set;
    while(1){
        FD_ZERO(&set);
        FD_SET(cfd,&set);
        FD_SET(kfd,&set);
        int r = select(maxfd+1,&set,NULL,NULL,NULL);
        if(r < 0){
            perror("select");
            exit(3);
        }
        char buf[1024];
        if(FD_ISSET(cfd,&set)){
            r = read(cfd, buf,1024);
            if(r =  0){
                close(cfd);
                break;
            }
            printf("%s",buf);
            fflush(stdout);
        }
        if(FD_ISSET(kfd,&set)){
            int r = read(0,buf,sizeof(buf));
            if(r < 0){
                break;
            }
            write(cfd,buf,strlen(buf));
        }
    }
    return 0;
}
