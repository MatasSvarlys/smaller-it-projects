#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int arr[1000];
    int a, b, c;
    int difference;
    
    printf("iveskite skaicius a ir b kurie bus reziai ir c kiek elementu sugeneruoti (0<c<1000):\n");
    scanf("%d %d %d", &a, &b, &c);

    difference = abs(a) + abs(b);
    srand(time(NULL));

    for (int i=0; i<c; ++i)
        arr[i] = a + rand()%(difference + 1);


    for (int i=0; i<c; ++i)
        printf("%d: %d\n", i+1, arr[i]);
}