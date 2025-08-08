

#include <stdio.h>
/*
soru5: oluşturdugunuz matrixde her satırdaki en buyuk elemanı
yazdıran programı yazınız.
en: Write a program that prints the largest element in each row of the matrix.
*/
#define FSIZE 4
#define SSIZE 5

int main() {
    int max;
    int matrix[FSIZE][SSIZE]={0};
    srand(time(NULL)); 

    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            matrix[i][j]=rand()%1000;
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int i=0;i<FSIZE;i++){
        max=matrix[0][0];
        for (int j=0;j<SSIZE;j++){
            if (matrix[i][j] > max)
                max=matrix[i][j];
            
        }
        printf("\n%d",max);
    }
    

}