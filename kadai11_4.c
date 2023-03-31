#include <stdio.h>

char *myStrrChr(char *s, char c)
{
    char *p = NULL;
    while (*s) {
        if (*s == c) {
            p = s;
        }
        s++;
    }
    return p;
}

int main(void) {
    int c;
    char str[] = "the quick brown fox jumps over the lazy dog.";
    char *ptr;

    printf("入力："); 
    c = getchar();
    ptr = myStrrChr(str, c);
    if (ptr) {
        printf("%c の最後の出現位置は %d，残りの文字列は %s です\n", c, (int)(ptr-str), ptr);
    } else {
        printf("%c は %s に出現しません\n", c, str);
    } 
    return 0;
}