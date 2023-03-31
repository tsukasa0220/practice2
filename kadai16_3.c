// 前回の支出の日時,品目,支出額,所持金を追加
// 支出の品目を追加

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUM1 173
#define NUM2 16381

void loadData(char latestDate[], char name[], int *p_out, int *p_money);
void saveData(char n_name[], int *p_out, int *p_money);

int main(int argc, char *argv[]) {

    char latestDate[32], name[32], n_name[32];
    int money = 0, out = 0;

    loadData(latestDate, name, &out, &money);

    puts("前回の支出");
    printf("日時：%s\n", latestDate);
    printf("支出品目：%s\n", name);
    printf("支出額：%d円\n", out);
    printf("所持金：%d円\n", money);
    putchar('\n');

    if (argc == 2) {
        printf("追加した収入額：%s円\n", argv[1]);
        money += atoi(argv[1]);    
    }

    puts("今回の支出");
    printf("支出品目："); scanf("%s", n_name);
    printf("支出額："); scanf("%d", &out);
    putchar('\n');
    money -= out;

    if (money < 0) {printf("※支出額が所持金を超えています"); exit(1);}

    printf("現在の所持金：%d円\n", money);

    saveData(n_name, &out, &money);

    return 0;
}

void loadData(char latestDate[], char name[], int *p_out, int *p_money)
{
    FILE *fp;
    if ((fp = fopen("data_file2.bin", "rb")) == NULL) {
        strcpy(latestDate, "記録を開始します");
        strcpy(name, "なし");
    } else {
        struct tm local;
        fread(&local, sizeof(struct tm), 1, fp);
        sprintf(latestDate, "%d年%d月%d日%d時%d分%d秒", local.tm_year+1900, local.tm_mon+1, local.tm_mday, local.tm_hour, local.tm_min, local.tm_sec);

        fread(name, sizeof(char), sizeof(name), fp);

        fread(p_out, sizeof(int), 1, fp);

        fread(p_money, sizeof(int), 1, fp);
        *p_money = (*p_money - NUM2) / NUM1;

        fclose(fp);
    }
}

void saveData(char n_name[], int *p_out, int *p_money)
{
    FILE *fp;
    fp = fopen("data_file2.bin", "wb");

    time_t timer;
    struct tm *local;
    time(&timer);
    local = localtime(&timer);
    fwrite(local, sizeof(struct tm), 1, fp);

    fwrite(n_name, sizeof(char), sizeof(n_name), fp);

    fwrite(p_out, sizeof(int), 1, fp);

    *p_money = *p_money * NUM1 + NUM2;
    fwrite(p_money, sizeof(int), 1, fp);
    
    fclose(fp);
}