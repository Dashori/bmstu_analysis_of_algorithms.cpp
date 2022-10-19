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

    private:
        Matrix firstMatrix;
        Matrix secondMatrix;

};  


#endif //MULTIPLICATION_H