#include <stdio.h>
#include <sys/types.h>
#include <process.h>

void main() {
    if (fork() == 0) {
        pid_t n = getpid();
        printf("Hello from child [PID - %d]\n", n);
    } else {
        pid_t n = getpid();
        printf("Hello from parent [PID - %d]\n", n);
    }
}