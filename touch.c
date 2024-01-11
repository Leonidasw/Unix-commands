#include <stdio.h>
#include <unistd.h>
 
// defining main with arguments
int main(int argc, char* argv[])
{
    FILE *fp;
    if (argc >= 1) {
        for (int i = 1; i < argc; i++) {
            if (access(argv[i], F_OK) == 0) {
               return 1;
            } 
            else {
                if (access(argv[i], F_OK) != 0) {
                   fp = fopen(argv[i], "w");
                }
            }
        }
    }
    else {
        printf("not enough arguments");
    };
    return 0;
}