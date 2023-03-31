#include <stdio.h>

int main(void)
{
    int price, payment, tax, point;
    
    printf("商品代金（税抜き）:");
    scanf("%d", &price);

    tax = price / 10;
    payment = tax + price;
    point = payment / 10;

    printf("消費税%d円、お支払額%d円です\n", tax, payment);
    printf("%dポイントつきました\n", point);
    return 0;
}