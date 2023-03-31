#include <stdio.h>
#include <time.h>

int vs(void) {
    int p, n;
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
            return 1;
        } else {
            puts("あなたの負けです…");
            return 0;
        }
    }
}

int main(void)
{
    int money = 200;
    srand((unsigned)time(NULL));

    while (money != 0 && money != 500) {
        money -= 100;
        printf("掛け金を支払いました（現在の所持金：%d円）\n", money);
        if (vs()){
        money += 200;
        }
        printf("現在の所持金は%d円です\n", money);
    }

    if (money == 500) {
        printf("ｷﾀ━━━ヽ(∀ﾟ )人(ﾟ∀ﾟ)人( ﾟ∀)ノ━━━!");
    } else {
        puts("破産しました。ゲーム終了です");
    }

    return 0;
}