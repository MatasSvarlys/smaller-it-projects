#include <stdio.h>

#define minimum 10
#define maximum 100


int main(){
    FILE *inputFile;

    inputFile = fopen("in.txt", "r");

    printf("ivedimas faile in.txt, sveikasis skacius intervale (%d, %d), su ne daugiau 3 skaciu po kablelio\n", minimum, maximum);
    if(inputFile){
        int baseOfNumber;

        if(fscanf(inputFile, "%3d", &baseOfNumber) == 1 && (getc(inputFile) == ',' || getc(inputFile) == EOF)){
            if(baseOfNumber > minimum && baseOfNumber < maximum){

                if(getc(inputFile) == ','){
                    if (fscanf(inputFile, ",%3d", &baseOfNumber) == 1 && getchar() == EOF)
                        printf("skaicius ivestas teisingai");
                    else
                        printf("problema su trupmenine skaciaus dallimi");
                } else
                    printf("skaicius ivestas teisingai");
                
            } else
                printf("ivestas skaicius netelpa i rezius");

                
            
        } else{
            printf("patikrinkite faile ivesta skaiciu!");
        }

    } else
        printf("failas in.txt neegzistuoja\n");




}