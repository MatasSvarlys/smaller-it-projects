#include <stdio.h>
#include <limits.h>

int main(){
    int flagRepeatInput = 1;
    long long inputNumber;
    FILE * outputFile;

    printf("iveskite teigiama skaiciu ir bus isvestas jo faktorialas:\n");

    while(flagRepeatInput){
        if (scanf("%12lld", &inputNumber) && (getchar() == '\n')){
            if (inputNumber < INT_MAX && inputNumber > 0){
                flagRepeatInput = 0;
            } else{
                printf("skaicius netelpa i rezius!\n");
            }
        } else{
            printf("ivedete ne skaiciu!\n");
            scanf("%*[^\n]");
        }
        if (flagRepeatInput)
            printf("kartokite ivedima:\n");
    }

    int result = 1;

    for (int i = inputNumber; i > 0; --i)
        result *= i;
    
    printf("gautas faktorialas: %d", result);

    outputFile = fopen("out.txt", "w"); 
    fprintf (outputFile, "gautas faktorialas: %d", result);
    fclose(outputFile);
}