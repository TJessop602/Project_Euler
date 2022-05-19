#include <malloc.h>
#include <stdio.h>
#include <error.h>
#include "BigInt.h"

static bigint* NewBigInt(int Length)
{
    bigint* Number = (bigint*)malloc(sizeof(bigint));
    Number->Length = Length;
    Number->IsNegative = false;
    Number->Digits = (char*)malloc(Number->Length*sizeof(char));
    for(int i = 0; i < Number->Length; i++)
    {
        *(Number->Digits + i) = '0';
    }

    return Number;
}

static bool BigIntAbsAGreaterEqualAbsB(bigint* A, bigint* B)
{
    if(A->Length == B->Length)
    {
        for(int i = A->Length; i >= 0; i--){
            if(*(A->Digits + i) < (*(B->Digits + i)))
            {
                return false;
            }
        }
        return true;
    }
    if(A->Length < B->Length)
    {
        return false;
    }

    return true;

}

void FreeBigInt(bigint* BigInt){
    free(BigInt->Digits);
    free(BigInt);
}

bigint* NewBigIntFromString(char* Str)
{

    int Length = 0;
    bool Negative = false;

    if(*Str == '-')
    {
        Negative = true;
        Str++;
    }

    while(*Str != '\0')
    {
        if(*Str >= '0' && *Str <= '9')
        {
            Str++;
        }
        else
        {
        error(1,0,"Error: String must be numeric, non-numeric character '%c' found", *Str);
        }
        Length++;
    }

    Str--;

    bigint* Number = NewBigInt(Length);
    Number->IsNegative = Negative;

    for(int i = 0; i < Length; i++)
    {
        *(Number->Digits+i) = *Str;
        Str--;
    }

    return Number;
}

bigint* CopyBigInt(bigint* A)
{
    bigint* Copy = NewBigInt(A->Length);
    Copy->IsNegative = A->IsNegative;

    for(int i = 0; i < A->Length; ++i)
    {
        *(Copy->Digits+i) = *(A->Digits+i);
    }

    return Copy;
}

static void OverwriteBigInt(bigint* Dest, bigint* Source)
{

    Dest->Length = Source->Length;
    Dest->IsNegative = Source->IsNegative;
    Dest->Digits = (char*)realloc(Dest->Digits, Source->Length*sizeof(char));

    for(int i = 0; i<Source->Length; ++i)
    {
        *(Dest->Digits+i) = *(Source->Digits+i);
    }
}

bigint* AddBigInts(bigint* First, bigint* Second)
{
    if(First->IsNegative == Second->IsNegative)
    {
        bigint* Longest = First;
        bigint* Shortest = Second;

        if(First->Length < Second->Length)
        {
            Longest = Second;
            Shortest = First;
        }
        bigint* Result = NewBigInt(Longest->Length+1);

        Result->IsNegative = Longest->IsNegative;

        int Carry = 0;
        for(int i = 0; i < Longest->Length; i++)
        {
            if(i < Shortest->Length)
            {
                int Digit = (*(Longest->Digits+i) - '0') + (*(Shortest->Digits+i) - '0') + Carry;
                *(Result->Digits + i) = Digit%10 + '0';
                Carry = Digit/10;
            }
            else
            {
                int Digit = (*(Longest->Digits+i) - '0') + Carry;
                *(Result->Digits + i) = Digit%10 + '0';
                Carry = Digit/10;
            }
        }
        if(Carry != 0)
        {
    //        realloc(Result->Digits, MaxLength+1);
            *(Result->Digits + Longest->Length) = Carry + '0';
        }
        else
        {
            Result->Length--;
        }
        return Result;
    }

    else if(First->IsNegative != Second->IsNegative)
    {
        bigint* Longest = First;
        bigint* Shortest = Second;

        if(!BigIntAbsAGreaterEqualAbsB(First, Second))
        {
            Longest = Second;
            Shortest = First;
        }


        bigint* Result = NewBigInt(Longest->Length);

        Result->IsNegative = Longest->IsNegative;

        int Carry = 0;
        for(int i = 0; i < Longest->Length; i++)
        {
            if(i < Shortest->Length)
            {
                int Digit = (*(Longest->Digits+i) - '0') - (*(Shortest->Digits+i) - '0') - Carry;
                Carry = 0;
                if(Digit < 0)
                {
                    Digit += 10;
                    Carry = 1;
                }
                *(Result->Digits + i) = Digit + '0';
            }
            else
            {
                int Digit = (*(Longest->Digits+i) - '0') - Carry;
                Carry = 0;
                if(Digit < 0)
                {
                    Digit += 10;
                    Carry = 1;
                }
                *(Result->Digits + i) = Digit + '0';
            }
        }
        while(*(Result->Digits + Result->Length-1) == '0')
        {
            Result->Length--;
        }
        return Result;
    }
    else
    {
        error(1,0, "Error: Operation failed... somehow...");
        return NewBigIntFromString("0");
    }
}

void AddBigIntsInPlace(bigint* First, bigint* Second)
{
    bigint* Sum = AddBigInts(First, Second);
    OverwriteBigInt(First, Sum);
    FreeBigInt(Sum);
}

bigint* MultiplyBigInts(bigint* First, bigint* Second)
{
    int TotalLength = First->Length + Second->Length;

    bigint* Longest = First;
    bigint* Shortest = Second;

    if(First->Length < Second->Length)
    {
        Longest = Second;
        Shortest = First;
    }

    bigint* Result = NewBigInt(TotalLength);

    int Carry = 0;
    for(int i = 0; i < Shortest->Length; i++)
    {
        Carry = 0;
        for(int j = 0; j < Longest->Length; j++)
        {
            int Digit = (*(Longest->Digits+j) - '0') * (*(Shortest->Digits+i) - '0') + (*(Result->Digits + j + i) - '0') + Carry;
            *(Result->Digits + j + i) = Digit%10 + '0';
            Carry = Digit/10;
        }
        if(Carry != 0)
        {
            int Digit = (*(Result->Digits + Longest->Length + i) - '0') + Carry;
            *(Result->Digits + Longest->Length + i) = Digit + '0';
        }
    }
    if(*(Result->Digits + TotalLength - 1) == '0')
    {
//        realloc(Result->Digits, TotalLength - 1);
        Result->Length--;
    }

    if(Longest->IsNegative != Shortest->IsNegative)
    {
        Result->IsNegative = true;
    }

    return Result;
}

void MultiplyBigIntsInPlace(bigint* First, bigint* Second)
{
    bigint* Prod = AddBigInts(First, Second);
    OverwriteBigInt(First, Prod);
    FreeBigInt(Prod);
}

void PrintBigInt(bigint* Number)
{
    if(Number->IsNegative)
    {
        printf("-");
    }

    for(int i = Number->Length-1; i >= 0;  i--)
    {
        printf("%c", *(Number->Digits+i));
    }

    printf("\n");
}

