#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<ctype.h>
#include<unistd.h>

//全局变量
int argc = 0;
char *argv[8];

//分析函数
void do_parse(char *buf){
    int i;
    int status = 0;
    for(i=argc=0;buf[i];i++){
        if(status == 0 && !(isspace(buf[i]))){
            argv[argc++] = buf + i;
            status = 1;
        }else if(isspace(buf[i])){
            buf[i] = 0;
            status = 0;
        }
    }
    argv[argc] == NULL;
}

//执行函数
void do_execute(void){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        execvp(argv[0],argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }else{
        int st;
        while(wait(&st) != pid){
            ;
        }
    }
}


int main(){
    char buf[1024] = {};
    while(1){
        printf("myshell>");
        scanf("%[^\n]%*c",buf);
        do_parse(buf);
        do_execute();
    }
    return 0;
}
