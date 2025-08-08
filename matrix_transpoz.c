#include <stdio.h>
/*
5'e 5 lik elemanları rastgele verilmiş bir matrisi
şu forma çeviriniz

en:
Transform a 5 by 5 matrix with randomly assigned elements into the following form:

transpo

1 0 0 0 0   0 0 0 0 1
0 1 0 0 0   0 0 0 1 0
0 0 1 0 0   0 0 1 0 0
0 0 0 1 0   0 1 0 0 0
0 0 0 0 1   1 0 0 0 0
*/
#define FSIZE 5
#define SSIZE 5

int main() {
    int matrix[FSIZE][SSIZE]={0};
    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            matrix[i][j]=0;
            if (i==j)
                matrix[i][j]=1;
            //matrix[i][j]=rand()%10;
            printf("%d\t",matrix[i][j]);

        }
    
        printf("\n");

    }
            printf("\n");

    for (int i=0;i<FSIZE;i++){
        for (int j=SSIZE-1;j>=0;j--){
            printf("%d\t",matrix[i][j]);

        }
    
        printf("\n");

    }


}

