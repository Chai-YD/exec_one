#include<stdio.h>

int main(){
    int x,y,z,t;  //定义四个变量
    printf("please input x:\n");//分别提示和输出三个变量
    scanf("%d",&x);
    printf("please input y:\n");
    scanf("%d",&y);
    printf("please input z:\n");
    scanf("%d",&z);
    if(x > y){  //判断x是否大于y
        t = x;
        x = y;
        y = t;
    }
    if(x > z){
        t = x;
        x = z;
        z = t;
    }
    if(y > z){
        t = y;
        y = z;
        z = t;
    }
    //三个变量的值已经发生了变量，，
    printf("%d %d %d \n",x,y,z);
    return 0;
}
