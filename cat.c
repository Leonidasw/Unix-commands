#include <stdio.h>
#include <unistd.h>
 
// defining main with arguments
int main(int argc, char* argv[])
{
    char buffer[50];
    FILE *fp;
    if (argc >= 1) {
        for (int i = 1; i < argc; i++) {
            if (access(argv[i], F_OK) == 0) {
                fp = fopen(argv[i], "r");
                while (fgets(buffer,50,fp) != NULL){
                    printf("%s", buffer);
                };
                printf("\n");
            } 
            else {
                if (access(argv[i], F_OK) != 0) {
                    printf("%s is an inexistant file", argv[i]);
                    return 1;
                }
            }
        }
    }
    else {
        printf("not enough arguments");
        return 1;
    };
    return 0;
}
