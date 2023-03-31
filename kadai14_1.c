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

void initPreca(Card *p);
void printPreca(Card no);

int main(void)
{
    Card no1;
    initPreca(&no1);
    printPreca(no1);
    return 0;
}

void initPreca(Card *p)
{
    srand((unsigned)time(NULL));
    
    p->id = 1;
    p->balance = 1000;
    p->year = 2025;
    p->month = 3;
    p->day = 31;
    p->code = rand() % 10000;
}

void printPreca(Card no) 
{
    printf("#%d：%d、%d年%d月%d日、%04d\n", no.id, no.balance, no.year, no.month, no.day, no.code);
}