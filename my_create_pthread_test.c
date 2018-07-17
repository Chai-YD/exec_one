//线程的优点
//   1.创建一个线程的开销成本较低
//   2.线程的调度需要的操作远少于进程的调度
//   3.线程占用的资源远少于进程
//   4.能充分的利用多处理机可并行数量
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/syscall.h>

//同一个线程组的线程，没有层次关系
void *handler(void* mag){
    int i;
    printf("I am thread\n");
    //获取线程id
    pid_t tid;
    tid  = syscall(SYS_gettid);
    printf("%d\n",tid);
    sleep(1);
}

//主函数
int main(){
    pthread_t tid;
    int ret ;
    if((ret = pthread_create(&tid,NULL,handler,NULL)) != 0){
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    for(;;){
        printf("I am Main thread\n");
        sleep(1);
    }
    return 0;
}
