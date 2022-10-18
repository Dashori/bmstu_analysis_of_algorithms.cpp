#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    public:
        Matrix() = default;
        Matrix(vector<vector<int>> tempArray, int tempRows, int tempColumns);
        Matrix(int tempRows, int tempColumns);

        int getRows() { return rows; };
        int getColumns() { return columns; };
        

        int inputMatrix();
        void printMatrix();

    private:
        int rows;
        int columns;
        vector<vector<int>> array; 
};

#endif //MATRIX_H