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