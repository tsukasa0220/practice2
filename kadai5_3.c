﻿#include <stdio.h>
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

    printf("Hit数 = %d\n", hitter(answer, input, n));

    return 0;

}