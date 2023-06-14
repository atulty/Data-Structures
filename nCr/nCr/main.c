

#include <stdio.h>


long int factorial(long int x)
{
    long int i,fact = 1;
    for(i = 2 ; i <= x ; i++)
        fact *= i;
    return fact;
}

int main(int argc, const char * argv[]) {
    long int n = 9 ,r = 5,numerator,denominator,result;
    if(n < r)
    {
        long int temp = n;
        n = r;
        r = n;
    }
    numerator = factorial(n);
    denominator = factorial(n - r);
    result = numerator/denominator;
    printf("%ld \n",result);
    return 0;
}
