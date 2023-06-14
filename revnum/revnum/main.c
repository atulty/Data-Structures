//
//  main.c
//  revnum
//
//  Created by Atul Tiwary on 11/08/21.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num = 1211,rev = 0,left,n;
    n = num;
    while(n > 0)
    {
        left = n % 10;
        rev = rev * 10 + left;
        n = n/10;
    }
    if(rev == num)
        printf("true\n");
    else
        printf("%d false\n",rev);
    return 0;
}
