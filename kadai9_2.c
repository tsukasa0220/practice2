#include <stdio.h>
#include <limits.h>

void min_maxArr(int datArray[][9], int resArray[][2], int len) 
{
    for (int i = 0; i < len; i++) {
        resArray[i][0] = minArr(datArray[i]);
        resArray[i][1] = maxArr(datArray[i]);
    } 
}

int minArr(int *p)
{
    int min = *p;
    p++;
    while (*p != INT_MIN) {
        if (*p < min) {
            min = *p;
        }
        p++;
    }
    return min;
}

int maxArr(int *p)
{
    int max = *p;
    p++;
    while (*p != INT_MIN) {
        if (*p > max) {
            max = *p;
        }
        p++;
    }
    return max;
}

int main(void)
{
    int data[3][9] = {
        {3, 5, 7, 1, 2, 3, 4, 0, INT_MIN},
        {10, 100, 5, 1, 0, -10, 15, 9, INT_MIN},
        {0, 5, -1, -3, 8, 2, 6, -8, INT_MIN}
    };
    int result[3][2];

    min_maxArr(data, result, 3);

    for (int i = 0; i < 3; i++) {
        printf("data%dの最小値：%d、最大値：%d\n", i + 1, result[i][0], result[i][1]);
    } 

    return 0;
}