#include <stdio.h>
#include <time.h>
#define NUM 5

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
    int n, answer[NUM], input[NUM];
    printf("n：");
    scanf("%d", &n);

    srand((unsigned)time(NULL));
    random(n, answer);
    
    printf("answer = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);   
    }
    putchar('\n');

    inputer(n, input);

    printf("Blow数 = %d\n", blower(answer, input, n));

    return 0;

}