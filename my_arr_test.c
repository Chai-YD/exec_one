//#include<stdio.h>
//
//int main(){
//    int arr[10];
//    int i = 0;
//    for(;i<10;i++){
//        arr[i] = i+10;
//    }
//    for(i = 0;i<=9;i++){
//        printf("%d ",arr[i]);
//    }
//    printf("\n");
//    return 0;
//}

//将输入信息保存到数组中
//#include<stdio.h>
//
//int main(){
//    char buf[100] = {0};
//    char c = 'a';
//    int i = 0;
//    while(1){
//        scanf("%c",&c);
//        if(c == '\n'){
//            break;
//        }
//        buf[i] = c;
//        i++;
//    }
//    i = 0;
//    while(buf[i] != 0){
//        printf("%c" ,buf[i],i);
//        i++;
//    }
//    return 0;
//}

//#include<stdio.h>
//int main(){        //指针可以对其进行赋值，但是数组名并不可以对其进行赋值
//    char *p = NULL;
//    char arr[10] = {0};
//    char a = '1';
//    p = &a;
//    //arr = &a;
//    return 0;
//}


//指针的使用实例
//#include<stdio.h>
//
//int main(){
//    int i,j;
//    int *q,*p,*temp;
//    printf("please input i:\n");
//    scanf("%d",&i);
//    printf("please input j:\n");
//    scanf("%d",&j);
//    p = &i;
//    q = &j;
//    printf("%d %d \n",*p,*q);
//    if(*p > *q){
//        temp = p;
//        p = q;
//        q = temp;
//    }
//    printf("%d %d \n",*p,*q);
//    return 0;
//}

/**************************************
 * 数组与指针
 *************************************/

//定义的数组名可以直接赋值给一个指针
//#include<stdio.h>
//int main(){
//    int arr[3] = {1,2,3};
//    int *p = arr;
//    printf("%d ",*p);
//    p++;
//    printf("%d ",*p);
//    p++;
//    printf("%d\n",*p);
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main(){
//    char a[30];
//    scanf("%s",a);
//    int size = strlen(a);
//    printf("%s->%d\n",a,size);
//    return 0;
//}






