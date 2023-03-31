#include <stdio.h>
#include <time.h>

typedef struct {
    int id;
    int balance;
    int year;
    int month;
    int day;
    int code;
} Card;

int main(void)
{
    srand((unsigned)time(NULL));

    Card no1 = {1, 1000, 2026, 3, 31, rand() % 10000};

    printf("ID：%d\n金額：%d\n有効期限：%d %d %d\nセキュリティコード：%04d\n", no1.id, no1.balance, no1.year, no1.month, no1.day, no1.code);

    return 0;
}