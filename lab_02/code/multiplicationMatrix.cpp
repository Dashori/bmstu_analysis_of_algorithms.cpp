#include "multiplicationMatrix.h"

MultiplicatoinMatrix::MultiplicatoinMatrix(Matrix tempFirstMatrix, Matrix tempSecondMatrix):
    firstMatrix(tempFirstMatrix), secondMatrix(tempSecondMatrix)
{
    first = firstMatrix.getArray();
    firstRows = firstMatrix.getRows();
    firstColumns = firstMatrix.getColumns();

    second = secondMatrix.getArray();
    secondRows = secondMatrix.getRows();
    secondColumns = secondMatrix.getColumns();
}

Matrix MultiplicatoinMatrix::standartMultiplication()
{
    vector<vector<int>> tempArray;  
    tempArray.resize(firstRows);

    for (int i = 0; i < firstRows; i++)
        tempArray[i].resize(secondColumns);    

    for (int i = 0; i < firstRows; i++)
        for (int j = 0; j < firstColumns; j++)
            for (int k = 0; k < secondColumns; k++)
                tempArray[i][k] = tempArray[i][k] + first[i][j] * second[j][k];   

    Matrix resultMatrix(firstMatrix.getRows(), secondMatrix.getColumns(), tempArray);

    return resultMatrix;
}


Matrix MultiplicatoinMatrix::grapeMultiplication()
{
    vector<int> vectorH(firstRows, 0);
    vector<int> vectorV(secondColumns, 0);

    for (int i = 0; i < firstRows; i++)
        for (int j = 0; j < firstColumns / 2; j++)
            vectorH[i] = vectorH[i] + first[i][2 * j] * first[i][2 * j + 1];

    for (int i = 0; i < secondColumns; i++)
        for (int j = 0; j < secondRows / 2; j++)
            vectorV[i] = vectorV[i] + second[2 * j][i] * second[2 * j + 1][i];

    vector<vector<int>> tempArray;
    tempArray.resize(firstRows);

    for (int i = 0; i < firstRows; i++)
        tempArray[i].resize(secondColumns);      

    for (int i = 0; i < firstRows; i++)
        for (int k = 0; k < secondColumns; k++)
        {
            tempArray[i][k] = tempArray[i][k] - vectorH[i] - vectorV[k];

            for (int j = 0; j < firstColumns / 2; j++)
                tempArray[i][k] = tempArray[i][k] + (first[i][2 * j] + second[2 * j + 1][k]) *
                (first[i][2 * j + 1] + second[2 * j][k]);
        }


    if (firstColumns % 2 == 1)
        for (int i = 0; i < firstRows; i++)
            for (int j = 0; j < secondColumns; j++)
                tempArray[i][j] = tempArray[i][j] + first[i][firstColumns - 1] * second[secondRows - 1][j];

    Matrix resultMatrix(firstMatrix.getRows(), secondMatrix.getColumns(), tempArray);

    return resultMatrix;
}


Matrix MultiplicatoinMatrix::grapeMultiplicationPro()
{
    vector<int> vectorH(firstRows, 0);
    vector<int> vectorV(secondColumns, 0);

    for (int i = 0; i < firstRows; i++)
        for (int j = 0; j < firstColumns / 2; j++)
            vectorH[i] += first[i][j << 1] * first[i][(j << 1) + 1];

    for (int i = 0; i < secondColumns; i++)
        for (int j = 0; j < secondRows / 2; j++)
            vectorV[i] += second[j << 1][i] * second[(j << 1) + 1][i];

    vector<vector<int>> tempArray;
    tempArray.resize(firstRows);

    for (int i = 0; i < firstRows; i++)
        tempArray[i].resize(secondColumns);      

    for (int i = 0; i < firstRows; i++)
        for (int k = 0; k < secondColumns; k++)
        {
            tempArray[i][k] -= (vectorH[i] + vectorV[k]);

            for (int j = 0; j < firstColumns / 2; j++)
                tempArray[i][k] += (first[i][j << 1] + second[(j << 1) + 1][k]) *
                (first[i][(j << 1) + 1] + second[j << 1][k]);
        }

    if (firstColumns % 2 == 1)
        for (int i = 0; i < firstRows; i++)
            for (int j = 0; j < secondColumns; j++)
                tempArray[i][j] += first[i][firstColumns - 1] * second[secondRows - 1][j];

    Matrix resultMatrix(firstMatrix.getRows(), secondMatrix.getColumns(), tempArray);

    return resultMatrix;
}

Matrix MultiplicatoinMatrix::grapeMultiplicationPro2()
{
    vector<int> vectorH(firstRows, 0);
    vector<int> vectorV(secondColumns, 0);

    for (int i = 0; i < firstRows; i++)
        for (int j = 0; j < firstColumns >> 1; j++)
            vectorH[i] += first[i][j << 1] * first[i][(j << 1) + 1];

    for (int i = 0; i < secondColumns; i++)
        for (int j = 0; j < secondRows >> 1; j++)
            vectorV[i] += second[j << 1][i] * second[(j << 1) + 1][i];

    vector<vector<int>> tempArray;
    tempArray.resize(firstRows);

    for (int i = 0; i < firstRows; i++)
        tempArray[i].resize(secondColumns);     

    int flag =  0;

    if (firstColumns % 2 == 1)
        flag = 1; 
        
    for (int i = 0; i < firstRows; i++)
        for (int k = 0; k < secondColumns; k++)
        {
            tempArray[i][k] -= (vectorH[i] + vectorV[k]);
            
            if (flag)
                tempArray[i][k] += first[i][firstColumns - 1] * second[secondRows - 1][k];

            for (int j = 0; j < firstColumns >> 1; j++)
                tempArray[i][k] += (first[i][j << 1] + second[(j << 1) + 1][k]) *
                (first[i][(j << 1) + 1] + second[j << 1][k]);
        }

    Matrix resultMatrix(firstMatrix.getRows(), secondMatrix.getColumns(), tempArray);

    return resultMatrix;
}