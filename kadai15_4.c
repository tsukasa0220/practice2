#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char tmp[32], str1[100][32], str2[100][32];

    if (argc < 3) {
        printf("引数が不足しています"); exit(1);
    }

    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        printf("ファイル１が開けません"); exit(1);
    }
    fp2 = fopen(argv[2], "r");
    if (fp2 == NULL) {
        printf("ファイル２が開けません"); exit(1);
    }

    int line1 = 0;
    while (fgets(tmp, sizeof(tmp), fp1) != NULL) {
        sscanf(tmp, "%s", str1[line1]);
        line1++;
    }
    int line2 = 0;
    while (fgets(tmp, sizeof(tmp), fp2) != NULL) {
        sscanf(tmp, "%s", str2[line2]);
        line2++;
    }

    int min_line = line1;
    if (line1 > line2) {min_line = line2;} 

    int i = 0, all_equal = 1;
    while (i < min_line) {
        if (strcmp(str1[i], str2[i]) != 0) {
            printf("--%s\n%d：%s\n", argv[1], i + 1, str1[i]);
            printf("--%s\n%d：%s\n", argv[2], i + 1, str2[i]); 
            all_equal = 0;
        }
        i++;
    }

    while (i < line1) {
        printf("--%s\n%d：%s\n", argv[1], i + 1, str1[i]);
        all_equal = 0;
        i++;
    }
    while (i < line2) {
        printf("--%s\n%d：%s\n", argv[2], i + 1, str2[i]);
        all_equal = 0;
        i++;
    }

    if (all_equal == 1) {printf("等しいファイルである");}

    fclose(fp1);
    fclose(fp2);

    return 0;
}