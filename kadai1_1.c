#include <stdio.h>

int main(void) {
    int n1, n2, n3, max;
    puts("input:");
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 > n2 && n2 > n3) {
        puts("おめでとう");
    } else {
        puts("いいね");
    }
    return 0;
}