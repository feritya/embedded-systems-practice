#include <stdio.h>
/*
soru8: Her sütünün toplamı ve ortalamasını ekrana yazdıran program.
en:Write a program that prints the sum and average of each column in a matrix.
*/

#define FSIZE 4
#define SSIZE 5

int main() {
    int max,sum=0,average;
    int matrix[FSIZE][SSIZE]={0};
    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            matrix[i][j]=rand()%100;
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    max=matrix[0][0];


    for (int i=0;i<SSIZE;i++){
        sum=0;
        for (int j=0;j<FSIZE;j++){
                sum+=matrix[j][i];

        }
        average=sum/FSIZE;
        printf("%d\t%d\n",sum,average);

    }
    


}
