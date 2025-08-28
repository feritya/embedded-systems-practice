//
// Created by Derslik3-08 on 25.08.2025.
//


#include <stdio.h>
#define SIZE 10
void swap(int *x,int *y) {
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
int main (void){

    int a[10]={2,4,6,8,10,12,14,16,18,20};
    int b[10]={1,3,5,7,9,11,13,15,17,19};
    int *ptr=a;
    int boyut=sizeof(a)/sizeof(a[0]);

    for (int i=0; i< boyut; i++) {
        printf("%d ",a[i]);
        ptr++;
    }
    printf("\n");

    return 0;

}


//int a[10]={2,4,6,300,200,12,14,16,18,20};
//int b[10]={1,3,5,7,9,11,13,500,1000,19};