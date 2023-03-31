#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[32];
    char post[32];
    int year;
    int money;
} Info;

int search(Info info[]);

int main(int argc, char *argv[])
{
    Info info[6];
    FILE *fp;
    char *fname, tmp[256], input_name[32];

    if (argc < 2) {
        printf("引数が不足"); exit(1);
    } else {
        fname = argv[1];
    }

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("ファイルが開けません"); exit(1);
    }

    int i = 0;
    while (fgets(tmp, sizeof(tmp), fp) != NULL) {
        sscanf(tmp, "%d%s%s%d%d", &info[i].id, info[i].name, info[i].post, &info[i].year, &info[i].money);
        printf("%d\t%s\t%s\t%d\t%d\n", info[i].id, info[i].name, info[i].post, info[i].year, info[i].money);
        i++;
    }

    i = 0; 
    int idx = search(info);
    if (idx == -1) {
        printf("該当するデータはありません"); exit(1);
    }
    
    printf("%d\t%s\t%s\t%d\t%d\n", info[idx].id, info[idx].name, info[idx].post, info[idx].year, info[idx].money);

    return 0;
}

int search(Info info[]) {
    char input[32];
    printf("入力："); scanf("%s", input);
    int i = 0;
    while (1) {
        if (strcmp(input, info[i].name) == 0) {
            return i;
        }
        if (i == 5) {
            return -1;
        } 
        i++;
    }
}