#include <stdio.h>
#define NUM 5

void input(int n, int arr[]) 
{
    int tmp;
    for (int i = 0; i < n; i++) {
        printf("n%d：", i + 1);
        scanf("%d", &tmp);
        arr[i] = tmp;
    }
    return;
}

int main(void)
{
    int n, arr[NUM];
    printf("n：");
    scanf("%d", &n);

    input(n, arr);
    
    printf("result：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);   
    }
    putchar('\n');

    return 0;

}