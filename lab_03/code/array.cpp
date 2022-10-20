#include "array.h"

int inputSize(int &size)
{
    cout << "Введите размерность массива: ";

    cin >> size;

    if (size <= 0)
    {
        cout << "Неверные размер массива.";

        return 1;
    }

    return 0;
}

void inputArray(int *array, int size)
{   
    cout << "Введите массив: ";

    for (int i = 0; i < size; i++)
        cin >> array[i];
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << " \n\n";
}
