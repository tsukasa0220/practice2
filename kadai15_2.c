#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char *fname, tmp[256];

    if (argc < 3) {
        printf("引数が不足"); exit(1);
    } else {
        fname = argv[2];
    }

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("ファイルが開けません"); exit(1);
    }

    int i = 1;
    while(fgets(tmp, sizeof(tmp), fp) != NULL) {
        if (strstr(tmp, argv[1]) != NULL) {
            printf("%d:%s", i, tmp);
        }
        i++;
    }

    fclose(fp);

    return 0;
}