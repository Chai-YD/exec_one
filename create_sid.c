#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<error.h>
//1.调用umask将文件模式创建 屏蔽字设置为0
//2.调用fork，父进程 退出（exit）
//如果该守护进程是作为一条简单的shell命令启动的，呢么父
//进程终止使得shell认为该命令己经执行完毕
//保证子进程不是 一个进程的组长进程
//3.调用setsid创建一个会话
//4.忽略SIGCHLD信号
//5.将当前工作目录改为根目录

void mydeamon(void){
    int i;
    int fd0;
    pid_t pid;
    struct sigaction sa;
    //将文件模式 创建屏蔽字设置为0
    umask(0);
    if((pid = fork())<0){
        //fork失败
        perror("fork");
        return;
    }else if(pid > 0){
        //parent
        exit(0);//终止父进程
    }else{
        setsid();//创建一个新的会话
        //信号的捕捉
        sa.sa_handler=SIG_IGN;//设置为忽略
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        if(sigaction(SIGCHLD,&sa,NULL) <0){
            //注册子进程退出忽略信号
            return;
        }
        //将当前工作目录改为根目录
        if(chdir("/") < 0){
            printf("child dir error\n");
            return;
        }
        //关闭不再需要的文件描述符，或者重定向到/dev/NULL
        close(0);
        fd0 = open("/dev/null",O_RDWR);
        dup2(1,fd0);
        dup2(2,fd0);
    }
} 
int main(){
    mydeamon();
    while(1){
        sleep(1);
    }
    return 0;
}
