#include <stdio.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Due;

typedef struct {
    int id;
    int balance;
    Due due;
    int code;
} Card;

void makePreca(Card preca[], int n);
void dumpPreca(Card preca[], int n);
int rand_only(Card preca[], int j);
int payPreca(Card preca[], int n);

int main(void)
{
    int n, payId;
    Card preca[100];
    
    srand((unsigned)time(NULL));

    printf("発行枚数："); scanf("%d", &n);

    makePreca(preca, n);

    dumpPreca(preca, n);

    puts("---");
    puts("支払い処理");
    payId = payPreca(preca, n);
    puts("---");

    if (payId != -1) {
        puts("支払い完了");
        printf("#%d：%d、%d年%d月%d日、%04d\n", preca[payId].id, preca[payId].balance, preca[payId].due.year, preca[payId].due.month, preca[payId].due.day, preca[payId].code);
    } else {
        puts("支払い失敗");
    }

    return 0;
}

void makePreca(Card preca[], int n)  
{
    int i;
    for (i = 0; i < n; i++) {
        preca[i].id = i + 1;
        preca[i].balance = 1000;
        preca[i].due.year = 2026;
        preca[i].due.month = 3;
        preca[i].due.day = 31;
        preca[i].code = rand_only(preca, i);
    }
}

void dumpPreca(Card preca[], int n) 
{
    int i;
    for (i = 0; i < n; i++) {
        printf("#%d：%d、%d年%d月%d日、%04d\n", preca[i].id, preca[i].balance, preca[i].due.year, preca[i].due.month, preca[i].due.day, preca[i].code);
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

int payPreca(Card preca[], int n)
{
    int id, code, pay, cannot = 0;

    printf("ID："); scanf("%d", &id);
    id--;
    printf("セキュリティコード："); scanf("%d", &code);
    printf("金額："); scanf("%d", &pay);

    if (code != preca[id].code) {cannot = -1;}
    if (pay <= preca[id].balance && pay > 0) {
        preca[id].balance -= pay;
    } else {cannot = -1;}

    if(cannot != -1) {
        printf("残高：%d円\n", preca[id].balance);
        return id;
    } else {
        return -1;
    }
}