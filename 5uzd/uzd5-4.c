#include <stdio.h>

int main(){
    int arr[10000]; //nezinau ar galima naudoti vectors for infinite storing tai for now limited array storage
    int arrPirminiai[10000];
    int numInArr = 0;
    int numInArrPirminiai = 0;

    printf("iveskite skaicius (neteigiamas baigs ivedima):\n");
    do{
        printf("%d: ", numInArr+1);
        scanf("%d", &arr[numInArr]);
        ++numInArr;
    }
    while (arr[numInArr - 1] > 0);

    arr[numInArr-1] = 1;
    printf("ivesti pirminiai skaiciai:\n");

    for(int i = 0; i < numInArr; ++i){
        int flagArPirminis = 1;

        if(arr[i] == 1)
            continue;

        for(int j = 2; j < arr[i]; ++j){

            if(arr[i] % j == 0){
                // printf("got here lol\n");
                flagArPirminis = 0;
                break;   
            }
        }
        
        if(flagArPirminis){
            int flagJauYra = 0;
            for(int j = 0; j < numInArrPirminiai; ++j){
                if(arrPirminiai[j] == arr[i]){
                    flagJauYra = 1;
                    break;
                }
            }
            
            if(!flagJauYra){
                arrPirminiai[numInArrPirminiai] = arr[i];
                printf("%d ", arrPirminiai[numInArrPirminiai]);
                ++numInArrPirminiai;
            }
        }
    }

}