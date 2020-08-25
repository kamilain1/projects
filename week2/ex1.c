#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("Size of int:  %u\n", sizeof(a));
    printf("Value of int:  %u\n", a);
    printf("Size of float:  %u\n", sizeof(b));
    printf("Value of float:  %d\n", a);
    printf("Size of double:  %u\n", sizeof(c));
    printf("Value of double:  %d\n", a);
    return 0;
}
