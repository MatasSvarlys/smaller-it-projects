#include <stdio.h>

int getPositiveNumber(char *msg){
    int flagRepeat = 1, number;
    do{ 
        printf("%s", msg);
        if (scanf("%d", &number) == 1 && getchar() == '\n'){
            if(number > 0)
                flagRepeat = 0;
        } else{
            scanf("%*[^\n]");
        }


    }while(flagRepeat);
    return number;
}

int main(){
    char message[] = "iveskite teigiama skaiciu:\n";
    printf("%d", getPositiveNumber(message));
}