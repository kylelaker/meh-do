#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Insufficient arguments provided\n");
        return 1;
    }
    if (execvp(argv[1], argv+1) < 0) {
        if (execv(argv[1], argv+1) < 0) {
            fprintf(stderr, "Unable to run %s\n", argv[1]);
            return 2;
        }
    }
}

