#include <stdio.h>
#include <stdlib.h>

//! Side functions
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//! Printing Utilities
void printList(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void printInt(int value)
{
    printf(" %d ", value);
}

//! Sortings

//? Bubble Sort
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//? Selection Sort
void selectionSort(int nums[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }

        //! Swap the minIndex value to the currentIndex of I
        swap(&nums[i], &nums[minIndex]);
    }
}

//? Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

//! LinkedList
typedef struct node
{
    int data;
    struct node *next;

} Node;

Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

Node *insertFirst(Node *head, int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}

Node *insertAtLast(Node *head, int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
    return head;
}

void removeFirst(Node *head, int data)
{
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    free(temp);
    return;
}

void removeLast(Node *head, int data)
{
    if (head == NULL)
        return;
    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = NULL;
    free(temp);
}

void printLL(Node *head)
{
    if (head == NULL)
        return;
    Node *current = head;
    while (current)
    {
        printInt(current->data);
        current = current->next;
    }
    printf("NULL \n");
}

#define MAX 100

//! Stack
typedef struct stack
{
    int arr[MAX];
    int top;
} Stack;

Stack *initStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return (s->top == MAX - 1);
}

//! Ops -> Push, Pop, Peek
Stack *push(Stack *s, int data)
{
    if (isFull(s))
        return;
    s->arr[++s->top] = data;
    return s;
}

int pop(Stack *s)
{
    if (isEmpty(s))
        return;
    int value = s->arr[s->top];
    s->top--;
    return value;
}

int peek(Stack *s)
{
    if (isEmpty(s))
        return -1;
    return s->arr[s->top];
}

//! Queue
typedef struct queue
{
    int arr[MAX];
    int front;
    int rear;
} Queue;

Queue initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmptyQueue(Queue *q)
{
    return (q->front == -1);
}

int isFullQueue(Queue *q)
{
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int data)
{
    if (q == NULL || isFullQueue(q))
        return;
    q->arr[++q->rear] = data;
}

int dequeue(Queue *q)
{
    if (q == NULL || isEmptyQueue(q))
        return;
    int value = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    q->front++;
    return value;
}

//! Binary Tree
typedef struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;

} TNode;

TNode *createBT(int data)
{
    TNode *root = (TNode *)malloc(sizeof(TNode));
    root->left = NULL;
    root->right = NULL;
    root->data = data;
    return root;
}

void preOrder(TNode *root)
{
    if (root)
    {
        printInt(root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TNode *root)
{
    if (root)
    {
        inOrder(root->left);
        printInt(root->data);
        inOrder(root->right);
    }
}

void postOrder(TNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printInt(root->data);
    }
}

// Searching in BST
TNode *searchBST(TNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
    {
        return root;
    }
    if (key > root->data)
    {
        searchBST(root->right, key);
    }
    else
    {
        searchBST(root->left, key);
    }
}

//! Tower of Hanoi
void TOH(int n, char x, char y, char z)
{
    if (n == 1)
    {
        printf("Move Disc %c to %c", x, z);
        return;
    }
    TOH(n - 1, x, z, y);
    printf("Move disk %d from %c to %c\n", n, x, y);
    TOH(n - 1, z, y, x);
}

/*
! TIME COMPLEXITY
! ORDER
?=> const < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(2^n) < O(n!)



*/