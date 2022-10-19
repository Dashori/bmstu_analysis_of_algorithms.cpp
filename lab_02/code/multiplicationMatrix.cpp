#include "multiplicationMatrix.h"

MultiplicatoinMatrix::MultiplicatoinMatrix(Matrix tempFirstMatrix, Matrix tempSecondMatrix):
    firstMatrix(tempFirstMatrix), secondMatrix(tempSecondMatrix)
{

}

Matrix MultiplicatoinMatrix::standartMultiplication()
{
    auto first = firstMatrix.getArray();
    auto firstRows = firstMatrix.getRows();
    auto firstColumns = firstMatrix.getColumns();

    auto second = secondMatrix.getArray();
    auto secondRows = secondMatrix.getRows();
    auto secondColumns = secondMatrix.getColumns();

    vector<vector<int>> tempArray;  
    tempArray.resize(firstRows);

    for (int i = 0; i < firstRows; i++)
        tempArray[i].resize(secondColumns);    

    for (int i = 0; i < firstRows; i++)
    {   
        for (int j = 0; j < firstColumns; j++)
        {
            for (int k = 0; k < secondColumns; k++)
            {
                tempArray[i][k] += first[i][j] * second[j][k];   
            }
        }
    }

    Matrix resultMatrix(firstMatrix.getRows(), secondMatrix.getColumns(), tempArray);

    return resultMatrix;
}



Matrix MultiplicatoinMatrix::grapeMultiplication()
{
    auto first = firstMatrix.getArray();
    auto firstRows = firstMatrix.getRows();
    auto firstColumns = firstMatrix.getColumns();

    auto second = secondMatrix.getArray();
    auto secondRows = secondMatrix.getRows();
    auto secondColumns = secondMatrix.getColumns();

    vector<int> vectorH(firstRows, 0);
    vector<int> vectorV(secondColumns, 0);

    for (int i = 0; i < firstRows; i++)
    {
        for (int j = 0; j < firstColumns / 2; j++)
            vectorH[i] += first[i][2 * j] * first[i][2 * j + 1];
        cout << vectorH[i] << " ";
    }

    cout << " \n \n ";

    for (int i = 0; i < secondColumns; i++)
    {
        for (int j = 0; j < secondRows / 2; j++)
            vectorV[i] += second[2 * j][i] * second[2 * j + 1][i];
        cout << vectorV[i] << " ";
    }

    vector<vector<int>> tempArray;
    tempArray.resize(firstRows);

    for (int i = 0; i < firstRows; i++)
        tempArray[i].resize(secondColumns);      

    for (int i = 0; i < firstRows; i++)
    {
        for (int k = 0; k < secondColumns; k++)
        {
            tempArray[i][k] -= (vectorH[i] + vectorV[k]);

            for (int j = 0; j < firstColumns / 2; j++)
            {
                tempArray[i][k] += (first[i][2 * j] + second[2 * j + 1][k]) *
                (first[i][2 * j + 1] + second[2 * j][k]);
            }
        }
    }

    if (firstColumns % 2 == 1)
    {
        for (int i = 0; i < firstRows; i++)
        {
            for (int j = 0; j < secondColumns; j++)
                tempArray[i][j] += first[i][firstColumns - 1] * second[secondRows - 1][j];
        }
    }

    Matrix resultMatrix(firstMatrix.getRows(), secondMatrix.getColumns(), tempArray);

    return resultMatrix;

}