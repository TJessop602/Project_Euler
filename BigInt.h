#ifndef BigInt_H
#define BigInt_H

typedef enum { false, true } bool;

typedef struct
{
    bool IsNegative;
    int Length;
    char* Digits;
}bigint;

bigint* NewBigIntFromString(char* Str);
static bigint* NewBigInt(int Length);
bigint* AddBigInts(bigint* First, bigint* Second);
void AddBigIntsInPlace(bigint* First, bigint* Second);
bigint* MultiplyBigInts(bigint* First, bigint* Second);
void MultiplyBigIntsInPlace(bigint* First, bigint* Second);
bigint* CopyBigInt(bigint* A);
static void OverwriteBigInt(bigint* Source, bigint* Dest);
static bool BigIntAbsAGreaterEqualAbsB(bigint* A, bigint* B);
void PrintBigInt(bigint* Number);
void FreeBigInt(bigint*);

#endif
