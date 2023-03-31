#include <stdio.h>
#include <limits.h>

/*int arr[] = {3,4,-3,2,0,-4,-9,7,-8,-6,3,4,INT_MIN};*/ 
int arr[] = {-2,9,0,-1,-2,-3,4,5,9,-6,INT_MIN};

int *findNeg(int *ptr) 
{
    while (1) {
        if (*ptr < 0) {
            return ptr;
        }
        ptr++;
    }  
}

int main(void)
{
    int *p, *next;
    int i = 0;
    p = arr;  
    while (1) {
        next = findNeg(p); 
        if (*next == INT_MIN) {
            break;
        }
        printf("%d番目に負の数 %dがあります\n", (int)(next - arr), *next);
        p = next + 1;

    }
    return 0;
}