#include <stdio.h>

int main(){
    FILE *fp;
    int a, b, c;

    fp = fopen("test.txt", "r");
    if(fp == NULL)
        printf("awooga");
    fscanf(fp, "%d %d %d", &a, &b, &c);
    a = ftell(fp);
    printf("%d/n", a);
}