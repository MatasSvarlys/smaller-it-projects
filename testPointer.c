#include <stdio.h>
void add(int *a){
    (*a)++;
}
void print(int* a){
    // ++*a;
    int temp = *a;
    printf("%d\n", temp);
}

int main(){
    int b = 10;
    printf("%d\n", b);
    add(&b);
    printf("%d\n", b);

    printf("%d\n", &b);
    print(&b);
    // printf("%d, %d", *a, &a);
}