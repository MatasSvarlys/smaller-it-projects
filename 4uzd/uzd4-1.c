#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    printf("iveskite kvadratines lygties koficientus:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    int diskriminantas, diskriminantoZenklas;
    double ats;
    diskriminantas = pow(b, 2) - 4*a*c;
    
    if(diskriminantas > 0)
        diskriminantoZenklas = 1;
    else if (diskriminantas == 0)
        diskriminantoZenklas = 0;

    printf("%d\n", diskriminantas);
    switch (diskriminantoZenklas){
    case 1:
        ats = (-b + sqrt(diskriminantas)) / (2 * a);
        printf("%.2f, ", ats);
    case 0:
        ats = (-b - sqrt(diskriminantas)) / (2 * a);
        printf("%.2f", ats);
        break;
    default:
        printf("realiuju skaiciu aibeje sprendiniu nera");
        break;
    }

    // if (diskriminantas  0){
    //     ats = (-b + sqrt(diskriminantas)) / (2 * a);
    //     printf("%d, ", ats);
        
    // } else if (diskriminantas == 0){

    // } else{
    //     printf("realiuju skaiciu aibeje sprendiniu nera");
    // }
}