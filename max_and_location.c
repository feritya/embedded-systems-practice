#include <stdio.h>
/*
soru7: matrixdeki en büyük elemanı ve yerini bulan programı
en:Write a program that finds the largest element in a matrix and its location.
*/
#define FSIZE 4
#define SSIZE 5

int main() {
    int max,location[2];
    int matrix[FSIZE][SSIZE]={0};
    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            matrix[i][j]=rand()%100;
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    max=matrix[0][0];


    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            if (matrix[i][j] > max){
                max=matrix[i][j];
                location[0]=i;
                location[1]=j;
            }

        }
    }
    
            printf("\n%d \t %d,%d",max,location[0]+1,location[1]+1);


}
