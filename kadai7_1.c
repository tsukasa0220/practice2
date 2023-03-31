#include <stdio.h>

void divide_Real(double x, int *p_i, double *p_f)
{
    *p_i = (int)x;
    *p_f = x - (int)x;
}

int main(void) {
    int i;
    double x, f;

    printf("入力：");
    scanf("%lf", &x);

    divide_Real(x, &i, &f);

    printf("整数部：%d\n", i);
    printf("少数部：%f\n", f);
    return 0;
}