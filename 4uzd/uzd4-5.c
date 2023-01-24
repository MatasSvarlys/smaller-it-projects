#include <stdio.h>
#include <limits.h>

int main(){
    int n;
    int suma = 0, minVal = INT_MAX, maxVal = INT_MIN;
    double vidurkis;

    printf("iveskite skaiciu n:");
    scanf("%d", &n);

    for (int i=0; i<n; ++i){
        int temp;
        printf("iveskite nari %d: ", i+1);
        scanf("%d", &temp);

        suma +=temp;

        if (temp < minVal)
            minVal = temp;
        
        if(temp > maxVal)
            maxVal = temp;
    }
    vidurkis = (double)suma/n;

    printf ("min: %d, max: %d, sum: %d, avr: %.2f", minVal, maxVal, suma, vidurkis);
}