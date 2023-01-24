#include <stdio.h>
#include <string.h>

int maxInputLength(int arg, char **argv){
    int max = -1;

    for (int i = 1; i < arg; ++i){
        int j = 0;

        while (argv[i][j] != '\0')
            ++j;
        
        if(j > max)
            max = j * sizeof(char);

    }

    return max;
}
int main(int argc, char *argv[]){
    printf("%d", maxInputLength(argc, argv));
}