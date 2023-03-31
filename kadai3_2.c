#include <stdio.h>

int parkingFee(int minute)
{
    if (minute <= 60) {
        return 300;
    } else {
        return 300 + ((minute - 61) / 30 * 100 + 100);
    }
}

int main(void)
{
    int minute;
    printf("時間：");
    scanf("%d", &minute);
    printf("料金：%d円\n", parkingFee(minute));
    return 0;
}