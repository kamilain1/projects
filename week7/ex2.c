#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Write the size of the array\n");
    int n;
    scanf("%d", &n);
    int *array = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        array[i] = i;
        printf("%i ", array[i]);
    }
    free(array);
    return 0;
}
