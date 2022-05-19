#include <stdio.h>

void Q6()
{
    long SquareOfSums = 0;
    long SumOfSquares = 0;

    for(int i = 1; i <= 100; i++)
    {
        SquareOfSums += i;
        SumOfSquares += i*i;
    }

    SquareOfSums *= SquareOfSums;

    printf("%ld", SquareOfSums-SumOfSquares);

}
