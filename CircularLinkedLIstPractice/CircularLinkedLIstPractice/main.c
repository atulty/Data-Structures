
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

int deleteDLL(node **head,int pos)
{
    node *current = *head,*temp = 0;
    int k = 1,x = -1;
    if(!head)
        return x;
    if(pos == 1)
    {
        temp = *head;
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        (*head) = (*head)->next;
        x = temp->data;
        free(temp);
    }
    else
    {
        while(current->next != *head && k < pos)
        {
            current = current->next;
            k++;
        }
        if(current->next == *head)
        {
            temp = current;
            current->prev->next = *head;
            (*head)->prev = current->prev;
            x = temp->data;
            temp->prev = temp->next = 0;
            free(temp);
        }
        else
        {
            temp = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            x = temp->data;
            free(temp);
        }
    }
    return x;
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

void deleteLL(node **head)
{
    node *current = *head;
    while(current->next != *head)
    {
        node *aux = current->next;
        free(current);
        current = aux;
    }
    free(current);
    *head = 0;
}

int main(int argc, const char * argv[]) {
    insert(&head,123,1);
    insert(&head,1233,2);
    insert(&head,1235,3);
    display(&head);
    insert(&head,1335,2);
    printf("%d \n",deleteDLL(&head, 4));
    display(&head);
    deleteLL(&head);
    display(&head);
    return 0;
}
