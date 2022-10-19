#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "matrix.h"

class MultiplicatoinMatrix
{
    public:
        MultiplicatoinMatrix() = default;
        MultiplicatoinMatrix(Matrix tempFirstMatrix, Matrix tempSecondMatrix);

        Matrix standartMultiplication();
        Matrix grapeMultiplication(); // оригинально я алгоритм винограда назвала да
        Matrix grapeMultiplicationPro();

    private:
        Matrix firstMatrix;
        Matrix secondMatrix;

        vector<vector<int>> first;
        int firstRows;
        int firstColumns;

        vector<vector<int>> second; 
        int secondRows;
        int secondColumns;
};  


#endif //MULTIPLICATION_H