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

void makePreca(Card preca[], int n);
void dumpPreca(Card preca[], int n);
int rand_only(Card preca[], int j);

int main(void)
{
    int n;
    Card preca[100];
    
    srand((unsigned)time(NULL));

    printf("発行枚数："); scanf("%d", &n);

    makePreca(preca, n);

    dumpPreca(preca, n);

    return 0;
}

void makePreca(Card preca[], int n)  
{
    int i;
    for (i = 0; i < n; i++) {
        preca[i].id = i + 1;
        preca[i].balance = 1000;
        preca[i].year = 2026;
        preca[i].month = 3;
        preca[i].day = 31;
        preca[i].code = rand_only(preca, i);
    }
}

void dumpPreca(Card preca[], int n) 
{
    int i;
    for (i = 0; i < n; i++) {
        printf("#%d：%d、%d年%d月%d日、%04d\n", preca[i].id, preca[i].balance, preca[i].year, preca[i].month, preca[i].day, preca[i].code);
    }
}

int rand_only(Card preca[], int j)
{
    int tmp, i;
    while (1) {
        tmp = rand() % 10000;
        for (i = 0; i < j; i++) {
            if (tmp == preca[i].code) {
                tmp = 0;
                break;    
            }
        }
        if (tmp) {return tmp;}
    }
}