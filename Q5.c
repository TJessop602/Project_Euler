#include <stdio.h>

void Q5()
{
    int CurrentValue = 20;
    int found = 0;
    while(!found){
        int TestFactor = 20;
        while(CurrentValue%TestFactor == 0 && TestFactor > 10){
            TestFactor--;
        }
        if(TestFactor == 10)
        {
            found = 1;
        }
        else
        {
            CurrentValue += 2;
        }
    }
    printf("%d", CurrentValue);
}

