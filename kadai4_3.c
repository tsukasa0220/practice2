#include <stdio.h>
#include <time.h>

int main(void)
{
    int line1, line2, direction, arr[9][9];
    srand((unsigned)time(NULL));
    printf(" | 1| 2| 3| 4| 5| 6| 7| 8| 9|\n");
    printf("-+--+--+--+--+--+--+--+--+--+\n");
    for (int i = 0; i < 9; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < 9; j++) {
            arr[i][j] = rand() % 10;
            printf("%2d|", arr[i][j]);
        }
        putchar('\n');
    }
    printf("行：");
    scanf("%d", &line1);
    printf("列：");
    scanf("%d", &line2);
    printf("方向[1:右, 2:下]：");
    scanf("%d", &direction);
    if (direction == 1 && line2 <= 6) {
        printf("暗証番号は%d%d%d%dです\n", arr[line1 - 1][line2 - 1], arr[line1 - 1][line2], arr[line1 - 1][line2 + 1], arr[line1 - 1][line2 + 2]);
    } else if (direction == 2 && line1 <= 6) {
        printf("暗証番号は%d%d%d%dです\n", arr[line1 - 1][line2 - 1], arr[line1][line2 - 1], arr[line1 + 1][line2 - 1], arr[line1 + 2][line2 - 1]);
    } else {
        puts("暗証番号は生成できません");
    }
    
    return 0;

}