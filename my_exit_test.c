////exit最后也会调用 _exit，但在调用_exit之前，还做了其他工作
////（执行用户自定义的清理函数，将缓存数据写入，关闭所有打开流）
//#include<stdio.h>
//#include<stdlib.h>
//
//int main(){
//    printf("hello");
//    exit(-1);
//}
////虽然status是int，但是仅有低8位可以被父进程所用。
////所以_exit(-1)时，在终端执行$?发现返回值是255


#include<stdio.h>

int main(){
    printf("hello");
    return 0;
}
//return是一种最常见的退出进程方法。执行return n等同于执行exit（n），
//因为调用main的运行时函数会将main的返回值当作exit的参数。
