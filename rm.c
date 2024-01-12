#include <stdio.h>
#include <unistd.h>
 
// defining main with arguments
int main(int argc, char* argv[])
{
    FILE *fp;
    if (argc >= 1) {
        for (int i = 1; i < argc; i++) {
            if (access(argv[i], F_OK) == 0) {
               remove(argv[i]);
            } 
            else {
                if (access(argv[i], F_OK) != 0) {
                   printf("%s: incorrect file or directory",argv[i]);
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