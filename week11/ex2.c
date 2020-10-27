#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    char *buf;
    setvbuf(stdout, buf, _IOLBF, BUFSIZ);
    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);
}