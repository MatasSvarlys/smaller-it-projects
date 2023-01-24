#include <stdio.h>
#include <math.h>

int BinaryToDecimal();
long long int DecimalToBinary();

int main(){
    int hexadecimal, decimal;
    long long int binary;

    scanf("%x", &hexadecimal);
    printf("0x%x in decimal is: %d\n", hexadecimal, hexadecimal);

    scanf("%d", &decimal);
    printf("%d in hexadecimal is: 0x%X\n", decimal, decimal);
    
    printf("11001011010101 from binary to decimal is: %d\n", BinaryToDecimal(11001011010101));
    printf("241 to binary is: 0b%lld\n", DecimalToBinary(241));
    
}

int BinaryToDecimal(long long int binary){
    int decimal=0, i=0, last_num;
    while (binary!=0){
        last_num = binary%10;
        binary /= 10;
        decimal += last_num * pow(2, i);
        i++;
    }
    return decimal;
}

long long int DecimalToBinary(int decimal){
    long long int binary=0;
    int divisible_by_2, i=1;

    while(decimal!=0){
        divisible_by_2 = decimal % 2;
        decimal /= 2;
        binary += divisible_by_2 * i;
        i *= 10;
    }
    return binary;
}