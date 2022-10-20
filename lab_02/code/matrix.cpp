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

int Random(int min, int max) 
{
    return min + rand() % (max - min);
}

void Matrix::fillRandom()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            array[i][j] = Random(-1000, 1000);
    }

}

int Matrix::inputSizes()
{
    cout << "Введите количество строк: ";

    if (scanf("%d", &rows) != 1 || rows < 1)
    {
        cout << "Количество строк должно быть натуральным числом";
        return 1;
    }

    cout << "Введите количество столбцов: ";

    if (scanf("%d", &columns) != 1 || columns < 1)
    {
        cout << "Количество столбцов должно быть натуральным числом";
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
    cout << "Введите элементы матрицы:" << endl;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (scanf("%d", &array[i][j]) != 1)
            {
                cout << "Неверный элемент матрицы." << endl;
                return 1;
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