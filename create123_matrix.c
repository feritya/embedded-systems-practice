#include <stdio.h>
/*
Soru 3:

1 2 3
1 2 3
1 2 3
1 2 3

*/
#define FSIZE 4
#define SSIZE 3

int main() {
    int sayılar=1;
    int matrix[FSIZE][SSIZE]={0};
    for (int i=0;i<FSIZE;i++){
        sayılar=1;
        for (int j=0;j<SSIZE;j++){
            matrix[i][j]=sayılar;
            printf("%d\t",sayılar);
            sayılar++;
            
        }
    
        printf("\n");

    }

}

