
#include <stdio.h>
#include <stdlib.h>

struct treenode
{
    struct treenode *lchild;
    int data;
    struct treenode *rchild;
}*root=0;

typedef struct treenode treenode;

void insert(int key)
{
    treenode *p = root;
    treenode *temp,*r;
    if(!root)
    {
        temp = (treenode*)malloc(sizeof(treenode));
        temp->data = key;
        temp->lchild = temp->rchild = 0;
        root = temp;
        return;
    }
    while(p)
    {
        r = p;
        if(key<p->data)
            p = p->lchild;
        else if(key>p->data)
            p = p->rchild;
        else
            return;
    }
        temp = (treenode*)malloc(sizeof(treenode));
        temp->data = key;
        temp->lchild = temp->rchild = 0;
        if(key<r->data)
            r->lchild=temp;
        else
            r->rchild=temp;
        return;
}

void Preorder(treenode *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void inorder(treenode *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void Postorder(treenode *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

treenode* convertToDoubleyLL(treenode *p)
{
    static treenode *prev = NULL,*head = 0;
    if(p == NULL)
        return NULL;
    convertToDoubleyLL(p->lchild);
    if(!prev)
    {
        prev = p;
        head = p;
    }
    else
    {
        prev->rchild = p;
        p->lchild = prev;
        prev = p;
    }
    convertToDoubleyLL(p->rchild);
    return head;
}

void display(treenode *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p = p->rchild;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    treenode *head;
     insert( 10);
     insert(5);
     insert( 50);
     insert(20);
     insert(30);
     insert( 60);
     Preorder(root);
     printf("\n");
     inorder(root);
     printf("\n");
     Postorder(root);
     printf("\n");
    head = convertToDoubleyLL(root);
    display(head);
     return 0;
}
