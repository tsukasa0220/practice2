#include <stdio.h>
#include <time.h>
#define NUM 5
#define DEBUG 0

void random(int n, int arr[]) 
{
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 9 + 1;
    }
    return;
}

void inputer(int n, int arr[]) 
{
    int tmp;
    for (int i = 0; i < n; i++) {
        printf("n%d：", i + 1);
        scanf("%d", &tmp);
        arr[i] = tmp;
    }
    return;
}

int hitter(const int va[], const int vb[], int n)
{
    int hit = 0;
    for (int i = 0; i < n; i++) {
        if(va[i] == vb[i]) {
            hit++;
        }
    }
    return hit;
}

int blower(const int va[], const int vb[], int n)
{
    int blow = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vb[i] == va[j] && i != j) {
                blow++;
            }
        }
    }
    return blow;
}

int main(void)
{
    int answer[NUM], input[NUM], n, hit, tmp, cnt = 0;
    printf("n：");
    scanf("%d", &n);

    srand((unsigned)time(NULL));
    random(n, answer);

    if (DEBUG) {
        printf("answer(DEBUG) = ");
        for (int i = 0; i < n; i++) {
            printf("%d ", answer[i]);   
        }
        putchar('\n');
    }

    do {
        cnt++;
        inputer(n, input);
        hit = hitter(answer, input, n);
        if (hit == n) {
            printf("正解（%d回）\n", cnt);
            break;
        } else {
            printf("不正解：Hit数 = %d, Blow数 = %d\n", hit, blower(answer, input, n));
            printf("続ける？（1：はい、2：いいえ）：");
            scanf("%d", &tmp);
        }
    } while (tmp == 1);

    return 0;

}