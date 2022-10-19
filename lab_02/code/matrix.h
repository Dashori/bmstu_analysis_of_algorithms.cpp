#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    public:
        Matrix() = default;
        Matrix(int tempRows, int tempColumns);
        Matrix(int tempRows, int tempColumns, vector<vector<int>> tempArray);
        
        int inputSizes();
        int allocateMatrix();
        int fillMatrix();

        int getRows() { return rows; };
        int getColumns() { return columns; };
        vector<vector<int>> getArray() { return array; };

        void printMatrix();

    private:
        int rows;
        int columns;
        vector<vector<int>> array; 
};

#endif //MATRIX_H