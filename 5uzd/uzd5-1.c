#include <stdio.h>

#define CAPACITY 10

int main (){
    int x[CAPACITY] = {};

    for (int i=0; i<CAPACITY; ++i)
        printf("%d ", x[i]);

    printf("\n");

    x[0] = 1;
    x[3] = 2;
    x[9] = 3;

    for(int i=2; i<CAPACITY; ++i)
        x[i] = x[i+1];
    
    for(int i=CAPACITY; i>6; --i)
        x[i] = x[i-1];
    
    x[6] = 4;

    for (int i=0; i<CAPACITY; ++i)
        printf("%d ", x[i]);

    printf("\n");


    int a, b;

    int flagContinue;

    do{
        printf("iveskite 2 sveikuosius skaicius x ir y kur ir koki skaiciu norite iterpti (1<x<%d):\n", CAPACITY);
        scanf("%d %d", &a, &b);

        if (a>0 && a<10){
            x[a] = b;
            flagContinue = 1;

        }
        else{
            printf("x netelpa i rezius\n");
            flagContinue = 0;
        }
    }
    while(!flagContinue)
        ;

    

    do{
        printf("iveskite skaiciu x kuri masyvo elementa norite istrinti (1<x<%d):\n", CAPACITY);
        scanf("%d", &a);

        if (a>0 && a<10){
            for(int i=a-1; i<CAPACITY; ++i)
                x[i] = x[i+1];
            flagContinue = 1;
        }
        else{
            printf("x netelpa i rezius\n");
            flagContinue = 0;
        }
    }
    while(!flagContinue)
        ;

    


    do{
        printf("iveskite 2 sveikuosius skaicius x ir y kur ir koki skaiciu norite iterpti(1<x<%d):\n", CAPACITY);
        scanf("%d %d", &a, &b);

        if (a>0 && a<10){
            for(int i=CAPACITY; i>a-1; --i)
                x[i] = x[i-1];
    
            x[a-1] = b;
            flagContinue = 1;
        }
        else{
            printf("x netelpa i rezius\n");
            flagContinue = 0;
        }
    }
    while(!flagContinue)
        ;




    for (int i=0; i<CAPACITY; ++i)
        printf("%d ", x[i]);
}