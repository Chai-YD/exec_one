#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

typedef struct client{
    int cfd;
    char nickname[32];
}client_t;
typedef struct node{
    client_t c;
    struct node* prev;
    struct node * next;
}node_t;

node_t *head = NULL;
void init(){
    node_t *p = malloc(sizeof(node_t));
    p->next = p;
    p->prev = p;
    head = p;
}

void insert(const client_t *pc){
    node_t *p = malloc(sizeof(node_t));
    memset(p,0x00,sizeof(node_t));
    p->c = *pc;
    p->prev = head->prev;
    head->prev->next = p;
    head->prev = p;
    p->next = head;
}

int length(){
    int i = 0;
    node_t *p = head->next ;
    do{
        i++;
        p = p->next;
    }while(p!=head);
    return i;
}

void erase(int cfd){
    node_t * p = head ->next;
    while(p != head && p->c.cfd !=cfd)
        p = p->next;
    p->next->prev = p ->prev;
    p->prev->next = p->next;
    free(p);
}

void travel(const char* msg){
    if(head == NULL){
        return ;
    }
    node_t *p = head;
    do{
        write(p->c.cfd,"msg",strlen(msg));
        printf("name = %s\n",p->c.nickname);
        p = p->next;
    }while(p!=head);
}
void *process(void *arg){
    int cfd = *(int *)arg;
    free(arg);
    char buf[1024];
    sprintf(buf,"%s","欢迎");
    write(cfd,buf,strlen(buf));
    sprintf(buf,"%s","输入昵称");
    write(cfd,buf,strlen(buf));
    memset(buf,0x00,sizeof(buf));
    read(cfd,buf,1024);
    char msg[1024];
    sprintf(msg,"欢迎%s来到聊天室",buf);
    travel(msg);
    client_t client;
    client.cfd = cfd;
    strcpy(client.nickname,buf);
    insert(&client);
    while(1){
        memset(buf,0x00,sizeof(buf));
        int r = read(cfd,buf,1024);
        if(r <= 0)break;
        travel(buf);
    }
    erase(cfd);
}

int main(){
    init();
    int lfd = socket(AF_INET,SOCK_STREAM,0);
    if(lfd == -1){
        perror("socket");
    }
    int op = 1;
    setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,&op,sizeof(op));
    struct sockaddr_in addr;
    //结构提的构造
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //绑定‘
    int r = bind(lfd,(struct sockaddr*)&addr,sizeof(addr));
    if(r == -1){
        perror("bind");
        exit(2);
    }
    r =  listen(lfd,5);
    if(r == -1){
        perror("listen");
        exit(3);
    }
    //建立连接
    for(;;){
        struct sockaddr_in client;
        int  len = sizeof(client);
        int clientfd = accept(lfd,(struct sockaddr*)&client,&len);
        if(clientfd == -1){
            printf("accept error");
            continue;
        }
        pthread_t tid;
        //线程的创建
        pthread_create(&tid,NULL,process,NULL);
        pthread_detach(tid);
    }
    return 0;
}
