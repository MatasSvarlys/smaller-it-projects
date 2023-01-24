#include <stdio.h>

int main(){
    int s, n;


    printf("iveskite skaicius s ir n:\n");

    scanf("%d%d", &s, &n);

    int arr[n];

    printf("dabar %d teigiamu(-s) skaiciu(-s):\n", n);
    for(int i=0; i < n; ++i){
        printf("%d: ", i+1);

        scanf("%d", &arr[i]);

        if (arr[i] < 1){
            printf("ivedete neteigiama skaiciu!!\n");
            --i;
        }
    }

    printf("poros kurias sudauginus gauname %d:\n", s);

    for(int i=0; i < n-1; ++i)
        for(int j=i+1; j < n; ++j)
            if(arr[i] * arr[j] == s)
                printf("(%d, %d) ", arr[i], arr[j]);

}