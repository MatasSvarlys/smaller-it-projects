#include <stdio.h>
#include <stdlib.h>

#define SIZE 10          // data size
#define FREQ_SIZE 1000   // upper bound for values

// input: 
//    user enters 10 non-negative integers
// output: 
//    report how many times each unique value occured,
//    display values and occurence times in ascending order

int main() {
   
   int inputArray[SIZE] = { 0 };
   int frequency[FREQ_SIZE] = { 0 };
   int diffNums[SIZE] = { 0 };
   int num, counter = 0;

   // report what the program does
    printf("Iveskite seka is %d nariu-(io)\n", SIZE);

   // ask to enter 10 numbers 
    // printf("Iveskite 1 sekos elementa: %d",);

   while(counter < SIZE){
      // ask to enter the following number
      printf("Iveskite %d sekos elementa: ", counter+1);

      if((scanf("%d", &num) == 1) && (getchar() == '\n')){
         if ((num >= 0) && (num <= FREQ_SIZE)){
            inputArray[counter++] = num;
            // report that number entered successfully
            // printf(" \n");
         } else {
            // report that value exceeds bounds and has to belong to [0; FREQ-SIZE]
            printf("virsyti masyvo reziai [0; %d]!\n", FREQ_SIZE);
         }
      } else {
         // report invalid input, ask to enter whole non-negative number again
        int invalid_input=0;
         while(getchar() != '\n')
            invalid_input=1;
        if(invalid_input)
            printf("Netinkama ivestis! Iveskite sveika, neneigiama skaiciu!\n");
      }
   }
   
   // report that data has been entered correctly
   printf("Skaicius %*s", 40, "Pasikartojimu skaicius\n");

   // proceeding to computations...
   
   for(int i=0; i<SIZE; i++){
        frequency[ inputArray[i] ]++;
   }

   int flag;
   int diffNumsCounter = 0;

   for(int i=0; i<SIZE; i++){
      flag=1;
      for(int j=0; j<i; j++){
         if(inputArray[i] == inputArray[j]){
            flag=0;
         }        
      }       
      if(flag){
         diffNums[diffNumsCounter] = inputArray[i];
         diffNumsCounter++;
      }
   }

   int temp;

   for(int j=0; j<diffNumsCounter-1; j++){
      for(int i=0; i<diffNumsCounter-j-1; i++){
         if(diffNums[i] > diffNums[i+1]){
            temp = diffNums[i];
            diffNums[i] = diffNums[i+1];
            diffNums[i+1] = temp;
         }
      }
   }

   // report that results will be reported
   for(int i=0; i<diffNumsCounter; i++){
      if( frequency[ diffNums[i] ] != 0 ){
         // report the value of diffNums[i] and the value of frequency[diffNums[i]]
         printf("%8d" "%*d\n", diffNums[i], 40, frequency[diffNums[i]]);
      }
   }

   return 0;
}