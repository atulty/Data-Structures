//
//  main.c
//  leetcode1
//
//  Created by Atul Tiwary on 19/07/21.
//

#include <stdio.h>

int maxArea(int a[], int heightSize){
    int i = 0,j = heightSize,value,result,max = 0;
    while(i < j)
    {
        if(a[i] <= a[j] || a[j] <= a[i])
        {
            result = (a[i] <= a[j]) ? a[i] : a[j];
                value = result * (j-i);
            if(value > max)
                max = value;
        }
        (a[j] > a[i]) ? i++ : j--;
    }
    return max;
}

int main(int argc, const char * argv[])
{
    //int height[] = {1,8,6,2,5,4,8,3,7};
    int height[] = {9,3,2,1,4,2};
    int heightSize = sizeof(height)/sizeof(height[0]);
    printf("%d \n",maxArea(height, heightSize-1));
    return 0;
}
