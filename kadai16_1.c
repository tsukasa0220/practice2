#include <stdio.h>

int load(void);
void save(int money);

int main(int argc, char *argv[]) 
{
    int in, out, money;
    
    printf("前回の所持金：%d円\n", money = load()); 

    puts("-----");
    printf("今日の収入額："); scanf("%d", &in);
    printf("今日の支出額："); scanf("%d", &out);
    puts("-----");

    money = money + in - out;

    printf("現在の所持金：%d円\n", money); 

    save(money);

    return 0;
}

int load(void)
{
    FILE *fp;

    if ((fp = fopen("data_file.txt", "r")) == NULL) {
        return 0;
    } else {
        int tmp;
        fscanf(fp, "%d", &tmp);
        fclose(fp);
        return tmp;
    }
}

void save(int money)
{
    FILE *fp;

    fprintf(fp = fopen("data_file.txt", "w"), "%d", money);
    fclose(fp);
}