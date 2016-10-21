#include <stdio.h>
#include <math.h>
#include <stdarg.h>

int main(){
    int n;
    printf ("Please input a number: ");
    scanf ("%d", &n);
    int total = 0;
    int i;
        for (i = 1; i<n + 1; i++){
            int square = i * i;
            printf("The square of %d is %d\n", i, square);
            total+= square;      };
    printf("The sum of the squares is: %d\n", total);
    return 0;}
