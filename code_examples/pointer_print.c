#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int main(){
    int a = 5;
    int *b = &a;
    printf("%p\n", b);
    // returns memory address of a
    printf("%d\n", *b);
    // returns value of a
    printf("%p\n", &b);
    // returns memory address of pointer b


    // pointer to a pointer should point to the memory address of a pointer
    int **c = &b;
    printf("%p\n", c);
    // returns memory address of pointer b
    printf("%p\n", *c);
    // returns memory address of a
    printf("%d\n", **c);
    // returns value of a
    printf("%p\n", &c);
    // returns memory address of double pointer c
}