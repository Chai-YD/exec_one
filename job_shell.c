#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t id = fork();
    if(id < 0 ){
        //fork失败
        perror("fork");
        return 1;
    }else if(id == 0){
        //child
        while(1){
            printf("child(%d)#i am running!\n",getpid());
            sleep(1);
        }
    }else{
        //parent
        int i = 5;
        printf("parent(%d)#i am going to dead...%d\n",getpid(),i--);
        sleep(1);
    }
    return 0;
}
//我们发现。程序起来以后，在前台新起了一个作业，包含 父子进程。
//5s之内，shell无法接受任何命令，说明此时的前台作业不是shell。
//但是父进程退出以后，子进程还在运行，但此时输入的命令
//
//shell可以进行处理，说明此时shell变成量前台作业，
//换句话说，我们刚新起的作业退出了，但子进程还在，就自动被提到后台，
//你可以在看看，子进程所属组还在，组长是父进程（已经退出）
//我们发现它还在一直打消息，杀掉即可。
