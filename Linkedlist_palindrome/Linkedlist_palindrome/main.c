
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode
{
    int data;
    struct ListNode *next;
}*head = NULL,*tail = 0;

typedef struct ListNode ListNode;

void insert(ListNode** head,int pos,int x)
{
    ListNode *new = (ListNode*)malloc(sizeof(ListNode)),*p = *head,*q = NULL;
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

void display(ListNode **head)
{
    ListNode *p = *head;
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

ListNode* reverse(ListNode **p)
{
    ListNode *dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = *p;
    dummy->data = -1;
    ListNode *prev = dummy,*current = *p;
    while(current && current->next)
    {
        prev->next = current->next;
        current->next = current->next->next;
        prev->next->next = current;
        current = current->next;
        prev = prev->next->next;
    }
    return dummy->next;
}

bool isPalindrome(ListNode* head){
     ListNode *current = head,*mid = head;
     bool flag = true;
    if(!head || !head->next)
        return flag;
    while(current && current->next)
    {
        current = current->next;
        if(current->next)
        {
            mid = mid->next;
            current = current->next;
        }
    }
    ListNode *p = mid->next;
    mid->next = 0;
    ListNode *start = reverse(&p);
    current = head;
    while(current && start)
    {
        if(current->data == start->data)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
        current = current->next;
        start = start->next;
    }
    return flag;
    }


int main()
{
    insert(&head,1,1);
    insert(&head,1,0);
    insert(&head,1,2);
    insert(&head,1,0);
    insert(&head,1,1);
    //insert(&head,2,2);
    display(&head);
    bool result = isPalindrome(head);
    printf("%d\n",result);
    return 0;
}
