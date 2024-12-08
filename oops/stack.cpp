#include <iostream>

using namespace std;

#define max 50

class Stack
{
    int arr[max];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int data)
    {
        arr[++top] = data;
    }

    int pop()
    {
        int value = arr[top];
        top--;
        return value;
    }

    int peek()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == max - 1;
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Stack s = Stack();
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;
    s.display();
    return 0;
}