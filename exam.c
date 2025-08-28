//
// Created by Derslik3-08 on 28.08.2025.
// task 2 bir dizide en büyük ve en küçük elemanı bu


#include<stdio.h>


void findmaxmin(int const *parray, size_t array_size, int *max, int *min) {
    *max=parray[0];
    *min=parray[0];
    for (size_t i=1;i<array_size;i++) {
        if (*min>parray[i]) {
            *min=parray[i];
        }
        else if (*max<parray[i]) {
            *max=parray[i];

        }

    }

}

int main (int argc, char *argv[]) {
    int a[10]={2,0,6,8,10,12,-1,16,18,20};
    int min;
    int max;

    size_t array_size = sizeof(a)/sizeof(a[0]);

    findmaxmin(a,array_size,&max,&min);
    printf("max =%d min =%d",max,min);
}
