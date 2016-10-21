#include <stdio.h>

int main(int argc, char *argv[]){
    char buf[1000], rest[800];
    int integers;

    FILE *file1 = fopen(argv[1], "r+");
    if (!file1){
        return 1;
    }

    FILE *file2 = fopen(argv[2], "w");
    if (!file2){
        return 1;
    }

    while (fgets(buf, 1000, file1)!=NULL){
        sscanf(buf, "%d %[^\n]s", &integers, rest);
        fprintf(file2, "%d %s\n", integers + 1, rest);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}
