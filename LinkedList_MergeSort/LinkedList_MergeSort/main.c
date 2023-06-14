
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head = NULL,*tail = 0;

typedef struct node node;

void insert(node** head,int pos,int x)
{
    node *new = (node*)malloc(sizeof(node)),*p = *head,*q = NULL;
    if(!new)
        return;
    int k = 1;
    new->next = NULL;
    new->data = x;
    if(pos == 1)
    {
        new->next = *head;
        *head = new;
        tail = new;
    }
    else
    {
        while(p && k < pos)
        {
            q = p;
            p = p->next;
            k++;
        }
        if(!p)
        {
            q->next = new;
            tail = new;
        }
        else
        {
            new->next = p;
            q->next = new;
        }
    }
}

void display(node **head)
{
    node *p = *head;
    if(!p)
    {
        printf("kat gya\n");
        return;
    }
        while(p)
        {
            printf("%d ",p->data);
            p = p->next;
        }
    printf("\n");
}
 
node* FindMidNode(node *head)
{
    node *slow = head,*fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* sortedMerge(node *first,node *second)
{
    node *result = 0;
    if(!first)
        return second;
    else if (!second)
        return first;
    if(first->data <= second->data)
    {
        result = first;
        result->next = sortedMerge(first->next, second);
    }
    else
    {
        result = second;
        result->next = sortedMerge(first, second->next);
    }
    return result;
}

void MergeSort(node **head)
{
    if(!(*head) || !(*head)->next)
        return;
    node *mid = FindMidNode(*head);
    node *first = *head;
    node *second = mid->next;
    mid->next = 0;
    MergeSort(&first);
    MergeSort(&second);
    *head = sortedMerge(first,second);
}

int main()
{
    insert(&head,1,7);
    insert(&head,2,6);
    insert(&head,3,5);
    insert(&head,4,4);
    insert(&head,5,3);
    insert(&head,6,2);
    insert(&head,7,1);
    display(&head);
    MergeSort(&head);
    display(&head);
}
