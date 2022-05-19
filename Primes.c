#include <malloc.h>
#include <math.h>
#include "Primes.h"

int* PrimesLessThanN(int n)     //0.3 seconds to find 1,000,000th prime, Approx 4 seconds to find the 10,000,000th prime
{

    //Prime number sieve where non-primes are zeroed

    int* Numbers = malloc(n*sizeof(int));
    for(int i = 0; i < n/2; i++)
    {
        *(Numbers+i) = 2*i + 1;     //We only care about odd numbers
    }

    *(Numbers+0) = 2;  //Two notwithstanding

    int Counter = 0;

    for(int i = 1; i < n/2; i++)
    {
        if(*(Numbers + i) != 0)         //Factors already encountered are set to zero so skip them
        {
            Counter++;
            for(int j = i+(*(Numbers+i)); j < n/2; j=j+(*(Numbers+i)))   //The index of the next odd factor of x is x above the current index...
            {
                *(Numbers+j) = 0;       //and since this number is a factor of x it isn't prime
            }
        }
    }

    //Remove all the zeros leaving only primes and return

    int* Primes = calloc(Counter+1,sizeof(int));  //The end of the area is marked with a zero
    int Next = 0;

    for(int i = 0; i < n/2; i++)
    {
        if(*(Numbers+i) != 0)
        {
            *(Primes + Next) = *(Numbers + i);
            Next++;
        }
    }
    free(Numbers);      //Array from the prime sieve is no longer needed
    return Primes;      //Heap allocated, needs to be freed by the calling function
}

void PrimeFactorisationOfN(long long n, int* Array, size_t Length)
{
    int* Primes = PrimesLessThanN((int)sqrt(n));
    int ArrayIndex = 0;
    int PrimesIndex = 0;
    while(n > 1){
        if(n%(*(Primes+PrimesIndex)) == 0)
        {
            if(ArrayIndex >= Length)
            {
                printf("Error in PrimeFactorisationOfN: Too many factors for array, pass a larger array\n\n\n");
                break;
            }
            n = n/(*(Primes+PrimesIndex));
            *(Array + ArrayIndex) = *(Primes+PrimesIndex);
            ArrayIndex++;
        }
        else
        {
            PrimesIndex++;
        }
    }
    Array[ArrayIndex] = -1;
}

int NthPrime(int n)
{
    int EarlyPrimes[] = {2,3,5,7,11,13};
    if(n <= 6)
    {
        return EarlyPrimes[n-1];
    }

    int UpperBound = (int)(n*(log(n) + log(log(n))));  //only works for n > 6 hence the above.
    int *Primes = PrimesLessThanN(UpperBound);
    return *(Primes + n - 1);
}

void PrintPrimesLessThanN(int n)
{
    int* Primes = PrimesLessThanN(n);
    int i = 0;
    while(*(Primes+i) != 0)
    {
        printf("%d, ", *(Primes+i));
        i++;
    }
    printf("\n");
    free(Primes);
}
