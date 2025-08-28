#include <stdio.h>
void swap(double* x,double* y){
    double temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
int main (){

  double x=5,y=10;
    swap(&x,&y);
    printf("%d %d",x,y);

    return 0;
}