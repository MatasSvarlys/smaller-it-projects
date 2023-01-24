#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

void generateArray(int data[], int size, int low, int high){
    int difference;
    difference = abs(low) + abs(high);
    
    srand(time(NULL));

    for (int i = 0; i < size; ++i)
        data[i] = low + rand() % (difference + 1);
    
}
int main(){
    int wantedArr[SIZE] = {};
    generateArray(wantedArr, SIZE, -15, 60);

    // for(int i = 0; i < SIZE; ++i)
    //     printf("%d\n", wantedArr[i]);
}