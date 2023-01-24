#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Point{
    double x, y;
};

typedef struct Point Point;

struct stack{
    Point *begin;
    int size;
};

typedef struct stack Stack;


//--------------------point functions-------------------
void printPoint(Point p){
    printf("(%.2f, %.2f) ", p.x, p.y);
}

Point createPoint(double x, double y){
    Point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

double getDistance(Point a, Point b){
    double x, y;
    double distance;
    
    x = a.x - b.x;
    y = a.y - b.y;

    distance = sqrt(pow(x, 2) + pow(y, 2));

    // printf("%.2f\n", distance);

    return distance;

}

//-------------------------stack functions----------------------------

void initStack(Stack *stack){
    for(int i = 0; i < stack->size; ++i)
        stack->begin[i] = createPoint(0, 0);
}

void printStack(Stack *stack){
    for (int i = 0; i < stack->size; ++i)
        printf("%.2f ", getDistance(createPoint(0, 0), stack->begin[i]));
    
    printf("\n");
}

int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, Point value){
    stack->size++;
    stack->begin = realloc(stack->begin, stack->size * sizeof(Point));

    stack->begin[stack->size - 1] = value;
}

Point top(Stack *stack){

    if (stack->size == 0)
        return createPoint(0, 0);
    
    return stack->begin[stack->size - 1];
}

Point pop(Stack *stack){
    Point value;

    value = top(stack);
    
    if(stack->size > 0){
        stack->size--;
        stack->begin = realloc(stack->begin, stack->size * sizeof(Point));
    }

    return value;
}

void destroyStack(Stack *stack){
    free(stack->begin);
    stack->begin = NULL;
    stack->size = 0;
}

int main(){
    Stack test;
    destroyStack(&test);

    push(&test, createPoint(5, -4));
    push(&test, createPoint(46, 5));
    push(&test, createPoint(7, -2));
    push(&test, createPoint(5.4, -5.6));
    push(&test, createPoint(-5.4, -4));

    printStack(&test);
}