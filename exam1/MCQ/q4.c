#include <stdio.h>
#include <stdlib.h>

int main(){
    // int a[] = {1, 2, 3};

    // int *p = a;

    // // *p++;
    // // printf("%d\n", a[0]);

    // int r = (unsigned long) p == (unsigned long) &p;

    // printf("%d\n", r);

    // return 0;

    int t[10];
    char * p = (char *) t + 8;
    char * q = (char *) (t + 8);

    printf("%ld\n", q - p);

}