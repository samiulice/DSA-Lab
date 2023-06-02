#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

// Structure of the node
struct node
{
    int data;
    Node *next;
};

// Creating new node:
Node *Create_Node(int data, Node *next)
{
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Unable to allocate memory\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    return new_node;
}
// Inserting node at the end of the list:
Node *Append(int data, Node *head)
{
    Node *new_node = Create_Node(data, NULL);
    if (head == NULL)
    {
        return new_node;
    }
    Node *currnt_node = head;
    while (currnt_node->next != NULL)
    {
        currnt_node = currnt_node->next;
    }
    currnt_node->next = new_node;
    return head;
}


// Inserting node at the beginning 0f the list:
Node *Prepend(int data, Node *head)
{
    Node *new_node = Create_Node(data, head);
    return new_node;
}


//Inserting node at specific location
Node *Insert(Node *head, int data, int position)
{
    Node *new_node = Create_Node(data, NULL);
    Node *temp = head;
    if(position == 1)
    {
        new_node->next = head;
        return new_node;
    }

    for(int i = 0; i < position-2; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}
//Deleting Specific element
Node *Delete_Node(Node *head, int position)
{
    if(head == NULL){
        printf("Empty Linked List::Failed to delete\n");
        return head;
    }
    Node *pre = head;
    if(position == 1)
    {

        head = head->next;
        free(pre);
    }
    for(int i=2; i < position; i++)
    {
        if(pre->next->next == NULL)
        {
            printf("Invalid position::Failed to delete\n");
            return head;
        }
        else if(pre->next!=NULL)
        {
            pre = pre->next;
        }
    }
    Node *temp = pre->next;
    pre->next = pre->next->next;
    free(temp);
    return head;
}
// Traversing Linkedlist:
void Traverse_Node(Node *head)
{
    Node *current_node = head;
    if (head == NULL)
    {
        printf("Empty linkedlist\n");
        return;
    }
    printf("\t");
    while (current_node != NULL)
    {
        printf("%d\t", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
// Main function(program start:)
void main()
{

    Node *head = NULL;
    printf("Enter -1 for close:");
    int n, i = 0;
    while(1)
    {
        scanf("%d", &n);
        if(n == -1){
            break;
        }
        if(i == 0){
            head = Append(n, NULL);
        }
        else{
           head = Append(n, head);
        }
        i++;
    }



    printf("After Create:");
    Traverse_Node(head);

    while(1)
    {
        printf("Enter 1 for prepend\nEnter 2 for append\nEnter 3 for insert\nEnter 4 for Delete\nEnter 5 for Program close\n");
        scanf("%d", &n);
        if(n == 5){
            break;
        }
        else if(n == 4){
            int temp;
            printf("Enter the position:");
            scanf("%d", &temp);
            head = Delete_Node(head, temp);
        }
        else if(n == 3){
            int temp,position;
            printf("Enter element:");
            scanf("%d", &temp);
            printf("Enter the position:");
            scanf("%d", &position);
            head = Insert(head, temp, position);
        }
        else if(n == 2){
            int temp;
            printf("Enter element:");
            scanf("%d", &temp);
            head = Append(temp, head);
        }
        else if(n == 1){
            int temp;
            printf("Enter element:");
            scanf("%d", &temp);
            head = Prepend(temp, head);
        }
        Traverse_Node(head);
    }

}