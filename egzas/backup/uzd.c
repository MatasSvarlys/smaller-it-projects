#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 100

typedef struct{
   int x, y, length;
} coordinate;

void debug(char* text){
   printf("[debug] %s\n", text);
}

void removeStartFromList(coordinate **listOfStarts, int *numOfStarts, int index){
   --(*numOfStarts);
   // free(listOfStarts[index]);

   for(int i=index; i<(*numOfStarts); ++i)
      (*listOfStarts)[i] = (*listOfStarts)[i+1];

   realloc(*listOfStarts, sizeof(coordinate) * (*numOfStarts));   
}

void removeWordFromList(char ***list, int index, int *numberOfStrings){
   --(*numberOfStrings);
   free((*list)[index]);

   for(int i=index; i<(*numberOfStrings); ++i)
      (*list)[i] = (*list)[i+1];

   realloc(*list, sizeof(char*) * (*numberOfStrings));
}

int insertWordAtStart(coordinate *listOfStarts, int *numOfStarts, char *word, char ***crosswordStructure, int rows){
   int x = listOfStarts->x;   
   int y = listOfStarts->y;
   int len = listOfStarts->length;

   if((x == 0 || (*crosswordStructure)[x-1][y] == 'X') && ((*crosswordStructure)[x+1][y] == 'O' || (*crosswordStructure)[x+1][y] == word[1])){
      for(int i=0; i<len; i++)
         if((*crosswordStructure)[x+i][y] != 'O' && (*crosswordStructure)[x+i][y] != word[i])
            return 0;

      for(int i=0; i<len; i++)
         (*crosswordStructure)[x+i][y] = word[i];
   } else{
      for(int i=0; i<len; i++)
         if((*crosswordStructure)[x][y+i] != 'O' && (*crosswordStructure)[x][y+i] != word[i])
            return 0;
        
      for(int i=0; i<len; i++)
         (*crosswordStructure)[x][y+i] = word[i];
   }

   return 1; 
}

char** solveCrossword(coordinate *listOfStarts, int numOfStarts, char **wordlist, int numberOfStrings, char** crosswordStructure, int rows){
   if(wordlist == NULL)
      return NULL;
   if(numOfStarts == 0)
      return crosswordStructure;

   for(int i=0; i<numOfStarts; ++i){
      for(int j=0; j<numberOfStrings; ++j){
         if(listOfStarts[i].length == strlen(wordlist[j])){
            //printf("[debug] zodis %s pagal ilgi tinka starte (%d, %d), nes ilgiai: %d\n", wordlist[j], listOfStarts[i].x, listOfStarts[i].y, listOfStarts[i].length);
            if(insertWordAtStart(&listOfStarts[i], &numOfStarts, wordlist[j], &crosswordStructure, rows)){
               removeStartFromList(&listOfStarts, &numOfStarts, i);
               printf("[debug] starts left: %d\n", numOfStarts);
               printf("[debug] list of availabe starts: ");
               for(int k=0; k<numOfStarts;++k)
                  printf("(%d, %d) ", listOfStarts[k].x, listOfStarts[k].y);
               printf("\n");

               removeWordFromList(&wordlist, j, &numberOfStrings);
               printf("[debug] words left: %d\n", numberOfStrings);
               
               for(int k = 0; k<rows; ++k)
                  printf("%s\n", crosswordStructure[k]);  
                       
               printf("\n");

               if(numOfStarts == 0)
                  return crosswordStructure;
               crosswordStructure = solveCrossword(listOfStarts, numOfStarts, wordlist, numberOfStrings, crosswordStructure, rows);
               // return NULL;
            } else
               return NULL;
         }
      }
   }
}

coordinate *findWordStarts(char **grid, int rows, int *numStarts) {
   *numStarts = 0;
   coordinate *starts = NULL;

   for (int i = 0; i < rows; ++i){
      for (int j = 0; j < rows; ++j){
         if (grid[i][j] == 'O') {

            //check if there is an x oposite of an o
            int xAbove = (i == 0 || grid[i-1][j] == 'X');
            int xLeft = (j == 0 || grid[i][j-1] == 'X');
            int oBelow = (i+1 < rows && grid[i+1][j] == 'O');
            int oRight = (j+1 < rows && grid[i][j+1] == 'O');

            if ((xAbove && oBelow) || (xLeft && oRight)){

               if(starts == NULL)
                  starts = (coordinate*)malloc(sizeof(coordinate) * ((*numStarts)+1));
               else
                  starts = (coordinate*)realloc(starts, sizeof(coordinate) * ((*numStarts)+1));
               // printf("[debug] row: %d column: %d\n", i, j);

               starts[*numStarts].x = i;
               starts[*numStarts].y = j;

               int wordLength = 1;
               int currentRow = i;
               int currentCol = j;

               if(xAbove && oBelow)
                  while (currentRow+1 < rows && grid[currentRow+1][currentCol] == 'O'){
                     wordLength++;
                     currentRow++;
                  }
               else
                  while (currentCol+1 < rows && grid[currentRow][currentCol+1] == 'O'){
                     wordLength++;
                     currentCol++;
                  }
               
               starts[*numStarts].length = wordLength;
               // printf("[debug] lenght of the word: %d\n", wordLength);
               (*numStarts)++;
            }
         }
      }
   }
   //Return the array of word lenghts as well
   return starts;
}

char** readStringsFromFile(const char* filename, int* numStrings){
   FILE* file = fopen(filename, "r");
   if (file == NULL) {
      printf("Error opening file\n");
      return NULL;
   }

   char buffer[MAX_STRING_LENGTH];
   int count = 0;

   while (fgets(buffer, MAX_STRING_LENGTH, file)) //read until end of file
      count++;
   rewind(file); 

   char** arr = (char**)malloc(sizeof(char*) * count);

   for (int i = 0; i < count; i++)
      arr[i] = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);


   int a = 0;
   while (!feof(file)) {
      if(fgets(buffer, MAX_STRING_LENGTH, file)) {
         buffer[strcspn(buffer, "\n")] = '\0';
         strcpy(arr[a++], buffer);
      }
   }

   fclose(file);
   *numStrings = count;
   return arr;
}

int main(){
   int numberOfStrings;
   int sideOfSquare;
   int numOfStarts;
   char** wordlist;
   char** crosswordStructure;
   char** solvedCrossword;
   coordinate *listOfStarts;

   wordlist = readStringsFromFile("zodziai.txt", &numberOfStrings);
   crosswordStructure = readStringsFromFile("struktura.txt", &sideOfSquare);
   listOfStarts = findWordStarts(crosswordStructure, sideOfSquare, &numOfStarts);
   printf("[debug] words: %d, starts: %d\n", numberOfStrings, numOfStarts);
   printf("[debug] list of availabe starts: ");
   for(int k=0; k<numOfStarts;++k)
      printf("(%d, %d) ", listOfStarts[k].x, listOfStarts[k].y);
   printf("\n");
   

   solvedCrossword = solveCrossword(listOfStarts, numOfStarts, wordlist, numberOfStrings, crosswordStructure, sideOfSquare);
   
   debug("got back safely");

   for(int i = 0; i<sideOfSquare; ++i){
       printf("%s\n", solvedCrossword[i]);
   }

}