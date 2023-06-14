

#include <stdio.h>

int isPrime(int x)
{
    int i , flag = 1;
    for(i = 2 ; i <= x/2 ; i++)
    {
        if(x % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    int num = 20,i;
    for(i = 2 ; i <= num/2 ; i++)
    {
        if(isPrime(i))
        {
            if(isPrime(num-i))
            {
                printf("%d is %d + %d \n",num,i,num-i);
            }
        }
    }
    return 0;
}
