//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//
//int main(){
//    int fd = open("myfile",O_RDONLY);
//    if(fd < 0){
//        perror("open");
//        return 1;
//    }
//    printf("fd:%d\n",fd);
//    return 0;
//}

//输出结果为3


//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<unistd.h>
//
//int main(){
//    close(0);
//    int fd = open("myfile",O_RDONLY);
//    if(fd<0){
//        perror("open");
//        return 1;
//    }
//    printf("fd:%d\n",fd);
//    return 0;
//}

//输出结果为：0

//可见，文件描述符的分配规则：在file_struct数组当中，找到当
//前没有被使用的最小的一个下标，作为新的文件描述符
