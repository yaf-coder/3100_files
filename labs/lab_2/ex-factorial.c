/* This program should read a single integer from standard input then
 * compute its factorial. For example, if the user enters 5, the program should
 * output 120 because 1*2*3*4*5=120. */

#include <stdio.h>

int factorial(int n)
{
    if(n <= 1)
        return 1;
    return (n * factorial(n-1));
}

int main()
{
    int n, result;

    if (scanf("%d", &n) != 1 || n < 0) { 
        printf("Error: Please enter a non-negative integer.\n");
        return 1;
    }
    result = factorial(n);
    printf("%d\n", result);
    return 0;
}