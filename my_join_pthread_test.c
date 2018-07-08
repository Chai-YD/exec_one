#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *handler1(void *arg){
    printf("thread 1 returning\n");
    int *p = (int *)malloc(sizeof(int));
    *p = 1;
    return (void*)p;
}

void *handler2(void *arg){
    printf("I am thread 2\n");
    int *p = (int *)malloc(sizeof(int));
    *p = 2;
    pthread_exit((void*)p);
}

void *handler3(void *arg){
    while(1){
        printf("I am thread 3\n");
        sleep(1);
    }
}

//主函数
int main(){
    pthread_t tid;
    void *ret;
    //thread 1 return
    pthread_create(&tid,NULL,handler1,NULL);

    pthread_join(tid,&ret);
    printf("thread return ,thread id %x,return code:%d\n",tid,*(int*)ret);
    free(ret);

    //thread 2 exit
    pthread_create(&tid,NULL,handler2,NULL);
    pthread_join(tid,&ret);
    printf("thread return ,thread id %x,return code:%d\n",tid,*(int*)ret);
    free(ret);
    //thread 3 cancel
    pthread_create(&tid,NULL,handler3,NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid,&ret);
    if(ret == PTHREAD_CANCELED){
        printf("thread return ,return id %x \n",tid);
    }
}
