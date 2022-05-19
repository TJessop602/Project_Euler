#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include "Matrix.h"

matrix* CreateEmptyMatrix(int nRows, int nColumns)
{
    assert(nRows > 0 && nColumns > 0);

    matrix* M = (matrix*)malloc(sizeof(matrix));
    M->Columns = nColumns;
    M->Rows = nRows;
    M->Digits = (double*)calloc(nColumns*nRows,sizeof(double));

    return M;
}

matrix* CreateRandomisedMatrix(int nRows, int nColumns, int MaxValue)
{
    matrix* M = CreateEmptyMatrix(nRows,nColumns);
    for(int i = 0; i < M->Rows*M->Columns; i++)
    {
        *(M->Digits + i) = (double)(rand()%MaxValue);
    }
    return M;
}

void FillMatrix(matrix* M, double FillValue)
{
    for(int i = 0; i < M->Rows*M->Columns; i++)
    {
        *(M->Digits + i) = FillValue;
    }
}

matrix* CopyMatrix(matrix* M)
{
    matrix* C = CreateEmptyMatrix(M->Rows, M->Columns);
    for(int i = 0; i < M->Rows*M->Columns; i++)
    {
        *(C->Digits + i) = *(M->Digits + i);
    }
    return C;
}

matrix* CreateMatrixFromString(int nRows, int nColumns, char* Str)
{
    matrix* M = CreateEmptyMatrix(nRows,nColumns);
    int MIndex = 0;

    while(MIndex < nRows*nColumns && *Str != '\0')
    {
        *(M->Digits + MIndex) = strtod(Str, NULL);              //Write the number
        MIndex++;
        Str++;

        while(*Str == '.' || (*Str >= '0' && *Str <= '9'))     //Skip the rest of the number
        {
            Str++;
        }

        while(*Str != '.' && *Str != '-' && *Str != '\0' && (*Str < '0' || *Str > '9'))  //Then skip any possible deliniaters until the start of the next number is found
        {
            Str++;
        }
    }

    if(*Str == '\0' && MIndex != nRows*nColumns)
    {
    printf("Warning: String too short for specified matrix. Length has been buffered with zeros.\n\n");
    }
    else if(*Str != '\0' && MIndex == nRows*nColumns)
    {
    printf("Warning: String too long for specified matrix. Excess characters ignored.\n\n");
    }
    return M;
}

double MatrixGetValue(matrix* M, int Row, int Column)
{
    assert(Row <= M->Rows && Column <= M->Columns);
    return *(M->Digits + ((Row-1)*M->Columns) + (Column-1));
}

void MatrixSetValue(matrix* M, int Row, int Column, double Value)
{
    assert(Row <= M->Rows && Column <= M->Columns);
    *(M->Digits + ((Row-1)*M->Columns) + (Column-1)) = Value;
}

matrix* MatrixAdd(matrix* A, matrix* B)
{
    matrix* M = CreateEmptyMatrix(A->Columns, A->Rows);
    for(int i = 0; i < M->Columns*M->Rows; i++)
    {
        *(M->Digits + i) = *(A->Digits + i) + *(B->Digits + i);
    }
    return M;
}

matrix* MatrixSubstract(matrix* A, matrix* B)
{
    matrix* M = CreateEmptyMatrix(A->Columns, A->Rows);
    for(int i = 0; i < M->Columns*M->Rows; i++)
    {
        *(M->Digits + i) = *(A->Digits + i) - *(B->Digits + i);
    }
    return M;
}

matrix* MatrixMultiply(matrix* A, matrix* B)
{
    matrix* M = CreateEmptyMatrix(A->Rows, B->Columns);
    for(int i = 0; i < B->Columns; i++)
    {
        for(int j = 0; j < A->Rows; j++)
        {
            for(int k = 0; k < B->Rows; k++)
            {
                *(M->Digits + i*(M->Columns) + j) += *(A->Digits + i*(A->Columns)+k) * *(B->Digits + k*(B->Columns)+j);    //i*nColumns+j is location of element M(i,j)
            }
        }
    }
    return M;
}

matrix* Transpose(matrix* M)
{
    matrix* T = CreateEmptyMatrix(M->Columns, M->Rows);
    for(int i = 0; i < T->Columns; i++)
    {
        for(int j = 0; j < T->Rows; j++)
        {
            *(T->Digits + j*T->Columns+i) = *(M->Digits + i*T->Rows+j);
        }
    }
    return T;
}

void FreeMatrix(matrix* Matrix)
{
    free(Matrix->Digits);
    free(Matrix);
}

void PrintMatrix(matrix* M)
{
    for(int i = 0; i < M->Columns*M->Rows; i++)
    {
        printf("%10.2f ", *(M->Digits + i));
        if((i+1)%M->Columns == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
