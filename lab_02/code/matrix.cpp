#include "matrix.h"

Matrix::Matrix(vector<vector<int>> tempArray, int tempRows, int tempColumns):
    array(tempArray), rows(tempRows), columns(tempColumns)
{

}

Matrix::Matrix(int tempRows, int tempColumns)
{
    

}

int Matrix::inputMatrix()
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
    array.resize(rows);

    cout << "Введите элементы матрицы построчно:\n";

    for (int i = 0; i < rows; i++)
    {
        array[i].resize(columns);
        for (int j = 0; j < columns; j++)
            cin >> array[i][j];
    }

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