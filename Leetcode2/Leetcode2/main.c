//
//  main.c
//  Leetcode2
//
//  Created by Atul Tiwary on 29/07/21.
//

#include <stdio.h>
#include <stdlib.h>

void Merge2Listin1Array(int A[],int l,int mid,int h);

void RMergeSort(int A[],int l,int h)
{
    int mid;
    if(l < h)
    {
        mid = (l + h) / 2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        Merge2Listin1Array(A, l, mid, h);
    }
}

void Merge2Listin1Array(int A[],int l,int mid,int h)
{
    int i,j,k,B[h+5];
    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i <= mid ; i++)
        B[k++] = A[i];
    for(; j <= h ; j++)
        B[k++] = A[j];
    for(i = l ; i <= h ; i++)
        A[i] = B[i];
}

int* calculateRank(int a[],int n)
{
    int *B = (int*)malloc(n*sizeof(int)),j = 0,i, pass = 1;
    for(i = 0 ; i < n ; i++)
    {
        if(a[i] == a[i+1])
        {
            B[j] = B[j+1] = pass;
            pass+=1;
            j+=2;
            i+=1;
        }
        else
        {
            B[j] = pass;
            j+=1;
            pass += 1;
        }
    }
    return B;
}

void display(int A[],int n)
{
    int i;
    for(i = 0 ; i < n ;i++)
        printf("%d ",A[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int A[] ={-5,-10,45,-4,-17,30,-27,44,31,14,33,-32,-1,10,-19,-24,-17,-50,-7,44,47};
    int n = sizeof(A)/sizeof(A[0]);
    RMergeSort(A, 0, n-1);
    display(A,n);
    display(calculateRank(A, n),n);
    return 0;
}
