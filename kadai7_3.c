#include <stdio.h>
#define N 11

void calcMaxMinAve(const int v[], int *p_max, int *p_min, double *p_ave)
{
    int i;
    *p_max = v[0];
    *p_min = v[0];
    *p_ave = v[0];
    for (i = 1; v[i] != -1; i++) {
        if (v[i] > *p_max) {
            *p_max = v[i];
        }
        if (v[i] < *p_min) {
            *p_min = v[i];
        }
        *p_ave += v[i];
    }
    *p_ave = *p_ave / i;
}

int main(void) {
    int score[N], max, min;
    double ave;

    puts("入力");
    for (int i = 0; i < N - 1; i++) {
        printf("点数%d：", i + 1);
        scanf("%d", &score[i]);
        if (score[i] == -1) {
            break;
        }
        if (i == N - 2) {
            score[N - 1] = -1;
        }
    }

    calcMaxMinAve(score, &max, &min, &ave);

    puts("出力");
    printf("最大：%d\n", max);
    printf("最小：%d\n", min);
    printf("平均：%.1f\n", ave);

    return 0;
}