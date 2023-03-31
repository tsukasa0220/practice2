#include <stdio.h>
#include <string.h>
#define MAX_STRING 30

typedef struct {
    int base;
    int housing;
    int trans;
    int support;
} Pay;

typedef struct {
    int id;
    char name[MAX_STRING];
    char post[MAX_STRING];
    int year;
    char trans[MAX_STRING];
    Pay pay;
} Info;

int totalPay(Pay total);

int main(void) {

    Info info[5] = {
    {127, "Humphrey",  "s_chief", 21, "Bus",   {400000, 10000, 4000,  25000}},
    {204, "Cary",      "s_chief", 15, "Train", {350000, 10000, 5000,  15000}},
    {255, "James",     "chief",   12, "Bus",   {300000, 0,     2000,  0}},
    {272, "Katharine", "member",  10, "Walk",  {270000, 27000, 0,     0}},
    {300, "Bette",     "member",  5,  "Train", {240000, 1000,  15000, 0}}
    };

    char tmp[MAX_STRING];
    int flg = 0;

    printf("役職："); scanf("%s", tmp);

    for (int i = 0; i < 5; i++) {
        if (strcmp(tmp, info[i].post) == 0) {
            printf("%d %s %s %d %s %d\n", info[i].id, info[i].name, info[i].post, info[i].year, info[i].trans, totalPay(info[i].pay));
            flg = 1;
        }
    }

    if (flg == 0) {puts("該当なし");}

    return 0;
}

int totalPay(Pay pay)
{
    return pay.base + pay.housing + pay.trans + pay.support;
}