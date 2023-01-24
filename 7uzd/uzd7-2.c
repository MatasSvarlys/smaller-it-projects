#include <stdio.h>

int getFactorial(int number){
    if (number < 0)
        return 0;
    else if (number > 0)
        return number * getFactorial(number - 1);
    else 
        return 1;


}

int main(){
    int number = 0;

    printf("%d", getFactorial(number));
}