#include <stdio.h>

void swap(int *a, int *b){
int temp;
temp = *a;
*a = *b;
*b = temp;
}

int main(int argc, char* argv[]) {
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    swap(&n, &m);
    printf("Swapped: %d ", n);
    printf("%d", m);

    return 0;
}



