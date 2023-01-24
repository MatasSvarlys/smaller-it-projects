#include <stdio.h>

int main(){
    int num1, num2, num3;
    int flagKeepGoing = 1;
    FILE *outputFile;

    printf("iveskite 3 sveikuosius skaicius atskirtus kabliataskiais (ne tarpais):\n");

    while (flagKeepGoing){
        if(scanf("%d;%d;%d", &num1, &num2, &num3) == 3 && getchar() == '\n'){
            printf("ivesta korektiskai\n");
            flagKeepGoing = 0;
        } else{
            printf("ivedete neteisingai, bandykite dar karta:\n");
            scanf("%*[^\n]");
        }
    }
    

    printf ("iveskite failo pavadinima kuriame irasyti atsakyma (turi baigtis .txt)\n");

    flagKeepGoing = 1;
    char fileName[100];
    while (flagKeepGoing){

        if(scanf("%s", fileName)){
            for(int i = 0; i < 96; ++i)
                if(fileName[i] == '.' && fileName[i+1] == 't' && fileName[i+2] == 'x' && fileName[i+3] == 't')
                    flagKeepGoing = 0;
                 
        }

        if (flagKeepGoing)
            printf("ivestas pavadinimas netiko bandykite dar karta\n");
    }
    
    outputFile = fopen (fileName, "w");

    fprintf(outputFile, "%d", num1 > num2 ? (num1 < num3 ? num1 : (num2 > num3 ? num2 : num3)) : (num2 < num3 ? num2 : (num1 > num3 ? num1 : num3)));

    printf("isvedimas ivykdytas i faila %s", fileName);
}