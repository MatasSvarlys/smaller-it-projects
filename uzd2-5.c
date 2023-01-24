#include <stdio.h>
#include <math.h>

int main(){
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("a) %.2f\nb) %.2f", x+4*y+pow(z, 3), (x+sqrt(y))*(pow(z, 4)-fabs(z)+46.3f));
}