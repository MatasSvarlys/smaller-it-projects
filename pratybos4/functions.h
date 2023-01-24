#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

typedef struct node{
    int data;

    struct node *next;
    struct node *previous; 
} node;

node* intputAtEnd(int, node**, node**, node**);
void inputListFromFile(FILE*, node**, node**, node**);
void readList(node**, node**);
void printForward(FILE*, node*);
void printBackwards(FILE*, node*);
void printList(unsigned int, node*, node*);
void removeNode(node**);
void deleteSmallest(node*);
void getFileName(char**);
int printDropDownList(char**, int);

#endif