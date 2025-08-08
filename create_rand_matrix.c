#include <stdio.h>
/*
soru4: Rastgele bir 4*5 lik matrix oluşturun
en: Create a random 4x5 matrix.

*/
#define FSIZE 4
#define SSIZE 5

int main() {
    srand(time(NULL)); 
    int sayılar=1;
    int matrix[FSIZE][SSIZE]={0};
    for (int i=0;i<FSIZE;i++){
        for (int j=1;j<=SSIZE;j++){
            matrix[i][j]=rand()%1000;
            printf("%d\t",matrix[i][j]);
            sayılar++;
            
        }
    
        printf("\n");

    }

}

