#include <stdio.h>
#include <math.h>

void Q4()
{
    int i = 999;
    int found = 0;
    while(!found)
    {
        int n = i*1000 + ((i/1)%10)*100 + ((i/10)%10)*10 + ((i/100)%10)*1;
        int j = 999;
        for(int j = 999; j >= n/j; j--)
        {
            if(n%j == 0 && n/j < 1000)
            {
                printf("%d", n);
                found = 1;
                break;
            }
        }
        i--;
    }
}

void Q4Normal()
{
    int IsPalendrome(char* str)
    {
        char* start = str;
        char* end = str;
        while(*(end+1) != '\0'){
            end++;
        }
        while(start < end)
        {
            if(*start != *end)
            {
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }

    int Largest = 0;

    for(int i = 100; i < 1000; i++)
    {
        for(int j = i; j < 1000; j++)
        {
            int Product = i*j;
            int Size = (int)((ceil(log10(Product))+1)*sizeof(char));
            char Str[Size];
            snprintf(Str, Size, "%d", Product);
            if(IsPalendrome(Str) && Product > Largest)
            {
                Largest = Product;
            }
        }
    }
    printf("%d", Largest);
}
