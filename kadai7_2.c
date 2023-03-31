#include <stdio.h>

void rotate(int *p_n1, int *p_n2, int *p_n3)
{
    int tmp;
    tmp = *p_n1;
    *p_n1 = *p_n2;
    *p_n2 = *p_n3;
    *p_n3 = tmp;
}

int main(void) {
    int n1, n2, n3;
    puts("入力");
    
    printf("n1：");
    scanf("%d", &n1);
    printf("n2：");
    scanf("%d", &n2);
    printf("n3：");
    scanf("%d", &n3);

    rotate(&n1, &n2, &n3);

    puts("出力");
    printf("n1：%d\n", n1);
    printf("n2：%d\n", n2);
    printf("n3：%d\n", n3);

    return 0;
}