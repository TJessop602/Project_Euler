#include <stdio.h>

void Q1() //slightly faster
{
    int Sum = 0;
    int Value = 0;
    int Next[] = {3, 2, 1, 3, 1, 2, 3};
    int NextIndex = 0;
    while(Value < 1000)
    {
        Sum += Value;
        Value += Next[NextIndex%7];
        NextIndex++;
    }
    printf("%d", Sum);
}

void Q1Normal()
{
    int Sum = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(i%3 == 0 || i%5 == 0)
        {
            Sum += i;
        }
    }
    printf("%d", Sum);
}
