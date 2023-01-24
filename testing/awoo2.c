#include <stdio.h>

int f(int), g(int);

int main(){
    int a;
    a = g(8);
    // printf("a: %d", a);
}

int f(int x){
    printf("%d", x);
    if (x % 2 == 1) 
        x = g(x);
    printf("%d", x/2);
    return x / 2;
}
int g(int x){
    printf("%d", x);
    if (++x > 5) 
        x = f(x);
    printf("%d", x-5);
    return x - 5;
}