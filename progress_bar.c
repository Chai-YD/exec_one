#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(){
    int i = 0;
    char bar[102];
    //初始化数组
    memset(bar,0,sizeof(bar));
    const char* lable = "|/\\-";
    while(i<=100){
        printf("[%-100s]",bar);
        printf("[%d%%]",i);
        //printf("%s",lable[i%4]);
        fflush(stdout);
        printf("\r");
        bar[i++] = '#';
        sleep(1);

    }
    printf("\n");
    return 0;
}
