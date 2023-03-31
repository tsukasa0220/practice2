#include <stdio.h>

int main(void)
{
    int vc[10] = {60, 36, 42, 51, 83, 81, 29, 45, 77, 62};
    for (int i = 0; i < 10; i++) {
        printf("%d番 %d ", i + 1, vc[i]);
        
        if (vc[i] >= 60) {
            puts("合格");
        } else {
            puts("不合格");
        }
    }

    return 0;
}