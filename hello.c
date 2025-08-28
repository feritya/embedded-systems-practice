#include <stdio.h>
#define PI 3.141592653589793238462643383279502884
void findareaenv(double r,double *env ,double *area){
    *area = PI * r * r;
    *env  = PI * r * 2;
}

int main (){
  int r=5;
    double env,area;
    findareaenv(r,&env,&area);
    printf("%.4lf\n",area);
    printf("%.4lf\n",env);
    return 0;

}