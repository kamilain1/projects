#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int N, int array[]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (array[j] > array[j+1]){
            swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    int a[] = {54, 125, 5, 8, 4, 7, 98, 2, 1767, 9, 121, 4, 0};
    int N = sizeof(a)/ sizeof(a[0]);
    bubble_sort(N, a);
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}