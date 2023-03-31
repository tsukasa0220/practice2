#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

char *dicSearch(char *dic[7], char *key)
{
    for (int i = 0; i < 7; i++) {
        if (!strcmp(dic[i], key)) {
            return dic[i];
        }
    }
    return NULL;
}

int main(void) 
{
    char key[MAX_LENGTH];
    char *dic[7] = {
    "sunday", "monday", "tuesday", "wednesday",
    "thursday", "friday", "saturday" 
    };

    while (1) {
        printf("key：");
        scanf("%s", key);
        if (!strcmp(key, "XXXXX")) {
            break;
        }
        if (dicSearch(dic, key)) {
            puts("ある");
        } else {
            puts("ない");
        }
    }
    
    return 0;
}