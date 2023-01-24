#include <stdio.h>
#include <stdlib.h>

struct stack{
    int *begin;
    int size;
};

typedef struct stack Stack;

void initStack(Stack *stack){
    for(int i = 0; i < stack->size; ++i)
        stack->begin[i] = 0;
}

void printStack(Stack *stack){
    for (int i = 0; i < stack->size; ++i)
        printf("%d ", stack->begin[i]);
    
    printf("\n");
}

int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, int value){
    stack->size++;
    stack->begin = realloc(stack->begin, stack->size * sizeof(int));

    stack->begin[stack->size - 1] = value;
}

int top(Stack *stack){
    if (stack->size == 0)
        return 0;
    
    return stack->begin[stack->size - 1];
}

int pop(Stack *stack){
    int value;

    value = top(stack);
    
    if(stack->size > 0){
        stack->size--;
        stack->begin = realloc(stack->begin, stack->size * sizeof(int));
    }

    return value;
}

void destroyStack(Stack *stack){
    free(stack->begin);
    stack->begin = NULL;
    stack->size = 0;
}

int main(){
    // Stack test;
    // int* ptr;
    // ptr = malloc(3 * sizeof(int));
    // test.begin = ptr;
    // test.size = 3;
    // initStack(&test);
    // printStack(&test);
    // push(&test, 15);
    // printStack(&test);
}