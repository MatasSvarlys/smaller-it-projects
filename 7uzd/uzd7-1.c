#include <stdio.h>


int isInRange(int number, int low, int high){
    if(number > low && number < high)
        return 1;
    
    return 0;
}


int main(){
    int number = -5, low = 1, high = 10;
    printf("%d", isInRange(number, low, high));
}

