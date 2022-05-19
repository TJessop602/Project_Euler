#include <stdio.h>
#include <malloc.h>
#include "Primes.h"

void Q10()
{
    int* P = PrimesLessThanN(2000000);
    unsigned long Sum = 0;
    int* i = P;
    while(*i != 0)
    {
        Sum += *i;
        i++;
    }
    printf("%ld", Sum);
    free(P);
}
