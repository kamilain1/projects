#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    DIR *dirp = opendir("C:\\Users\\kamil\\Documents\\MobaXterm\\home\\tmp\\");
    FILE *file = fopen("C:\\Users\\kamil\\Documents\\MobaXterm\\home\\week10\\ex4.txt", "w");
    struct dirent *dp;
    char path[1024];
    struct stat statbuf;

    while ((dp = readdir(dirp)) != NULL) {
        snprintf(path, sizeof(path), "%s%s", "C:\\Users\\kamil\\Documents\\MobaXterm\\home\\tmp\\", dp->d_name);
        stat(path, &statbuf);
        if (statbuf.st_nlink >= 2) fprintf(file, "%s\n", path);
    }
    fclose(file);
    return 0;
}