#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "matrix.h"

class MultiplicatoinMatrix
{
    public:
        MultiplicatoinMatrix();
        MultiplicatoinMatrix(Matrix tempFirstMatrix, Matrix tempSecondMatrix);

        Matrix standartMultiplication();

    private:
        Matrix firstMatrix;
        Matrix seconfMatrix;

};  


#endif //MULTIPLICATION_H