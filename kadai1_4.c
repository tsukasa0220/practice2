#include <stdio.h>

int main(void)
{
    int height, weight; 
    double bmi, weightStandard, heightM;
    printf("身長[cm]:");
    scanf("%d", &height);
    printf("体重[kg]:");
    scanf("%d",&weight);

    heightM = height * 0.01;

    bmi = weight / heightM / heightM;

    if (bmi >= 25) {

        weightStandard = 22 * heightM * heightM;
        printf("BMIは%.1f, 肥満です\n", bmi);
        printf("身長%dcmの標準体重は%.1fkgです\n", height, weightStandard);

    }else {
        printf("BMIは%.1f、肥満ではありません\n", bmi);
    }

    return 0;
}