#include<stdio.h>
#include<string.h>
int main(){
    FILE* fd= fopen("myfile","w");
    if(!fd){
        printf("fopen error\n");
        return 0;
    }
    const char *msg = "hello bit\n";
    int count = 5;
    while(count--){
        fwrite(msg,strlen(msg),1,fd);
    }
    //关闭文件描述符
    fclose(fd);
    return 0;
}
