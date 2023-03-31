#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 100

void strSep(char *str1, char *str2, char *str3)
{   
    while (*str1) {
        if (isalpha(*str1)) {
            *str2 = *str1;
            str2++;
        } else {
            *str3 = *str1;
            str3++;
        }
        str1++;
    }
    str2 = '\0';
    str3 = '\0';
}

int main(void) 
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH] = "", str3[MAX_LENGTH] = "";
    printf("入力:");
    scanf("%s", str1);

    strSep(str1, str2, str3);

    printf("str1:%s\n", str2);
    printf("str2:%s\n", str3);
    
    return 0;
}