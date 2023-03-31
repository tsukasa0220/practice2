#include <stdio.h>
#define MAX_LENGTH 100

char *delChar(char *str, char c) 
{
    char *tmpStr, *p = str;
    while (*str) {
        if (*str == c) {
            tmpStr = str;
            while (*str) {
                *str = *(str + 1);
                str++;
            }
            *str = '\0';
            str = tmpStr;
        } else {
            str++;
        }
    }
    return p;
}

int main(void) 
{
    char str[MAX_LENGTH], c;
    
    printf("c:");
    scanf("%c", &c);
    printf("str:");
    scanf("%s", str);

    printf("出力：%s\n", delChar(str, c));

    return 0;
}