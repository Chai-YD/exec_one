
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int fd[2];
    if(pipe(fd) == -1){
        perror("pipe");
        exit(1);
    }
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        exit(2);
    }
    if(pid == 0){
        //child
        close(fd[0]);
        write(fd[1],"hello",5);
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }else{
        close(fd[1]);
        char buf[10] = {0};
        read(fd[0],buf,10);
        printf("buf = %s\n",buf);
        return 0;
    }
}
