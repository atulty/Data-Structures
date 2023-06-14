

#include <stdio.h>
//#include<string.h>

void binary(char A[],int n)
{
    if(n < 1)
        puts(A);
    else
    {
        A[n-1] = '0';
        binary(A,n-1);
        A[n-1] = '1';
        binary(A,n-1);
    }
}

void kString(char A[],int n,int k)
{
    int j;
    if(n < 1)
        puts(A);
    else
    {
        for(j = 0 ; j < k ; j++)
        {
            A[n-1] = j + 48;
            kString(A, n-1, k);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n = 5,k = 3;
    char A[n];
    //A[n-1] = '\0';
    //binary(A,n);
    kString(A, n, k);
    return 0;
}
