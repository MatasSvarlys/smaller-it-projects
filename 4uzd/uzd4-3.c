#include <stdio.h>


int fibonachi(unsigned int demuo1, unsigned int demuo2, unsigned int likusiosIteracijos){
    
    if (likusiosIteracijos == 0)
        return demuo2;

    unsigned int demuo3;
    
    demuo3 = demuo1 + demuo2;
    --likusiosIteracijos;

    fibonachi(demuo2, demuo3,  likusiosIteracijos);

}


int main(){
    unsigned int a, b, c;
    printf("iveskite tris neneigimus sveikuosius skaicius:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    printf("%d", fibonachi(a, b, c));
}