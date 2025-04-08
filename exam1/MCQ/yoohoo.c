#include <stdio.h>
int main(){
    // int a[10], *p = a, i;

    // for (i=0; i<10; i++) *++p = i;
    
    // for (i=0; i<10; i++)
    //     printf("%d", a[i]);
    // printf("\n");

    // return 0;

    int a[] = {1, 2, 3};

    char *p = a;

    printf("%d\n", p[0] + p[1] + p[2]);
    return 0;
}