#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} Node;

Node *createLinkedList(int data)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    return head;
}

Node *insertBegining(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
        return head;
    }
    else
    {
        temp->next = head;
        head = temp;
        return head;
    }
}

Node *insertAtLast(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
        return head;
    }

    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->next = NULL;
    return head;
}

Node *deleteFromBeg(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteLast(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}



int main()
{
    Node *head = createLinkedList(1);
     insertBegining(head, 0);
    printLinkedList(head);
    return 0;
}
