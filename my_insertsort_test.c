//插入排序的实现
#include<stdio.h>

//插入函数的实现
//排序思想：
//从左至右 将数组中的元素依次插入，待插入完成后，数组就是一个有序的数组

void insert_sort(int arr[],int  len){
    int i = 1;
    for(;i<len;++i){
        int value = arr[i];
        int  j = i;
        while(j>0&&value<arr[j-1]){
            arr[j] = arr[j-1];
            --j;
        }
        //在此处时候，说明下标为j的数组 位置就是新插入元素的位置
        arr[j] = value;
    }
    for(i = 0;i<len;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {2,3,4,5,6,7,8,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    insert_sort(arr,len);
    return 0;
}
