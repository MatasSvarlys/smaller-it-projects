#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "functions.h"

int main(){
    node *beginning;
    node *end;

    beginning = (node*)malloc(sizeof(node));
    end = (node*)malloc(sizeof(node));

    beginning->previous = NULL;
    end->next = NULL;

    char *list[] = {"End program", "Read list", "Print list forward", "Print list backward", "Delete smallest element"};
    int numOfItems = 5;
    int choice;

    do{
        choice = printDropDownList(list, numOfItems);
        switch (choice){
        case 0:
            printf("Turning off program");
            break;
        case 1:
            readList(&beginning, &end);
            break;
        case 2:
            printList(1, beginning, end);
            break;
        case 3:
            printList(0, beginning, end);
            break;
        case 4:
            deleteSmallest(beginning->next);
            break;
        default:
            printf("theres no choice like this, try a valdid one\n");
            break;
        }
    } while(choice);
}