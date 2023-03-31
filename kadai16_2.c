#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUM1 173
#define NUM2 16381

int loadData(char latestDate[]);
void saveData(int money);

int main(int argc, char *argv[]) {

    char latestDate[32];
    int money, out;

    money = loadData(latestDate);

    printf("最終更新日時：%s\n", latestDate);
    printf("前回の所持金：%d円\n", money);
    if (argc == 2) {
        printf("今日の収入額：%s\n", argv[1]);
        money += atoi(argv[1]);    
    }

    puts("-----");
    printf("今日の支出額："); scanf("%d", &out);
    puts("-----");
    money -= out;

    printf("現在の所持金：%d円\n", money);

    saveData(money);

    return 0;
}

int loadData(char latestDate[])
{
    FILE *fp;

    if ((fp = fopen("data_file.bin", "rb")) == NULL) {
        strcpy(latestDate, "記録を開始します");
        return 0;
    } else {
        int money;
        fread(&money, sizeof(int), 1, fp);
        money = (money - NUM2) / NUM1;

        struct tm local;
        fread(&local, sizeof(struct tm), 1, fp);
        sprintf(latestDate, "%d年%d月%d日%d時%d分%d秒", local.tm_year+1900, local.tm_mon+1, local.tm_mday, local.tm_hour, local.tm_min, local.tm_sec);

        fclose(fp);

        return money;
    }
}

void saveData(int money)
{
    FILE *fp;

    fp = fopen("data_file.bin", "wb");

    money = money * NUM1 + NUM2;
    fwrite(&money, sizeof(int), 1, fp);

    time_t timer;
    struct tm *local;
    time(&timer);
    local = localtime(&timer);
    fwrite(local, sizeof(struct tm), 1, fp);
    
    fclose(fp);
}