#include <stdio.h>

void str_rev(const char s[])
{
    int len = 0;
    while (s[len]) {
        len++;
    }

    for (int i = 0; i <= len; i++) {
        putchar(s[len - i]);
    }
}

int main(void)
{
    char str[128];

    printf("文字列：");
    scanf("%s", str);
    str_rev(str);

    return 0;
}