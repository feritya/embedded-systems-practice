/*
en: Write a program that checks if a student number exists in a predefined list of students and prints the class number if found.
*/
#include <stdio.h>

int main() {
    int student_list[3][4]={ {120,258,330,332},
                            {278,323,100,200},
                            {578,145,772,287}
};
    int sınıf,ogrenci_no=10, var=0;
    scanf("%d\n",&ogrenci_no);

    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            if (student_list[i][j]==ogrenci_no){
                var=1;
                sınıf=i+1;}
                
        }
    }
    if (var==0)
        printf("yok");
    else 
        printf("var ve sınıfı :%d numaralı sınıf ",sınıf);

}

