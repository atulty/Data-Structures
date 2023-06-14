
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head = 0;

typedef struct node node;

void insert(node **head,int x,int pos)
{
    node *temp = (node*)malloc(sizeof(node)),*current = *head;
    int k = 1;
    if(!temp)
        return;
    temp->prev = temp->next = temp;
    temp->data = x;
    if(pos == 1)
        *head = temp;
    else
    {
        while(current->next != *head && k < pos)
        {
            current = current->next;
            k++;
        }
        if(current->next == *head)
        {
            current->next = temp;
            temp->prev = current;
            temp->next = *head;
            (*head)->prev = temp;
        }
        else
        {
            temp->prev = current->prev;
            temp->next = current;
            current->prev->next = temp;
            current->prev = temp;
        }
    }
}

void display(node **head)
{
    node *current = *head;
    if(!head)
    {
        exit(0);
    }
    else
    {
        while (current->next != (*head)) {
            printf("%d ",current->data);
            current = current->next;
        }
        printf("%d\n",current->data);
    }
}

int findMid(node **head,node **fastPtr,node **slowPtr)
{
    
    if(!head)
        return 0;
    int flag = 1;
    while((*fastPtr)->next != *head)
    {
        flag = 2;
        (*fastPtr) = (*fastPtr)->next;
        if((*fastPtr)->next != *head)
        {
            flag = 1;
            *slowPtr = (*slowPtr)->next;
            *fastPtr = (*fastPtr)->next;
        }
    }
    (*fastPtr)->next = *head;
    return flag;
}

void push(node **fastPtr,node *head2)
{
    node *dummy = (node*)malloc(sizeof(node));
    dummy->data = -1;
    dummy->next = head2;
    (*fastPtr)->next = dummy;
}

void splitCLLinTwo(node **head,node **head1,node **head2)
{
    node *fastPtr = *head,*slowPtr = *head;
    int res = findMid(head,&fastPtr,&slowPtr);
    if(res == 2)
    {
        *head1 = *head;
        *head2 = slowPtr->next;
        slowPtr->next = *head;
        fastPtr->next = *head2;
    }
    else if(res == 1)
    {
        *head1 =* head;
        *head2 = slowPtr->next;
        slowPtr->next = *head;
        push(&fastPtr,*head2);
    }
}

int main()
{
        node *head1,*head2;
        insert(&head,123,1);
        insert(&head,1233,2);
        insert(&head,1235,3);
        insert(&head,1212,4);
        display(&head);
        splitCLLinTwo(&head,&head1, &head2);
        display(&head1);
        display(&head2);
    return 0;
}
