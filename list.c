//
// Created by Derslik3-08 on 25.08.2025.
//

//
// Created by Derslik3-08 on 25.08.2025.
//


#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void writelist(const int *a,const int size) {
    int i=0;
    while (i< size) {
     printf("%d ",a[i]);
        i++;
    }
    printf("\n");

}
void randwritelist(int *a,int size) {
    int i=0;
    while (i< size) {
          a[i] = rand()%100;
        i++;
    }
}

int main (void){

    int a[10]={2,4,6,8,10,12,14,16,18,20};
    int b[10]={1,3,5,7,9,11,13,15,17,19};
    int size=sizeof(a)/sizeof(a[0]);
    randwritelist(b,size);
    writelist(b,size);


    printf("\n");

    return 0;

}
