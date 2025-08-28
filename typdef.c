//
// Created by Derslik3-08 on 28.08.2025.
// bir dizide bir eleman var mı? varsa olduğu yerin adresini döndüren yoksa null pointer dönen fonksiyon


#include<stdio.h>
#include<stdint.h>



int *findelement(int *array,size_t boyut ,int search) {
    for (int i=0;i<boyut;i++) {
        if (array[i]==search) {
            return &array[i];
        }
    }
    return NULL;
}
int main (int argc, char *argv[]) {
    int a[10]={2,4,6,8,10,12,14,16,18,20};
    int boyut=sizeof(a)/sizeof(a[0]);
    int search=18;

    printf("%d", *(a+9 ));
        int *result = findelement(a,boyut,search);
        if (result!=NULL)
            printf("bulundu %d", result - a);
        else if (result == NULL)
            printf("bulunmadı");

}>1