#include <stdio.h>
#include <math.h>

double roundOff(double x, int n)
{
    double tmp;
    tmp = x * pow(10.0 ,n);
    if (tmp >= (int)tmp + 0.5) {
        tmp += 1.0;
    }
    return (int)tmp / pow(10.0, n);
}

int main(void)
{
    double x;
    int n;
    printf("x：");
    scanf("%lf", &x);
    printf("n：");
    scanf("%d", &n);
    printf("%f", roundOff(x, n));
    return 0;
}