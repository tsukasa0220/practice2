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

int main(void)
{
    int n, arr[NUM];
    printf("n：");
    scanf("%d", &n);
    srand((unsigned)time(NULL));
    random(n, arr);
    
    printf("result：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);   
    }
    putchar('\n');

    return 0;

}