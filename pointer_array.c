#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 5


void writePointerArr(size_t arr_size,const char * arr) {

for (int i=0;i<arr_size;i++) {
    printf("%c\n",arr[i]);
}

}

int main() {

    const char *pa [5]={"ali","veli","selami","hayri","can"};
    size_t arr_size=strlen(pa);
    writePointerArr(arr_size,*pa);


    return 0;
}