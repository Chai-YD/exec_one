//#include<stdio.h>
//#include<unistd.h>
//
//int g_val = 0;
//
//int main(){
//    pid_t id = fork();
//    if(id<0){
//        perror("fork");
//        return 0;
//    }else if(id == 0){
//        //child
//        printf("child[%d]: %d : %p\n",getpid(),g_val,&g_val);
//    }else{
//        //parent
//        printf("parent[%d]: %d : %p\n",getpid(),g_val,&g_val);
//    }
//    sleep(1);
//    return 0;
//}
////我们发现输出的变量值和地址是一模一样的，很好理解，因为子进程
////按照父进程为模板，父子进程并没有对模板进行修改。


#include<stdio.h>
#include<unistd.h>
int g_val = 0;
int main(){
    pid_t id = fork();
    if(id < 0){
        perror("fork");
        return 0;
    }else if(id == 0){
        g_val = 100;
        printf("child[%d]: %d : %p\n",getpid(),g_val,&g_val);
    }else{
        sleep(3);
        printf("parent[%d]: %d : %p\n",getpid(),g_val,&g_val);
    }
}
//我们发现，父子进程，输出地址是一致的，但是变量内容不一样！得出结论
//1.变量内容不一样，所以父子进程输出的变量绝对不是同一个变量
//2.但地址值是一样的，说明，该地址绝对不是物理地址
//3.在LINUX地址下，这种地址叫做虚拟地址
//4.我们在应C/C++语言所能看到的地址，全部都是虚拟地址！物理地址，用户一般 
//看不到，右OS统一管理
