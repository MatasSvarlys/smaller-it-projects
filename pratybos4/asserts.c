#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "functions.h"

int main(){
    node *beginning;
    node *end;
    FILE *test;

    beginning = (node*)malloc(sizeof(node));
    end = (node*)malloc(sizeof(node));

    beginning->previous = NULL;
    end->next = NULL;

    node *list[5];

    list[0] = intputAtEnd(0, &beginning, &end, &beginning);
    for (int i = 1; i < 5; ++i)
        list[i] = intputAtEnd(i, &beginning, &end, &list[i-1]);

    assert(beginning->next->data == 0);
    assert(list[3]->next->data == 4);
    assert(end->next == NULL);

    test = fopen("test.txt", "r");

    inputListFromFile(test, &beginning, &end, &list[4]);

    assert(list[4]->next->next->data == 8);
    assert(list[4]->next->next == list[4]->next->next->next->previous);

    removeNode(&list[1]);

    assert(list[0]->next == list[2]);
    
    deleteSmallest(beginning->next);

    assert(beginning->next == list[2]);

    printf("everything works fine :)");
}