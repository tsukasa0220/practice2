// 支出品名の入力,最近までの支出履歴(最大10)を追加

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUM1 173
#define NUM2 16381
#define LENGTH 32
#define MAX 10

struct _hist {
    char name[LENGTH];
    int out;
    int balance;
} hist[MAX];

int main(int argc, char *argv[]) {

    char latestDate[MAX][LENGTH], n_name[LENGTH];
    int n_balance, n_out;

    n_balance = loadData(latestDate);
    
    puts("\n-----最近の支出-----");
    puts("日時|支出品名|支出額|残高");
    for (int i = 0; i < MAX, i++) {
        if (latestDate[i] == NULL) {break;}
        printf("%s|%10s|%10d|%10d\n", latestDate[i], name[i], out[i], balance[i]);
    }
    putchar('\n');

    if (argc == 2) {
        printf("今日の収入額：%s\n", argv[1]);
        n_balance += atoi(argv[1]);    
    }
    if (n_balance <= 0) {
        printf("※所持金がありません"); exit(1);
    }


    puts("-----");
    printf("支出品名："); scanf("%s", n_name);
    printf("今日の支出額："); scanf("%d", &n_out);
    puts("-----\n");

    n_balance -= n_out;
    if (n_balance < 0) {
        printf("※支出額が所持金を超えています"); exit(1);
    }

    printf("現在の所持金：%d円\n", n_balance);

    saveData(n_name, n_out, n_balance);

    return 0;
}

int loadData(char latestDate[][MAX])
{
    FILE *fp;

    if ((fp = fopen("data_file.bin", "rb")) == NULL) {
        strcpy(latestDate, "記録を開始します");
        return 0;
    } else {
        int n_balance;
        fread(&n_balance, sizeof(int), 1, fp);
        n_balance = (n_balance - NUM2) / NUM1;



        struct tm local;
        fread(&local, sizeof(struct tm), 1, fp);
        sprintf(latestDate, "%d年%d月%d日%d時%d分%d秒", local.tm_year+1900, local.tm_mon+1, local.tm_mday, local.tm_hour, local.tm_min, local.tm_sec);

        fclose(fp);

        return n_balance;
    }
}

void saveData(char n_name[], int out, int bala)
{
    FILE *fp;
    fp = fopen("data_file.bin", "ab");

    n_balance = n_balance * NUM1 + NUM2;
    fwrite(&n_balance, sizeof(int), 1, fp);

    fwrite(outName, sizeof(char), sizeof(outName), fp);

    time_t timer;
    struct tm *local;
    time(&timer);
    local = localtime(&timer);
    fwrite(local, sizeof(struct tm), 1, fp);
    
    fclose(fp);
}