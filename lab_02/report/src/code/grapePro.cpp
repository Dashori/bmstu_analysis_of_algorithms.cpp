
Matrix MultiplicatoinMatrix::winogradMultiplicationPro()
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

    int flag =  0;

    if (firstColumns % 2 == 1)
        flag = 1;    

    for (int i = 0; i < firstRows; i++)
        for (int k = 0; k < secondColumns; k++)
        {
            if (flag)
                tempArray[i][k] += first[i][firstColumns - 1] * second[secondRows - 1][k];
            tempArray[i][k] -= (vectorH[i] + vectorV[k]);

            for (int j = 0; j < firstColumns / 2; j++)
                tempArray[i][k] += (first[i][j << 1] + second[(j << 1) + 1][k]) *
                (first[i][(j << 1) + 1] + second[j << 1][k]);
        }
    
    Matrix resultMatrix(firstMatrix.getRows(), secondMatrix.getColumns(), tempArray);

    return resultMatrix;
}