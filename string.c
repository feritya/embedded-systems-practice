#include <stdio.h>
#include <string.h>
int myputs(const char *p) {
    int a=1;
    while (*p!='\0') {
        putchar(*p);
        p++;
        a++;
    }
return a;
}


int main (int argc, char *argv[]) {
    char name[30]="FeritYaşar";
        char surname[30]="Yasar";

    printf("\n %d",myputs(name));


}
