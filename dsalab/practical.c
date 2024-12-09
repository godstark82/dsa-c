#include <stdio.h>
#include <stdlib.h>

//! CodeChef Qns
//! 1. Search in array [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/SEARCHINARR]
int searchInArray(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
        return -1;
    }
}

//! 2. Find Maximum in array [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/UWCOI20A]
int maxInArray(int arr[], int n)
{
    int maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return arr[maxIndex];
}

//! 3. Largest and Second Largest [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/LARGESECOND]
//? Printing the sum of largest and second largest in an array
//? We can also do it by sorting the array and get last two elements
int largestAndSecondLargestSum(int arr[], int n)
{
    int max = a[0];
    int maxIndex = 0;
    int secMax = -1;

    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != max && a[i] > secMax && i != maxIndex)
        {
            secMax = a[i];
        }
    }

    return (max + secMax);
}

//! 4. Cost of Groceries [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/KITCHENCOST]
int totalCostOfGrocery(int a[], int b[], int n)
{
    //? a -> Freshness, b[] -> Cost
    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= x)
        {
            cost = cost + b[i];
        }
    }

    return cost;
}

//! 5. Running Comparison [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/RUNCOMPARE]
int runningComparison(int a[], int b[], int n)
{
    int bothHappyCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (b[i] > 2 * a[i] || a[i] > 2 * b[i])
        {
        }
        else
        {
            bothHappyCount++;
        }
    }

    return bothHappyCount;
}

//!
//!     SORTING
//!

//! BubbleSort
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//! Selection Sort
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

//! Insertion Sort
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

//! Fibonacci Series
int fibonacciSeries(int n)
{
    if (n <= 1)
        return n;
    return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
}

//! Factorial
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

//! Linked List
struct LLNode
{
    int data;
    struct LLNode *next;
};

//! Insertion in Linked List
struct LLNode *insertAtHead(struct LLNode *head, int data)
{
    struct LLNode *newNode = (struct LLNode *)malloc(sizeof(struct LLNode));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    newNode->next = head;
    head = newNode;

    return head;
}

//! Insertion at Tail
struct LLNode *insertAtTail(struct LLNode *head, int data)
{
    struct LLNode *newNode = (struct LLNode *)malloc(sizeof(struct LLNode));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    struct LLNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//! Deletion in first
struct LLNode *deleteFirst(struct LLNode *head)
{
    if (head == NULL)
        return NULL;
    struct LLNode *temp = head;
    head = head->next;
    free(temp);
    return head;
}

//! Deletion in last
struct LLNode *deleteLast(struct LLNode *head)
{
    if (head == NULL)
        return NULL;
    struct LLNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

//! Binary Search Tree
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

//! PreOrder
void preOrder(struct BSTNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

//! InOrder
void inOrder(struct BSTNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

//! PostOrder
void postOrder(struct BSTNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

//! Height of BST
int heightOfBST(struct BSTNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightOfBST(root->left), heightOfBST(root->right));
}

//! Search in BST
struct BSTNode *searchInBST(struct BSTNode *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    if (data < root->data)
        return searchInBST(root->left, data);
    return searchInBST(root->right, data);
}

//! **** Binary Search Tree from PreOrder only
struct BSTNode *constructBSTFromPreOrderUtil(int preOrder[], int *preIndex, int key, int min, int max, int n) {
    if (*preIndex >= n)
        return NULL;
        
    struct BSTNode *root = NULL;
    
    if (key > min && key < max) {
        root = (struct BSTNode *)malloc(sizeof(struct BSTNode));
        root->data = key;
        root->left = NULL;
        root->right = NULL;
        
        *preIndex = *preIndex + 1;
        
        if (*preIndex < n) {
            root->left = constructBSTFromPreOrderUtil(preOrder, preIndex, preOrder[*preIndex], min, key, n);
        }
        if (*preIndex < n) {
            root->right = constructBSTFromPreOrderUtil(preOrder, preIndex, preOrder[*preIndex], key, max, n);
        }
    }
    
    return root;
}

struct BSTNode *constructBSTFromPreOrder(int preOrder[], int n) {
    if (n == 0) return NULL;
    int preIndex = 0;
    return constructBSTFromPreOrderUtil(preOrder, &preIndex, preOrder[0], INT_MIN, INT_MAX, n);
}


//! Print the number of direct neighbours of each node in a graph using adjacency matrix
void printDirectNeighbours(int n, int adjMatrix[][n]) // Fixed parameter order and array syntax
{
    if (n <= 0) return; // Input validation
    
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
                count++;
        }
        printf("Node %d has %d neighbours\n", i, count);
    }
}

//! Print the number of direct neighbours using adjacency list
void printDirectNeighboursAdjList(int n, struct Node* adjList[]) 
{
    if (n <= 0 || adjList == NULL) return;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        struct Node* temp = adjList[i];
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("Node %d has %d neighbours\n", i, count);
    }
}


//* ------- END OF PRACTICALS ------- */

