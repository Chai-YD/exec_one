//c默认打开三个输入输出流，分别是stdin,stdout,stderr
//仔细观察这三个流的类型都是FILE*，fopen返回值类型，文件指针
#include<stdio.h>
#include<string.h>
int main(){
    const char *msg = "hello world\n";
    fwrite(msg,strlen(msg),1,stdout);
    printf("%s",msg);
    fprintf(stdout,"hello world\n");
    return 0;
}
