#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int strKeynum(char *str, char *key) 
{
    int cnt = 0;
    char *p1 = key, *p2 = str;
    while (strlen(str) - strlen(key) + 1) {
        while (*p1) {
            if (*p2 != *p1) {
                break;
            }
            p1++;
            p2++;
        }
        if(!*p1) {
            cnt++;
        }
        str++;
        p2 = str;
        p1 = key;
    }    
    return cnt;
}

int main(void) 
{
    char str[MAX_LENGTH], key[MAX_LENGTH];
    printf("str:");
    scanf("%s", str);
    printf("key:");
    scanf("%s", key);

    printf("%d個含まれている", strKeynum(str, key));

    return 0;
}