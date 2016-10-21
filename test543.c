 #include <stdio.h>

 int main (int argc, char *argv[]) {
 int i, j=0;
 printf("\ncommand line args count=%d\n", argc);

 /* First argument is executable name only */
 printf("executable name=%s\n", argv[0]);
 
 for (i=1; i< argc; i++) {
        printf("arg%d=%s\n", i, argv[i]);
    }

int square, k, num = 0;
 for (i = 1; i < argc; i++){
    char c = *(argv[i]);
    int count = 0;
    while (c != '\0')
    {
        int k = c - 48;
        num = num * 10 + k;
        count++;
        c=*(argv[i] + count);
    };
    square = num * num;
     printf("The square of arg%d=%d\n", i, square);
     num = 0;
}

 return 0;
 }
 
