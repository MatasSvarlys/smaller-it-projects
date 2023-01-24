#include <stdio.h>


int dow(int m, int d, int y){
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + "-bed=pen+mad."[m] + d)%7; //is interneto paimta formule tiesa pasakius nesiruosiu jos aiskintis dabar
}


int main(){
    int year, month, day;
    int flagContinue;
    FILE *weekNames;

    printf("iveskite dara yyyy-mm-dd formatu:\n");
    
    do{
        if(scanf("%4d-%2d-%2d", &year, &month, &day) == 3 && getchar() == '\n'){
            if(month <= 12 && day <=31 && year > 0 && month > 0 && day > 0){
                flagContinue = 0;
                printf("ivesta teisingai\n");
            }
        }

        if(flagContinue){
            printf("iveskite teisinga data!\n");
            scanf("%*[^\n]");
        }

    } while (flagContinue);

    weekNames = fopen("week.txt", "r");


    int dayNum;
    char nameOfTheDay[100];
    dayNum = dow(month, day, year);

    for(int i = 0; i <= dayNum; ++i)
        fgets(nameOfTheDay, 100, weekNames);
    
    printf("savaites diena ta diena: %s", nameOfTheDay);
}