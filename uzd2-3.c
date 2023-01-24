#include <stdio.h>

int main(){
    int skaicius;
    scanf("%d", &skaicius);
    printf("%s\n", skaicius%2==0 ? "lyginis" : "nelyginis");
}