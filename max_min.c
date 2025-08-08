#include <stdio.h>
/*
soru6: matrixdeki en büyük ve en küçük elemanı bulan programı yazınız
en:
Write a program that finds the largest and smallest elements in a matrix.

*/
#define FSIZE 4
#define SSIZE 5

int main() {
    int max,min;
    int matrix[FSIZE][SSIZE]={0};
    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            matrix[i][j]=rand()%100;
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    max=matrix[0][0];
    min=matrix[0][0];


    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            if (matrix[i][j] > max){
                max=matrix[i][j];}
                
            else if(matrix[i][j] < min){
                min=matrix[i][j];}
        
        }
    }
            printf("\n%d \t %d",max,min);


}
