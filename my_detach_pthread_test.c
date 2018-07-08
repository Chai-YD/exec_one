#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void * handler(void *arg){
    //分离线程
    pthread_detach(pthread_self());
    return NULL;
}

//主函数
int main(){
    pthread_t tid;
    if(pthread_create(&tid,NULL,handler,NULL)!= 0){
        printf("create thread error\n");
        return 1;
    }
    int ret = 0;
    sleep(1);

    if(pthread_join(tid,NULL) == 0){
        printf("pthread wait success!\n");
        ret = 0;
    }else{
        printf("pthread wait filed\n");
        ret = 1;
    }
    return ret;
}
