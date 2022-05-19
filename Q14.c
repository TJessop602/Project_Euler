#include <stdio.h>

void Q14()
{
    int EncounterTable[1000000] = {0};
    int TestValue = 2;
    long long i = TestValue;
    int Counter = 0;
    int MaxChain = 1;
    int MaxValue = 1;
    while(TestValue < 1000000)
    {
        while(i > 1)
        {
            if(i%2 == 0)
            {
                i = i/2;
            }
            else
            {
                i = 3*i + 1;
            }

            Counter++;
            if(i < 1000000){
                if(EncounterTable[i] != 0)
                {
                    Counter += EncounterTable[i];
                    i = 1;
                }
            }
        }
        EncounterTable[TestValue] = Counter;
        if(Counter > MaxChain)
        {
            MaxChain = Counter;
            MaxValue = TestValue;
        }
        Counter = 0;
        TestValue++;
        i = (long long)TestValue;
    }
    printf("%d", MaxValue);
}

