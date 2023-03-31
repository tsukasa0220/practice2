#include <stdio.h>
#define MAX_LENGTH 100

void strMix(char *str1, char *str2, char *str3)
{

    while (*str1 && *str2) {
        *str3 = *str1;
        str1++;
        str3++;
        *str3 = *str2;
        str2++;
        str3++;
    }
    while (*str1) {
        *str3 = *str1;
        str1++;
        str3++;
    }
    while (*str2) {
        *str3 = *str2;
        str2++;
        str3++;
    }
    str3 = '\0';
}
int main(void) 
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH], str3[MAX_LENGTH] = "";
    printf("str1:");
    scanf("%s", str1);
    printf("str2:");
    scanf("%s", str2);

    strMix(str1, str2, str3);

    printf("出力：%s\n", str3);

    return 0;
}