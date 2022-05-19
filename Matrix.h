#ifndef Matrix_H
#define Matrix_H

typedef struct
{
    int Rows;
    int Columns;
    double* Digits;
}matrix;

matrix* CreateEmptyMatrix(int nRows, int nColumns);
matrix* CreateMatrixFromString(int nRows, int nColumns, char* Str);
matrix* CreateRandomisedMatrix(int nRows, int nColumns, int MaxValue);
void FillMatrix(matrix* M, double FillValue);

double MatrixGetValue(matrix* M, int Row, int Column);
void MatrixSetValue(matrix* M, int Row, int Column, double Value);

void FreeMatrix(matrix* Matrix);
void PrintMatrix(matrix* Matrix);

matrix* Transpose(matrix* M);
matrix* MatrixAdd(matrix* A, matrix* B);
matrix* MatrixSubstract(matrix* A, matrix* B);
matrix* MatrixMultiply(matrix* A, matrix* B);


#endif
