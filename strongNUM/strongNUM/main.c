#include <stdio.h>

int factorial(int n)
{
    int i,res = 1;
    for(i = 2; i <= n ; i++)
        res = res * i;
    return res;
}

int main(void) {
    int n = 145,rem,sum = 0;
    while(n > 0)
    {
        rem = n%10;
        sum += factorial(rem);
        n /= 10;
    }
    n = 145;
    if(sum == n)
        printf("Strong NUmber\n");
    else
        printf("not Strong NUmber\n");
    return 0;
}
