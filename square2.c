#include <stdio.h>

int main(){
    int num;
    char c;
    
    printf("Input: ");
    num = 0;
    while (c != '\n') 
    {
        c = getchar();
        int k = c - 48;
        if (k != -38){
            num = num * 10 + k;};
    }
    printf("%d\n", num * num);
    return 0;
};
