#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    scanf("%[^\n]", str);
    printf("Reverse: %s", strrev(str));
    return 0;
}
