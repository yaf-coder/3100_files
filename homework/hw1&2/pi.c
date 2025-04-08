#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i;
    printf("n = ");
    scanf("%d", &n);

    double pi = 0.0;
    double t16 = 1.0;

    for (i=0; i<=n; i++){
        double n_term = (4.0/(8.0*i + 1.0) - 2.0/(8.0*i + 4.0) - 1.0/(8.0*i + 5.0) - 1.0/(8.0*i + 6.0));
        n_term *= t16;
        t16 /= 16.0;
        pi += n_term;
    }
    printf("PI = %.10f\n", pi);
    return 0;
}