#include <stdio.h>
#include <math.h>

int FactorCount(long n)
{
    if(n == 1){return 1;}
    if(n == 2){return 2;}

    int Count = 2;
    for(int i = 2; i < (int)sqrt(n); i++)
    {
        if(n%i == 0)
        {
            Count+=2;
        }
    }
    if(n % (int)sqrt(n) == 0)
    {
        Count++;
    }
    return Count;
}

void Q12()      //Would it be faster to use prime factorisation?
{

    long Tri = 1;
    int i = 2;
    while(1)
    {
        int nFactors = FactorCount(Tri);
        if(nFactors > 500)
        {
            printf("%ld", Tri);
            return;
        }
        Tri += i;
        i++;
    }
}
