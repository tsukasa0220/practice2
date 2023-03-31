#include <stdio.h>

int main(void)
{
    int n, m, cnt = 0;
    printf("n:");
    scanf("%d", &n);
    printf("m:");
    scanf("%d", &m);

    for (int i = n; i <= m; i++) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            cnt++;
            printf("%d年\n", i);
        }
    }
    printf("%d回\n", cnt);
    

    return 0;
}