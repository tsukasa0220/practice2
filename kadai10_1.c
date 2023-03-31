#include <stdio.h>

int chrCount(char *p, char c)
{
    int cnt = 0;
    while (*p++) {
        if (*p == c) {
            cnt++;
        }
    }
    return cnt;
}

int main(void) 
{
    char c, str[100];
    printf("c:");
    scanf("%c", &c);
    printf("str:");
    scanf("%s", str);
    
    printf("%d個\n", chrCount(str, c));
    return 0;
}