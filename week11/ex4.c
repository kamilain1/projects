#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    int myFile = open("ex1.txt", O_RDWR);
    struct stat myStat = {};
    stat("ex1.txt", &myStat);
    off_t size = myStat.st_size;
    char *addr;
    addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, myFile, 0);


    int myFile1 = open("ex1.memcpy.txt", O_RDWR);
    struct stat myStat1 = {};
    stat("ex1.memcpy.txt", &myStat1);
    off_t size1 = myStat1.st_size;
    char *addr1;
    addr1 = mmap(NULL, size1, PROT_READ | PROT_WRITE, MAP_SHARED, myFile1, 0);

    memcpy(addr1, addr, size1);
    return 0;
}