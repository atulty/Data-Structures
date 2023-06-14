#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head = NULL;

typedef struct node node;

void insert(node **head,int pos,int x)
{
    node *new = (node*)malloc(sizeof(node)),*p = *head;
    if(!new)
        return;
    int k = 1;
    new->next = new->prev = NULL;
    new->data = x;
    if(pos == 1)
    {
        if(!(*head))
            *head = new;
        else
        {
            new->next = *head;
	        (*head)->prev = new;
            *head = new;
        }
    }
    else
    {
        
        while(p->next && k < pos)
        {
            p = p->next;
            k++;
        }
        if(!p->next)
        {
            new->prev = p;
	        p->next = new;
        }
        else
        {
            node *l = p->prev;
            node *r = p;
            new->prev = l;
            new->next = r;
            l->next = new;
            r->prev = new;
        }
        
    }
}

int delete(node **head,int pos)
{
    node *temp = 0,*current = *head;
    int k = 1,x = -1;
    if(!head)
    {
        printf("List empty\n");
        return x;
    }
    if(pos == 1)
    {
        temp = *head;
        *head = (*head)->next;
        temp->next = temp->next->prev = 0;
        x = temp->data;
        free(temp);
    }
    else
    {
        while (current->next && k < pos) {
            current = current->next;
            k++;
        }
        if(!current->next)
        {
            current->prev->next = 0;
            current->prev = 0;
            x = current->data;
            free(current);
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current->prev = current->next = 0;
            x = current->data;
            free(current);
        }
    }
    return x;
}

void deleteDDl(node **head)
{
    node *current = *head;
    while (current) {
        node *aux = current->next;
        free(current);
        current = aux;
    }
}

void display(node *head)
{
    node *p = head;
    while (p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    insert(&head,1,23);
    insert(&head,2,123);
    insert(&head,3,223);
    display(head);
    insert(&head,2,423);
    display(head);
    /*printf("%d \n",delete(&head, 3));
    display(head);
    printf("%d \n",delete(&head, 1));
    display(head);
    printf("%d \n",delete(&head, 2));
    display(head);*/
    deleteDDl(&head);
    display(head);
    return 0;
}
