//
// Created by Derslik3-08 on 28.08.2025.
//
//diziyi başka diziye kopyalayan fonksiyon kaç adet  kopya olacağını pparametre olarak alacak ve baştan başlayarek ypacak diziler boyutları eşit alıncak
//

#include<stdio.h>

void coppyfunc(const int *first_array,int *second_array,size_t count,size_t boyut) {
    for (size_t i=0; i<count; i++) {
    second_array[i]=first_array[i];
    }
}


int main (int argc, char *argv[]) {
    int first_array[10]={2,4,6,8,10,12,14,16,18,20};
    int second_array[10]={0};
    size_t count =6;

    coppyfunc(first_array,second_array,count,10);

    for (size_t i=0;i<10;i++) {
        printf("%d\n",second_array[i]);
    }
}