#include <stdio.h>
#include <time.h>

int main(void)
{
    int line1, line2, arr[9][9];
    srand((unsigned)time(NULL));
    printf(" |   1|   2|   3|   4|   5|   6|   7|   8|   9|\n");
    printf("-+----+----+----+----+----+----+----+----+----+\n");
    for (int i = 0; i < 9; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < 9; j++) {
            arr[i][j] = rand() % 10000;
            printf("%04d|", arr[i][j]);
        }
        putchar('\n');
    }
    printf("行：");
    scanf("%d", &line1);
    printf("列：");
    scanf("%d", &line2);
    printf("暗証番号は%04dです", arr[line1 - 1][line2 - 1]);


    return 0;

}