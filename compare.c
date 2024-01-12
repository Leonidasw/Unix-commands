#include <stdio.h>
#include <unistd.h>
#include <string.h>
 
// defining main with arguments
int main(int argc, char* argv[])
{
    char buffer[50];
    char buffer2[50];
    FILE *fp;
    FILE *fp2;
    argc -= 1;
    if (argc <= 2) {
        if (access(argv[1], F_OK) == 0 && access(argv[2], F_OK) == 0 ) {
            printf("You have entered %d arguments:\n", argc);
            fp = fopen(argv[1], "r");
            fp2 = fopen(argv[2], "r");
            while (fgets(buffer,50,fp) != NULL && fgets(buffer2,50,fp2) != NULL){
                continue;
            };
            if (strcmp(buffer,buffer2) == 0){
                    printf("%s\n", "same");
                }
            else {
                printf("different");
            };

        } 
        else {
            if (access(argv[1], F_OK) == 1) {
                printf("%s is an inexistant file", argv[1]);
                return 1;
            }
            else {
                printf("%s is an inexistant file", argv[2]);
                return 1;
            }
        }


    }
    else {
        printf("too many arguments");
        return 1;
    }
    return 0;
}
