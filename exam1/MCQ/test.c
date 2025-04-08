#include <stdio.h>

void reverse(int a[], int n){
    int i;
    for (i=0; i<n; i++){
        int temp;
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
}

int main()
{
    double sum = 0.;
    for (int i=0; i< 1000000; i++) 
        sum+= 1/i/i;
    printf("sum = %lf\n", sum);
    return 0;

    int flat[5] = {1, 2, 3, 4, 5};
    reverse(flat, 5);
    printf("%d\n", flat);
}