#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define BUFFER_SIZE 256

char *trimString(char *arr, int howMuch){
    char *temp;
    temp = malloc(strlen(arr));
    strcpy(temp, arr + howMuch);
    realloc(arr, strlen(arr) - howMuch);
    strcpy(arr, temp);
    free(temp);
    return arr;
}

unsigned char endsWithTxt(char *arr){
    arr = strrchr(arr, '.');

    if(arr != NULL)
        return(!strcmp(arr, ".txt"));

    return 0;
}

void getFileName(char **fileName){

    char tempString[255];
    unsigned char loopAgain = 0;
    
    do{
        if (scanf("%s.txt", &tempString) == 1 && (getchar() == '\n')){
            if (!endsWithTxt(tempString)){
                printf("pavadinimas turi baigtis .txt, iveskite dar karta:\n");
                loopAgain = 1;   
                continue; 
            }
            printf("failo pavadinimas nuskaitytas\n");
            *fileName = malloc(strlen(tempString) * sizeof(char));
            strcpy(*fileName, tempString);
            loopAgain = 0;

        } else {
            printf("pavadinimas netinkamas, iveskite dar karta:\n");
            loopAgain = 1;
        }
    
    } while (loopAgain);
}

int main(){
    char *buffer;
    char *readFileName;
    char *writeFileName;
    FILE *readFile;
    FILE *writeFile;

//---------------------get file names-----------------
    printf("iveskite nuskaitymo failo pavadinima:\n");
    do{
        getFileName(&readFileName);
        readFile = fopen(readFileName, "r");
        if(readFile == NULL)
            printf("failas nerastas, iveskite kita pavadinima:\n");
    } while (readFile == NULL);

    printf("iveskite isvedimo failo pavadinima:\n");
    getFileName(&writeFileName);
    writeFile = fopen(writeFileName, "w");

    if(writeFile == NULL){
        printf("failo sukurti nepavyko");
        return 0;
    }

//---------------------main functioning-----------------------
    unsigned char stillLeft = 1;
    do{
        buffer = malloc(BUFFER_SIZE * sizeof(char)); 

        if(!fgets(buffer, BUFFER_SIZE, readFile)){
            stillLeft = 0;
            continue;
        }

        if(strchr(buffer, '\n') == NULL){
            fscanf(readFile, "%*[^\n]");
            fscanf(readFile, "%*c");
        }
        buffer = trimString(buffer, strspn(buffer, " "));
        // printf("[debug] buffer po realloc: %s\n", buffer);


        char *word;
        unsigned char keepGoing = 1;
        word = malloc(sizeof(buffer));

        do{
            if(sscanf(buffer, "%s", word) == EOF){
                keepGoing = 0;
                continue;
            }
            // printf("[debug] read word: %s\n", word);

            if(word[1] == word[strlen(word)-3])
                fprintf(writeFile, "%s ", word);

            buffer = trimString(buffer, strlen(word));
            // printf("[debug] word lengh how much it was pushed %d\n", strlen(word));
            // printf("[debug] the buffer after pushing it further: %s\n", buffer);
            // printf("[debug] spaces after the word: %d\n", strspn(buffer, " "));
            buffer = trimString(buffer, strspn(buffer, " "));
        }
        while (keepGoing);

        // printf("[debug] new line\n");
        fprintf(writeFile, "\n");
        free(buffer);

    }
    while(stillLeft);

}