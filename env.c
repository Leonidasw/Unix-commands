#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
int main(int argc, char **argv) {
    if (argc == 2) {
        if (strcmp(argv[1], "-0") == 0) {
            for (int i=0; environ[i]!=NULL; i++) {
                printf("%s",environ[i]);
            }
        } else {
            printf("Unknown argument: %s\n",argv[1]);
            return -1;
        }
    }
    else if(argc == 1){
        for (int i=0; environ[i]!=NULL; i++) {
            printf("%s\n",environ[i]);
        }
    }
    else {
        return -1;
    }
    return 0;
}