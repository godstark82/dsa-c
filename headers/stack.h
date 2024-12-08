
#ifndef STACK_H
#define STACK_H

#define max 50


typedef struct stack {
    int top;
    int storage[max];
} Stack;


Stack *createStack();
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack *s);

#endif
