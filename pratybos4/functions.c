#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "functions.h"

node* intputAtEnd(int data, node **beginning, node **end, node **lastNode){
    node *tempNode;

    tempNode = (node*)malloc(sizeof(node));
    tempNode->data = data;

    tempNode->next = *end;
    (*end)->previous = tempNode;

    (*lastNode)->next = tempNode;
    tempNode->previous = *lastNode;

    return tempNode;
}

void inputListFromFile(FILE *file, node **beginning, node **end, node **lastNode){
    static FILE *readFile = NULL;
    int tempInt;
    node *tempNode;

    if (file)
        readFile = file;
    
    if(fscanf(readFile, "%d", &tempInt) == EOF)
        return;

    // printf("[debug] i read the number: %d\n", tempInt);
    tempNode = intputAtEnd(tempInt, beginning, end, lastNode);

    inputListFromFile(NULL, beginning, end, &tempNode);
}

void readList(node **beginning, node **end){ 
    char *iFileName;
    FILE *readFile;

    printf("input file name:\n");
    getFileName(&iFileName);
    
    if(!(readFile = fopen(iFileName, "r"))){
        char temp;
        printf("file not found, do you want to try again? (y/n): ");
        scanf("%c", &temp);
        if(temp == 'y')
            readList(beginning, end);
        else
            return;
    }

    inputListFromFile(readFile, beginning, end, beginning);  

    (*end)->next = NULL;
    (*beginning)->previous = NULL;

    fclose(readFile);
    printf("file read correctly\n");          
    return;
}

void printForward(FILE *file, node *currNode){
    if (currNode->next == NULL)
        return;
    fprintf(file, "%d ", currNode->data);
    printForward(file, currNode->next);
}

void printBackwards(FILE *file, node *currNode){
    if (currNode->previous == NULL)
        return;
    fprintf(file, "%d ", currNode->data);
    printBackwards(file, currNode->previous);
}

void printList(unsigned int direction, node *beginning, node *end){ //direction == 1 forward, direction == 0 backwards
    char *oFileName;
    FILE *outputFile;

    printf("output file name:\n");
    getFileName(&oFileName);

    if(!(outputFile = fopen(oFileName, "w"))){
        char temp;
        printf("file not created, do you want to try again? (y/n):");
        scanf("%c", &temp);
        if(temp == 'y')
            printList(direction, beginning, end);
        else
            return;
    }

    if(direction){
        printForward(outputFile, beginning->next);
    } else{
        printBackwards(outputFile, end->previous);
    }
    fclose(outputFile);
    printf("output complete\n");
    return;
}

void removeNode(node **nodeToDelete){
    (*nodeToDelete)->next->previous = (*nodeToDelete)->previous;
    (*nodeToDelete)->previous->next = (*nodeToDelete)->next;
    free(*nodeToDelete);
    printf("node removed\n");
    return;
}

void deleteSmallest(node *head){
    int temp = INT_MAX;
    node *nodeToDelete;
    unsigned int headGotten = 0;

    while(head->next != NULL){
        headGotten = 1;

        if(temp > head->data){
            // printf("[debug] smaller node found\n");
            temp = head->data;
            nodeToDelete = head;
        }

        head = head->next;

        // printf("[debug] moved to the next node\n");
    }

    if(headGotten){
        printf("node to delete found\n");
        removeNode(&nodeToDelete);
    } else
        printf("theres no list to delete from\n");
    return;
}

unsigned int endsWithTxt(char *arr){
    arr = strrchr(arr, '.');

    if(arr != NULL)
        return(!strcmp(arr, ".txt"));

    return 0;
}

void getFileName(char **fileName){

    char tempString[255];
    unsigned int loopAgain = 0;
    
    do{
        if (scanf("%s.txt", &tempString) == 1 && (getchar() == '\n')){
            if (!endsWithTxt(tempString)){
                printf("name has to end in .txt, try again:\n");
                loopAgain = 1;   
                continue; 
            }
            printf("file name input correctly\n");
            *fileName = malloc(strlen(tempString) * sizeof(char));
            strcpy(*fileName, tempString);
            loopAgain = 0;

        } else {
            printf("input invalid, try again:\n");
            loopAgain = 1;
        }
    
    } while (loopAgain);
}

int printDropDownList(char *list[], int numOfElements){
    int temp;
    printf("input a number coresponding to your choice and press enter\n");
    for (int i = 0; i < numOfElements; ++i){
        printf("%d: %s\n", i, list[i]);
    }
    scanf("%d", &temp);
    return temp;
}