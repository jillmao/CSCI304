#include <stdio.h>

int main(){
    int count, reset;
    char c;
    
    printf("Input: ");
    
    count, reset = 0;
    c = getchar();
    if (c != ' ') {
        reset = 1;
        }
        
    while (c != '\n'){
        if (reset == 1){
            count++;
        };
        c = getchar();
        if (c != ' ') {
            reset = reset + 1;
        }
        else {
            reset = 0;
        };
    };
    printf("%d\n", count);
    return 0;
};
