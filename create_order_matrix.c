#include <stdio.h>

/*Soru2:
Şu matrisi elde ediniz
en: Create the following matrix
1 2 3
4 5 6
7 8 9
10 11 12
*/
#define FSIZE 4
#define SSIZE 3

int main() {
    int sayılar=1;
    int matrix[FSIZE][SSIZE]={0};
    for (int i=0;i<FSIZE;i++){
        for (int j=0;j<SSIZE;j++){
            matrix[i][j]=sayılar;
            printf("%d\t",matrix[i][j]);
            sayılar++;
            
        }
    
        printf("\n");

    }

}

