#include <stdio.h>

int main(){
    int count, num;
    int total;
    char c;
    
    printf("Input: ");
    
    count, num, total = 0;
    c = getchar();
    while (c != '\n'){
        if (c == ' '){
            total = total + num;
            num = 0;
        }
        else {
            int k = c-48;
            num = num * 10 + k;
        };
        c = getchar();
    };
    total = total + num;
    printf("%d\n", total);
    return 0;
};
