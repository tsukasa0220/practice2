#include <stdio.h>

int main(void)
{
    int cost, price; 
    double profitRate;

    printf("原価:");
    scanf("%d", &cost);
    printf("価格:");
    scanf("%d", &price);

    profitRate = (double)(price - cost) / price * 100;

    printf("利益率は%.1f%%です。\n", profitRate);
    return 0;
}