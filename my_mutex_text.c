#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int ticket = 100;

//定义互斥锁
pthread_mutex_t mutex;

void *hanlder(void *arg){
    char *id= (char*)arg;
    while(1){
        pthread_mutex_lock(&mutex);
        if(ticket > 0){
            usleep(1000);
            printf("%s sells ticket:%d\n",id,ticket);
            ticket--;
            pthread_mutex_unlock(&mutex);
        }else{
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
}

//对于简易的售票系统，可能会出现错误值，
//由于：操作并不是原子操作的，而是对应三条汇编指令（加载、更新、写回）

//主函数
int main(){
    pthread_mutex_init(&mutex,NULL);
    pthread_t t1,t2,t3,t4;
    pthread_create(&t1,NULL,hanlder,"thread 1");
    pthread_create(&t2,NULL,hanlder,"thread 2");
    pthread_create(&t3,NULL,hanlder,"thread 3");
    pthread_create(&t4,NULL,hanlder,"thread 4");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_mutex_destroy(&mutex);
}
