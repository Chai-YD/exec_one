#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


pthread_mutex_t mutex;
pthread_cond_t cond;

void *handler(void *arg){
    while(1){
        pthread_cond_wait(&cond,&mutex);
        printf("柴\n");
    }
}
void *handler2(void *arg){
    while(1){
        pthread_cond_signal(&cond);
        sleep(1);
    }
}



//主函数
int main(){
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,handler,NULL);
    pthread_create(&t2,NULL,handler2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}
