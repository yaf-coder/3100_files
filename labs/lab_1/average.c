#include <stdio.h>

int main(void) {
    double total = 0.0;
    double num;
    int count = 0;

    while (scanf("%lf", &num) == 1) {
        total += num;
        count++;
        printf("Total=%f Average=%f\n", total, total / count);
    }

    return 0;
}
