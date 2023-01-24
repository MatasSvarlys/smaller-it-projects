#include <stdio.h>


int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
    int flagRepeat = 1, number;
    do{
        printf("%s\n", menuTitle);

        for (int i = 0; i < menuSize; ++i)
            printf("%d: %s\n", i+1, menuOptions[i]);
        
        printf("%s\n", inputMsg);
        if (scanf("%d", &number) == 1 && getchar() == '\n'){
            if(number > 0 && number < menuSize+1)
                flagRepeat = 0;
            else
                printf("tokio pasirinkimo nera sarase\n");
        } else{
            printf("iveskite skaiciu atitinkanti jusu pasirinkima\n");
            scanf("%*[^\n]");
        }
        printf("\n");
    }while(flagRepeat);

    printf("jus pasirinkote: %s", menuOptions[number-1]);

}


int main (){
    char menuTitle[] = "Galimi pasirinkimai:";
    char inputMsg[] = "iveskite kuri punkta noretumete isvesti:";
    char* menuOptions[100] = {"pauksciai", "zmones", "kiti gyvunai"};
    int menuSize = sizeof(menuOptions)/(100*sizeof(char))-1;

    showMenu(menuTitle, menuOptions, menuSize, inputMsg);

}