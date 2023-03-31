#include <stdio.h>
#include <string.h>
#include <ctype.h>

void stringupper(char tmp[]);
void stringlower(char tmp[]);
void stringreverseANDprint(char tmp[]);

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char str[256];
    int flag_SorL = 0, flag_R = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "/R") == 0) {
            flag_R = 1;
        } else if (flag_SorL != -1 && strcmp(argv[i], "/L") == 0) {
            flag_SorL = 1;
        } else if (flag_SorL !=  1 && strcmp(argv[i], "/S") == 0) {
            flag_SorL = -1;
        } else if (fp == NULL) {
            fp = fopen(argv[i], "r");
        }   
    }
    if (fp == NULL) {printf("引数が不足"), exit(1);}

    while (fgets(str, sizeof(str), fp) != NULL) {
        if (flag_SorL == 1) {
            stringupper(str);
        } else if (flag_SorL == -1) {
            stringlower(str);
        }
        if (flag_R == 1) {
            stringreverseANDprint(str);
        } else {
            printf("%s", str);
        }
    }

    fclose(fp);

    return 0;
}

void stringupper(char tmp[])
{
    int i = 0;
    while (tmp[i] != '\0') {
        tmp[i] = toupper(tmp[i]);
        i++;
    }
}

void stringlower(char tmp[])
{
    int i = 0;
    while (tmp[i] != '\0') {
        tmp[i] = tolower(tmp[i]);
        i++;
    }
}

void stringreverseANDprint(char tmp[]) 
{
    int i = 0, len = strlen(tmp);
    char tmp2[256];
    while (tmp[i] != '\0') {
        tmp2[len - i - 1] = tmp[i]; 
        i++;
    }
    tmp2[len] = '\0'; 
    printf("%s", tmp2);
}