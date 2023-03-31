#include <stdio.h>
#include <stdlib.h>

double func(int c, char *v[]);

int main(int argc, char *argv[]) 
{
    double sum;

    if (argc < 2) {
        printf("引数が不足");
        exit(1);
    }

    sum = func(argc, argv);

    printf("sum = %.2f\n", sum);
    printf("ave = %.2f\n", sum / (argc - 1));

    return 0;
}

double func(int c, char *v[]) 
{
    double sum = 0;
    for (int i = 1; i < c; i++) {
        sum += atof(v[i]); 
    }
    return sum;
}