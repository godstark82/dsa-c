#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue
{
    int capacity, rear, front;
    int *storage;
} Queue;

//! Function Prototypes
Queue *createQueue(int capacity);
void enqueue(Queue *q, int data);
void dequeue(Queue *q);
void displayQueue(Queue *q);

#endif