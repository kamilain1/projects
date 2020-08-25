#include <stdio.h>

int main(int argc, char* argv[]) {
    int n;
    sscanf(argv[1],"%d", &n);
    int j = 1;

    int height = n;
    int width = 2 * n - 1;
    for (int i = 0; i < height; i++) {
        for (int space = 0; space < width; space++) {
            printf(" ");
        }
        for (int curr = 0; curr < j; curr++) {
            printf("*");
        }
        j = j + 2;
        width--;
        printf("\n");
    }
    return 0;
}