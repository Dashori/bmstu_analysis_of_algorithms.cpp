#include "matrix.h"
#include "multiplicationMatrix.h"

using namespace std;

int inputMatrix(Matrix &tempMatrix)
{
    if (tempMatrix.inputSizes())
        return 1;

    if (tempMatrix.allocateMatrix())
        return 1;

    if (tempMatrix.fillMatrix())
    {
        cout << "Неверный элемент матрицы.\n";
        return 1;
    }

    return 0;
}

int main()
{
    setbuf(stdin, NULL);
    Matrix first;
    Matrix second;

    cout << "Ввод первой матрицы.\n";

    if (inputMatrix(first))
        return 1;

    cout << "Ввод второй матрицы.\n";

    if (inputMatrix(second))
        return 1;

    // first.printMatrix();
    // second.printMatrix();

    if (first.getColumns() != second.getRows())
    {
        cout << "Невозможно умножить матрицы.\n";
        cout << "Количество столбцов первой матрицы должно совпадать с количеством строк второй.\n";

        return 1;
    }

    MultiplicatoinMatrix temp(first, second);

    Matrix resultBasic = temp.standartMultiplication();
    Matrix resultGrape = temp.grapeMultiplication();

    cout << "\n\n\n";
    resultBasic.printMatrix();
    cout << " \n";
    resultGrape.printMatrix();

    return 0;
}