#include <stdio.h>

void extrack_consonant(const char s[])
{
    int i = 0;
    while (s[i]) {
        if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
            i++;
        } else {
            putchar(s[i]);
            i++;
        }
    }
}

int main(void)
{
    char str[128];

    printf("文字列：");
    scanf("%s", str);
    extrack_consonant(str);

    return 0;
}