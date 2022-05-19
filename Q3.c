#include <stdio.h>

void Q3(){
    long long n = 600851475143;
    size_t length = 10;
    int PrimeFactors[length];
    PrimeFactorisationOfN(n, PrimeFactors, length);
    for(int i = 0; PrimeFactors[i] != -1; i++)
    {
        printf("%d, ", PrimeFactors[i]);
    }
}
