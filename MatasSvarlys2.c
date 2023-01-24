#include <stdio.h>
#include <stdlib.h>

void *ptr1, *ptr2;

void imagine(){
    int *box;
    int *arr;

    box = malloc(6);
    arr = malloc(3*6);
    ptr1 = malloc(6);
    ptr2 = malloc(6);

    arr[0] = 4831;
    arr[1] = -568;
    (arr+2) = &box;
    box = (int*)arr;
    ptr1 = (int*)&box;
    ptr2 = &arr[2];
    return;
}

unsigned char hexToChar(int digit, char type){
    if(digit < 0 || digit > 15)
        return 0;
    if(digit < 10)
        return ('0' + digit);
    if(type > 0)
        return ('A' + digit - 10);
    return ('a' + digit - 10);
}

int *getPermutation(int size){
    int *arr;
    arr = calloc(size, sizeof(int));
    char where;

    if(!arr)
        return NULL;

    for(int i = 0; i < size; ++i){
        where = rand()%2;
        if(where)
            arr[i] = i + 1;
        else{
            for(int j = i; j < 0; --j)
                arr[j] = arr[j-1];
            arr[0] = i+1;
        }
    }
}

int fun1(int a, int b){
    if(a < b)
        return b;
    if(a > b)
        return a;
    return 0;
}

void fun2(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
    return;
}

void fun3(int **a){
    if(*a)
        free(*a);
    return;
}