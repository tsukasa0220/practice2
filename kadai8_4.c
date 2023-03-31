#include <stdio.h>
#define N 11

void calcOdd(int *arr, int *p_oddNum, int *p_oddSum) 
{
    while (*arr)
    {
        if (*arr % 2 != 0) {
            *p_oddNum += 1;
            if (*arr > 0) {
                *p_oddSum += *arr;
            }
        }
        arr++;
    }
    
}

int main(void)
{
    int arr[N], i, oddNum = 0, oddSum = 0;

    printf("データ：");
    for (i = 0; i < N - 1; i++) {
        scanf("%d", &arr[i]);
        if (!arr[i]) {
            break;
        }
        if (i == N - 2){
            arr[N - 1] = 0;
        }
    }

    calcOdd(arr, &oddNum, &oddSum);

    printf("奇数の個数：%d\n", oddNum);
    printf("正の奇数の総和：%d\n", oddSum);

    return 0;
}