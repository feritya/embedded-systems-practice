//
// Created by Derslik3-08 on 28.08.2025.
//
// (163)1010 0011 -> (168)1011 1100 30p bitsel işlemle 2 . değeri bulucaz

#include <stdio.h>
#include <stdint.h>

#define F_BIT   163

int main (int argc, char *argv[]) {
    int  bit=F_BIT;
    bit ^=(1<<4);
    bit ^=(1<<3);
    bit ^=(1<<2);
    bit ^=(1<<1);
    bit ^=(1<<0);

    printf("%u",bit);
}
