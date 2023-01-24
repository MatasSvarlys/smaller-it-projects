#include <stdio.h>

int main(){
    int skaic1, skaic2, skaic3;
    scanf("%d %d %d", &skaic1, &skaic2, &skaic3);

    printf("max: %d\n", skaic1>=skaic2 ? (skaic1>=skaic3 ? skaic1 : skaic3) : (skaic2>=skaic3 ? skaic2 : skaic3));
}