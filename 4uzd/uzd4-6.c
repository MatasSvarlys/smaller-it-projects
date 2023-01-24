#include <stdio.h>
int skaitmenuSkaiciusFunc(int skaicius){
    int count = 0;
    while (skaicius){
        skaicius /= 10;
        ++count;
    }
    return count;
}

int main(){
    int flagBreak = 0, maxSkaitmenys = -1;
    while(!flagBreak){
        int tempInput, skaitmenuSkaicius;
        printf("iveskite neteigiama skaiciu jei norite baigti: ");
        scanf("%d", &tempInput);

        if(tempInput <= 0){
            flagBreak = 1;
            break;
        }
        skaitmenuSkaicius = skaitmenuSkaiciusFunc(tempInput);

        if(skaitmenuSkaicius > maxSkaitmenys)
            maxSkaitmenys = skaitmenuSkaicius;

    }
    printf("daugiausia skaitmenu: %d", maxSkaitmenys);
}