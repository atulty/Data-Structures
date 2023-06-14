

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first = 0,*second = 0,*tail1 = 0,*tail2 = 0;

typedef struct node node;

void firstList(node **first,int x)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->next = 0;
    temp->data = x;
    if(!(*first))
    {
        *first = temp;
        tail1 = temp;
    }
    else
    {
            tail1->next = temp;
            tail1 = temp;
    }
}

void secondList(node **second,int x)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->next = 0;
    temp->data = x;
    if(!(*second))
    {
        *second = temp;
        tail2 = *second;
    }
    else
    {
            tail2->next = temp;
            tail2 = temp;
    }
}

void display(node *p)
{
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

node* findIntersection(node **first,node **second)
{
    node *p = *first,*q = *second,*res = 0;
    int counter1 = 0,counter2 = 0;
    while (p) {
        counter1++;
        p = p->next;
    }
    while(q)
    {
        q = q->next;
        counter2++;
    }
    int result = counter1 > counter2 ? counter1 - counter2 : counter2 - counter1;
    if(counter1 > counter2)
    {
        p = *first;
        while (p && result >= 1)
        {
            p = p->next;
            result--;
        }
    }
    else
    {
        q = *second;
        while (q && result >= 1)
        {
            q = q->next;
            result--;
        }
    }
    q = *second;
    while (p && q)
    {
        if(p == q)
        {
            res = p;
            break;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return res;
}

int main(int argc, const char * argv[])
{
    firstList(&first, 10);
    firstList(&first, 20);
    firstList(&first, 30);
    firstList(&first, 40);
    firstList(&first, 50);
    secondList(&second, 100);
    secondList(&second, 200);
    node *temp = (node*)malloc(sizeof(node));
    temp->next = 0;
    temp->data = 976;
    tail1->next = temp;
    tail2->next = temp;
    display(first);
    display(second);
    node *result = findIntersection(&first, &second);
    printf("%d \n",result->data);
    return 0;
}
