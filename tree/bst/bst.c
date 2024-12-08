#include <stdio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insertBST(Node *root, int key)
{
    Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data > key)
        {
            root = root->left;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            return;
        }
    }

    Node *nn = createNode(key);
    if (key < prev->data)
    {
        prev->left = nn;
    }
    else
    {
        prev->right = nn;
    }
}

struct node *deleteNode(struct node *root, int key)
{
    
}

Node *searchBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}

int main()
{

    Node *root = createNode(50);

    root->left = createNode(40);
    root->left->left = createNode(20);
    root->left->right = createNode(45);

    root->right = createNode(60);
    root->right->left = createNode(55);
    root->right->right = createNode(70);

    return 0;
}