#include <stdio.h>
#define SUBJECTS 4

int main(void)
{
    int score[SUBJECTS] = {80, 100, 75, 62};
    int credit[SUBJECTS] = {2, 1, 2, 3};
    int s = 0, a = 0, b = 0, c = 0, x = 0, creditAll = 0;
    double gpa;

    printf("科目数:%d\n", SUBJECTS);

    for (int i = 0; i < SUBJECTS; i++) {
        printf("科目%dの点数:%d\n", i + 1, score[i]);
        printf("科目%dの単位数:%d\n", i + 1, credit[i]);

        creditAll += credit[i];

        if (90 <= score[i]) {
            s += credit[i];
        } else if  (80 <= score[i]) {
            a += credit[i];
        } else if (70 <= score[i]) {
            b += credit[i];
        } else if (60 <= score[i]) {
            c += credit[i];
        } else {
            x += credit[i];
        }
    }

    gpa = (double)(s * 4 + a * 3 + b * 2 + c * 1) / creditAll;

    printf("GPA:%.3f\n", gpa);

    return 0;
}