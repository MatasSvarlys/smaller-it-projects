#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateArray(int data[], int size, int low, int high){
    int distanceBetweenNumbers;
    distanceBetweenNumbers = abs(high - low);
    
    srand(time(NULL));

    for (int i = 0; i < size; ++i)
        *(data + i) = rand() % (distanceBetweenNumbers + 1) + low;
    
}

int* createArray(int size, int low, int high){
    if (size < 0)
        return NULL;

    int* arr;
    arr = malloc(size * sizeof(int));

    generateArray(arr, size, low, high);

    return arr;
}

int main(){
    int* arr;
    arr = createArray(15, -5, 20);
    for(int i = 0; i < 15; ++i)
        printf("%d ", arr[i]);
}