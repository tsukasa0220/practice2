#include <stdio.h>

int str_lenght(const char s[])
{
    int len = 0;
    while (s[len]) {
        len++;
    }
    return len;
}

void put_string(const char s[])
{
    int i = 0;
    while (s[i]) {
        putchar(s[i]);
        i++;
    }
}

int main(void)
{
    int n, len[5], max_len = 0;
    char str[5][128];
    printf("文字列数：");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("str[%d]：", i);
        scanf("%s", str[i]);
    }

    for (int i = 0; i < n; i++) {
        len[i] = str_lenght(str[i]);
        if (len[i] > max_len) {
            max_len = len[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (len[i] == max_len) {
            put_string(str[i]);
            printf("(%d)\n", len[i]);
        }
    }

    return 0;
}