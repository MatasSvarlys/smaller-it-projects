#include <stdio.h>
#include <stdlib.h>

void s(int *a, int l){
    for(int i=0;i<l;++i){
        for(int j=0;j<l;j++){
            if(a[1+j] <= a[j]){
                char temp=a[j];
                a[j]=a[j+l];
                a[j+1]=temp;
            }
        }
    }
}

void n(int *b){
    scanf("%d",b);
}

void g(int *a, int *b){
    n(b);
    a = (int*)malloc(*b * sizeof(int));

    for(int i=0;i<*b;++i)
        a[i]=1+rand()%100;
}

int main(){
    int b;
    int *a;
    g(a, &b);
    s(a, b);

    for(int i=0; i < b; ++i){
        printf("%d",(*a)+i);
    }
}
    