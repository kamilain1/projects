#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(){
    int myFile = open("ex1.txt", O_RDWR);
    struct stat myStat = {};
    off_t size = myStat.st_size;
    char *addr;
    addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);
    strncpy(addr, "This is a nice day", size);

    return 0;
}