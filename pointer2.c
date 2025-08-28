#include <stdio.h>
int main (){
    printf("hello world");

    int x=10,y=20,z=30;

    int *p1=&x,*p2=p1,*p3=p2;
    ++*p1;
    ++*p2;
    ++*p3;


    printf("\n ptr=%d x= %d  y=%d  x=%d\n",*p1,*p2,*p3,x);

    return 0;

}