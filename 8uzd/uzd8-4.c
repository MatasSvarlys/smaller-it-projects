#include <stdio.h>
#include <stdlib.h>

int split(int* arr, int size, int sizeA, int** newArrA, int** newArrB){
    if (arr == NULL || *newArrA != NULL || *newArrB != NULL)
        return -1;

    if (size < 0)
        return -1;

    if (sizeA > size)
        return -1;

    *newArrA = malloc(sizeA * sizeof(int));
    *newArrB = malloc((size - sizeA) * sizeof(int));

    for(int i = 0; i < sizeA; ++i)
        (*newArrA)[i] = arr[i];
    
    for(int i = 0; i < size - sizeA; ++i)
        (*newArrB)[i] = arr[i + sizeA];

    return 0;
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int* arrA = NULL;
    int* arrB = NULL;
    if(split(arr, 5, 2, &arrA, &arrB) == 0){
        for (int i = 0; i < 2; ++i)
            printf("%d ", arrA[i]);

        printf("\n");

        for (int i = 0; i < 3; ++i)
            printf("%d ", arrB[i]);
    } else
        printf("wrong input");
}