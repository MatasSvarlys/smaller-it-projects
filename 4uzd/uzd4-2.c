#include <stdio.h>

int main(){
    int a, b, c;
    printf("iveskite tris sveikuosius skaicius:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    for (int i = a+1; i<=b; ++i)
        if(i % c == 1)
            printf("%d ", i);
}