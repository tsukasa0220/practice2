#include <stdio.h>
#define MAX_LENGTH 100

int isSameChars(char *p, char c) 
{
    while (*p) {
        if (*p != c) {
            return 0;
        }
        p++;
    }
    return 1;
}

int main(void) 
{
    char c, s[MAX_LENGTH];

    printf("文字：");
    scanf("%c", &c);
    printf("文字列：");
    scanf("%s", s);

    printf("出力：");
    if (isSameChars(s, c)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}