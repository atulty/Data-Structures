//
//  main.c
//  DsAlgoBookPractice
//
//  Created by Atul Tiwary on 12/06/21.
//

#include <stdio.h>

int count = 10;

void func3()
{
    printf("In func3 = %d\n",count);
}

void func2()
{
    func3();
}

void func1()
{
    int count = 30;
    func2();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    func1();
    return 0;
}
