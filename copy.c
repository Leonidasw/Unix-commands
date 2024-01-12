#include <stdio.h>
#include <unistd.h>
#include <string.h>
 
// defining main with arguments

const char *get_filename_ext(const char *filename) {
    if (strrchr(filename, '.') != NULL) {
        const char *dot = strrchr(filename, '.');
        if(!dot || dot == filename) return "";
        return dot + 1;
    }
    else {
        return 0;
    }
}

int main(int argc, char* argv[])
{

    char buffer[50];
    char buffer2[50];
    char result[100];
    FILE *fp;
    FILE *fp2;
    argc -= 1;
    if (argc == 2) {
        if (access(argv[1], F_OK) == 0 && access(argv[2], F_OK) == 0 ) {
            printf("You have entered %d arguments:\n", argc);
            fp = fopen(argv[1], "r");
            fp2 = fopen(argv[2], "w");
            while (fgets(buffer,50,fp) != NULL) {
                fputs(buffer, fp2);
            };
        } 
        else {
            if (access(argv[1], F_OK) == 1) {
                printf("%s is an inexistant file", argv[1]);
                return 1;
            }
            else {
                if (get_filename_ext(argv[1]) != 0) {
                    sprintf(result,"%s%s%s",argv[2],".",get_filename_ext(argv[1]));
                    fp2 = fopen(result, "w");
                    printf("You have entered %d arguments:\n", argc);
                    fp = fopen(argv[1], "r");
                    while (fgets(buffer,50,fp) != NULL) {
                        fputs(buffer, fp2);
                    };
                }
                else {
                    fp2 = fopen(argv[2], "w");
                    printf("You have entered %d arguments:\n", argc);
                    fp = fopen(argv[1], "r");
                    while (fgets(buffer,50,fp) != NULL) {
                        fputs(buffer, fp2);
                    };
                };
            };
        };

    }
    else if(argc > 2){
        printf("too many arguments");
        return 1;
    }
    else {
        printf("too few arguments");
        return 1;
    }
    
    return 0;
}
