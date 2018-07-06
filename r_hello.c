#include<stdio.h>
#include<string.h>

int main(){
    FILE* fd = fopen("myfile","r");
    char buf[1024];
    const char* msg = "hello bit\n";
    while(1){
        size_t s = fread(buf,1,strlen(msg),fd);
        if(s>0){
            buf[s] = 0;
            printf("%s",buf);
        }
        if(feof(fd)){
            break;
        }
    }
    fclose(fd);
    return 0;
}
