#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
// defining main with arguments

int isDirectoryExists(const char *path);

int main(int argc, char* argv[])
{
    char buffer[50];
    FILE *fp;
    FILE *fp2;
    if (argc > 1) {
        if (isDirectoryExists(argv[argc-1]) == 0) {
            if (argc == 2) {
                    printf("specify files first");
                    return 1;
            }
            else {
                for (int i = 1; i < argc-1; i++) {
                    if (access(argv[i], F_OK) == 0) {
                        fp = fopen(argv[i], "r");
                        char dirn[strlen(argv[argc-1])+1];
                        strcpy(dirn, argv[argc-1]);
                        fp2 = fopen(strcat(dirn,argv[i]), "w");
                        while (fgets(buffer,50,fp) != NULL) {
                            fputs(buffer, fp2);
                        };
                        remove(argv[i]);
                        fclose(fp);
                        fclose(fp2);
                    }
                    else if (access(argv[i], F_OK) != 0) {
                        printf("%s: incorrect file or directory",argv[i]);
                        return 1;
                    }
                }
            }
        }
        else {
                printf("directory not found or not given");
                return 1;
        }
    }
    else {
        printf("not enough arguments");
        return 1;
    }
    return 0;
}

int isDirectoryExists(const char *path) {
    DIR* dir = opendir(path);
    if (dir) {
        closedir(dir);
        return 0;
    } else if (ENOENT == errno) {
        return 1;
    } else {
        return 2;
    }

    return 0;
}