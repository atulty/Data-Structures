#include <stdio.h>


int binarysearch(int A[],int length,int key)
{
   int l=0;
   int h=length-1;
   int mid;
   while(l<=h)
   {
       mid=(l+h)/2;
       if(key==A[mid])
           return 1;
       if(key < A[mid])
           h = mid-1;
       else
           l = mid+1;
   }
  return -1;
}


int main(){
    int arr[] = {2,4,7,8};
    int length = 3;
    int res = binarysearch(arr, length, 7);
    printf("%d ",res);
}
