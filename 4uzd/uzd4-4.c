#include <stdio.h>
#include <stdlib.h>

int rastiDbd(int a, int b){
    int dbd;

    while (abs(a) && abs(b))
        if (abs(a) > abs(b)) 
            a %= b; 
        else
            b %= a;
    // int dbd = ;
    return a+b;
}

int main(){
    int a, b, c;
    printf("iveskite tris sveikuosius skaicius:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    int dbd, mbk, temp;

    temp = rastiDbd(a, b);
    dbd = rastiDbd(temp, c);

    mbk = (a*b*c)/dbd;

    printf("DBD: %d, MBK: %d", dbd, mbk);
}