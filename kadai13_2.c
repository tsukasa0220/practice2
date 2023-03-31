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

void printPreca(Card no);

int main(void)
{
    srand((unsigned)time(NULL));

    Card no1 = {1, 1000, 2026, 3, 31, rand() % 10000};

    printPreca(no1);
    return 0;
}

void printPreca(Card no) 
{
    printf("#%d：%d、%d年%d月%d日、%04d\n", no.id, no.balance, no.year, no.month, no.day, no.code);
}