#include <stdio.h>
#define PI 3.14
void area(double *r){
    double a = PI * *r * *r; 
    printf("%lf",a);
}

int main (){

  double x=5;
    area(&x);
    return 0;

}