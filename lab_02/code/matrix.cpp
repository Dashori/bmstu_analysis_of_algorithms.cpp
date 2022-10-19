#include "matrix.h"

Matrix::Matrix(int tempRows, int tempColumns, vector<vector<int>> tempArray):
    rows(tempRows), columns(tempColumns), array(tempArray)
{

}

Matrix::Matrix(int tempRows, int tempColumns) :
    rows(tempRows), columns(tempColumns)
{
    array.resize(rows);

    for (int i = 0; i < rows; i++)
        array[i].resize(columns);    
}

int Matrix::inputSizes()
{
    cout << "Введите количество строк: ";
    cin >> rows;

    cout << "Введите количество столбцов: ";
    cin >> columns;

    if (rows < 1 || columns < 1)
    {
        cout << "Размеры матрицы должны быть натуральными\n";
        return 1;
    }

    return 0;
}

int Matrix::allocateMatrix()
{
    array.resize(rows);

    for (int i = 0; i < rows; i++)
        array[i].resize(columns);

    return 0;
}

int Matrix::fillMatrix()
{
    cout << "Введите элементы матрицы:\n";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (scanf("%d", &array[i][j]) != 1)
                return 1;
    
    return 0;    
}

void Matrix::printMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }

    cout << endl;
}