//创建命名管道
/*************************
 * 命名管道与匿名管道的区别
 *      1.匿名管道由pipe函数创建并打开
 *      2.命名管道由mkfifo创建，打来用open
 *      3.FIFO（命名管道 ）与pipe（匿名管道）之间唯一的区别在它们
 *      创建方式与打开方式不同，一旦这些工作完成之后，它们就具有
 *      相同的语义
 *************************/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    mkfifo("p2",0644);
    return 0;
}
