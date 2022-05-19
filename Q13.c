#include <stdio.h>
#include "BigInt.h"

void Q13()
{
    bigint* Sum = NewBigIntFromString("37107287533902102798797998220837590246510135740250");
    char str[50];
    FILE * file;
    file = fopen("Q13.txt","r");
    if (file) {
        while (fscanf(file, "%s", str)!=EOF)
        {
            bigint* A = NewBigIntFromString(str);
            AddBigIntsInPlace(Sum, A);
            FreeBigInt(A);
        }
    fclose(file);
    }
    PrintBigInt(Sum);
}

