#include <stdio.h>

int main(void)
{
    char c;
    char str[128];
    int i = 0;

    printf("文字：");
    scanf("%c", &c);
    printf("文字列：");
    scanf("%s", str);

    while (1) {
        if (str[i] == c) {
            puts("含まれます");
            break;
        } else if (str[i] == '\0') {
            puts("含まれません");
            break;
        } else {
            i++;
        }
    }

    return 0;
}