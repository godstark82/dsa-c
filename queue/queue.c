#include <stdio.h>
#include <stdlib.h>
#include "../headers/queue.h"



Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->storage = (int *)malloc(sizeof(int));
    return q;
}

void enqueue(Queue *q, int data)
{
    if (q->rear == q->capacity - 1)
    {
        printf("Queue is Full\n");
        return;
    }

    q->storage[++q->rear] = data;
}

void dequeue(Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    // shift all elements from index 1 till rear to the left
    for (int i = 0; i < q->rear; i++)
    {
        q->storage[i] = q->storage[i + 1];
    }

    q->rear--;
}

void displayQueue(Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is Empty\n");
        return;
    }
    //
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d > ", q->storage[i]);
    }
    printf("\n");
}




int main()
{
    Queue *q = createQueue(50);
    enqueue(q, 1);
    displayQueue(q);
    return 0;
}
