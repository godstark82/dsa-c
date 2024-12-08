#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"


Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void push(Stack *s, int data)
{
    // condition for full stack
    if (s->top == max - 1)
        printf("Stack Overflow");
    s->storage[++s->top] = data;
}

int pop(Stack *s)
{
    // COndition for empty Stack
    if (s->top == -1)
        return -1;
    int value = s->storage[s->top];
    s->top--;
    return value;
}

int peek(Stack *s)
{
    return (s->storage[s->top]);
}

int main()
{
    printf("Stack");
    return 0;
}