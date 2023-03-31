#include <stdio.h>
#define NUM 20

int ckLongestRun(int arr[], int n)
{
    int cnt = 0, max = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            cnt++;
        } else {
            if (cnt > max) {
                max = cnt;
            }
            cnt = 0;
        }
    }
    if (cnt > max) {
        max = cnt;
    }
    return max;
}

int main(void)
{
    int n = 0, arr[NUM], tmp;
    printf("入力：");
    for (int i = 0; i < NUM; i++) {
        scanf("%d", &tmp);
        if (tmp == -1) {
            break;
        }
        arr[i] = tmp;
        n++;
    }
    printf("出力：%d\n", ckLongestRun(arr, n));
    return 0;
}