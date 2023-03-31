#include <stdio.h>
#include <time.h>

int main(void)
{
    int p, n;
    srand((unsigned)time(NULL));

    puts("ぐー：0, ちょき：1, ぱー：2");

    while (1) {
        printf("あなたの手：");
        scanf("%d", &p);

        if (p != 0 && p != 1 && p != 2) {
            continue;
        }

        n = rand() % 3;
        
        printf("Computer ");
        switch (n) {
            case 0: printf("ぐー"); break;
            case 1: printf("ちょき"); break;
            default :printf("ぱー"); break;
        }
        printf(" vs ");
        switch (p) {
            case 0: printf("ぐー"); break;
            case 1: printf("ちょき"); break;
            default :printf("ぱー"); break;
        }
        puts(" あなた");

        if (p == n) {
            puts("あいこでしょ");
        } else if ((p == 0 && n == 1) || (p == 1 && n == 2) || (p == 2 && n == 0)) {
            puts("あなたの勝ちです！");
            break;
        } else {
            puts("あなたの負けです…");
            break;
        }
    }
    return 0;
}