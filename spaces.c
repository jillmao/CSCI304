#include <stdio.h>

int main() {
    int spaces;
    char c;

    printf("Input: ");
    spaces = 0;
    c = getchar();
    while (c != '\n') 
    {
        if (c == ' ') {
            spaces++  ; };
        c = getchar();
    }
    printf("%d\n", spaces);
    return 0;
} 
