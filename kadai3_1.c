#include <stdio.h>

double profitRatio(int cost, int price)
{
    return (double)(price - cost) / price * 100;
}

int main(void)
{
    int cost, price;
    printf("原価:");
    scanf("%d", &cost);
    printf("価格:");
    scanf("%d", &price);
    printf("利益率は%.1f%%です\n", profitRatio(cost, price));
    return 0;
}