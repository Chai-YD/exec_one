//行缓冲区（对以下三段代码，进行执行将对行缓冲的理解有一定的帮助）
//
//
//#include<stdio.h>
//#include<unistd.h>
//int  main(){
//    printf("hello\n");
//    sleep(3);
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>
//int main(){
//    printf("hello");
//    sleep(3);
//    return 0;
//}


#include<stdio.h>
#include<unistd.h>
int main(){
    printf("hello");
    fflush(stdout);
    sleep(3);
    return 0;
}

