#include <stdio.h>

int main() {
    FILE *file1 = fopen("/dev/random", "r");
    FILE *file2 = fopen("./ex1.txt", "w");
    char buffer[21];
    fgets(buffer, 21, file1);
    fprintf(file2, "%s", buffer);
    fclose(file1);
    fclose(file2);
    return 0;
}