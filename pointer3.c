#include <stdio.h>
int main (){
    printf("hello world");

    int x=10,y=20,z=30;

    int *ptr =&x;
    *ptr=20;
    ptr=&y;
    *ptr=300;

    printf("\n ptr=%d x= %d  y=%d \n",*ptr,x,y);

    return 0;

}