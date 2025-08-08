#include <stdio.h>

/*
Soru1: 3 satır 4 sutunden oluşan bir matrix tanımlayın
tüm elemanlarını 5 yapın.
en: Define a matrix with 3 rows and 4 columns, setting all elements to 5.
*/
#define FSIZE 3
#define SSIZE 4

int main() {
    int matrix[FSIZE][SSIZE]={0};
    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            matrix[i][j]=5;
            printf("%d\t",matrix[i][j]);
            
        }
    
        printf("\n");

    }

}

