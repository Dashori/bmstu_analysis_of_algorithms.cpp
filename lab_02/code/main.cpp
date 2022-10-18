#include "matrix.h"

using namespace std;

int main()
{
    Matrix first;
    Matrix second;

    cout << "Ввод первой матрицы.\n";
    first.inputMatrix();
    cout << "Ввод второй матрицы.\n";
    second.inputMatrix();

    first.printMatrix();
    second.printMatrix();

    return 0;
}