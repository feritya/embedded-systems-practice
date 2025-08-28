#include <stdio.h>
int main (){
    int a[5]={2,4,6,8,10};
    int *ptr = &a[2];
    int *ptr2 = &a[0];
    int *ptr3 = &a;
    printf("ptr = %p \n ptr2 = %p \n ptr3 = %p\n",&ptr,&ptr2,&ptr3);
    return 0;
}