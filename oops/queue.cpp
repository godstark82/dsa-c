#include <iostream>
using namespace std;

#define max 50

class Queue
{
    int arr[max];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int data)
    {
        if (rear == max - 1)
        {
            cout << "Queue Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow" << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }

    bool isEmpty(){
        return front == -1 && rear == -1;
    }

    bool isFull(){
        return rear == max - 1;
    }

    int peek(){
        return arr[front];
    }





    void clear(){
        front = -1;
        rear = -1;
    }

    int size(){
        return rear - front + 1;
    }
};

int main()
{
    Queue q = Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.size() << endl;
    q.display();
    return 0;
}