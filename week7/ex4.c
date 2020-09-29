#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* Realloc(int *array, int size){
    int *a2 = malloc(sizeof(int *) * size);
    if (array == NULL) array = malloc(sizeof(int *) * size);
    else if (size == 0) free(array);
    else{
        a2 = memcpy(a2,array,size);
    }
    return a2;
}

int main() {
    printf("Enter original array size:");
    int n1 = 0;
    scanf("%d", &n1);

    int *a1 = malloc(sizeof(int *) * n1);
    int i;
    for (i = 0; i < n1; i++) {
        a1[i] = 100;

        printf("%d ", a1[i]);
    }

    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    a1 = Realloc(a1, n2);

    if (n2 > n1)
        for (i = n1; i < n2; i++) {
            a1[i] = 0;
        }

    for (i = 0; i < n2; i++) {
        printf("%d ", a1[i]);
    }

    printf("\n");
    return 0;
}
