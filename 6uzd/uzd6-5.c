#include <stdio.h>
#include <string.h>

#define strSize 100

int main(){
    char workingString[strSize];

    printf("iveskite korektiska elektronini pasta:\n");

    gets(workingString);

    int isValidEmail = 1;
    char *afterAt;

    if(workingString[0] != '@'){
        char *afterDot;

        afterAt = strchr(workingString, '@');

        if(strchr(workingString, '@') == NULL)
            isValidEmail = 0;

        if(strchr(afterAt + 1, '@') != NULL)
            isValidEmail = 0;

        afterDot = strchr(afterAt + 2, '.');

        if(strchr(afterAt, '.') == NULL || *(afterDot + 1) == '\0')
            isValidEmail = 0;
        

    } else
        isValidEmail = 0;

    FILE *outputFile;
    outputFile = fopen("emails.txt", "a"); 


    if(isValidEmail){
        fputs(afterAt, outputFile);
        fprintf(outputFile, "\n");
        printf("domenas %s ikeltas i faila", afterAt);
    }else
        printf("ivestas email netinka");

}