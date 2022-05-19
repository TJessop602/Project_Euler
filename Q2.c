#include <stdio.h>

void Q2()   //Slower
{
    int Multiplier[] = {0, 1, 0};
    int MultiplierIndex = 0;
    int a = 0;
    int b = 1;
    int Sum = 0;
    while(b < 4000000){
        int c = a + b;
        Sum += (c)*Multiplier[MultiplierIndex%3];
        MultiplierIndex++;
        a = b;
        b = c;
    }
    printf("%d", Sum);
}

void Q2Normal()
{
    int Sum = 0;
    int a = 0;
    int b = 1;
    while(b < 4000000)
    {
        int c = a+b;
        if(c % 2 == 0)
        {
            Sum += c;
        }
        a = b;
        b = c;
    }
    printf("%d", Sum);
}
