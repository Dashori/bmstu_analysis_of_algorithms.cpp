#include "matrix.h"
#include "multiplicationMatrix.h"

#include <chrono>

using namespace std;
using namespace std::chrono;

int inputMatrix(Matrix &tempMatrix)
{
    if (tempMatrix.inputSizes())
        return 1;

    if (tempMatrix.allocateMatrix())
        return 1;

    if (tempMatrix.fillMatrix())
        return 1;

    return 0;
}

int main()
{
    Matrix first;
    Matrix second;

    cout << "Ввод первой матрицы." << endl;

    if (inputMatrix(first))
        return 1;

    cout << "Ввод второй матрицы." << endl;

    if (inputMatrix(second))
        return 1;

    if (first.getColumns() != second.getRows())
    {
        cout << "Невозможно умножить матрицы." << endl;
        cout << "Количество столбцов первой матрицы должно совпадать с количеством строк второй." << endl;

        return 1;
    }

    MultiplicatoinMatrix temp(first, second);

    auto start = steady_clock::now();
    Matrix resultBasic = temp.standartMultiplication();
    auto end = steady_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);
    cout << "Стандартное умножение." << endl;
    cout << "Время: " << elapsed.count() << " (микросекунды)" << endl;
    cout << "Матрица:" << endl;
    resultBasic.printMatrix();

    start = steady_clock::now();
    Matrix resultGrape = temp.grapeMultiplication();
    end = steady_clock::now();
    elapsed = duration_cast<microseconds>(end - start);
    cout << "Алгоритм Винограда." << endl;
    cout << "Время: " << elapsed.count() << " (микросекунды)" << endl;
    cout << "Матрица:" << endl;
    resultGrape.printMatrix();

    start = steady_clock::now();
    Matrix resultGrapePro = temp.grapeMultiplicationPro();
    end = steady_clock::now();
    elapsed = duration_cast<microseconds>(end - start);
    cout << "Оптимизированный алгоритм Винограда." << endl;
    cout << "Время: " << elapsed.count() << " (микросекунды)" << endl;
    cout << "Матрица:" << endl;
    resultGrapePro.printMatrix();


    start = steady_clock::now();
    Matrix resultGrapePro2= temp.grapeMultiplicationPro2();
    end = steady_clock::now();
    elapsed = duration_cast<microseconds>(end - start);
    cout << "Оптимизированный дважды алгоритм Винограда." << endl;
    cout << "Время: " << elapsed.count() << " (микросекунды)" << endl;
    cout << "Матрица:" << endl;
    resultGrapePro2.printMatrix();

    return 0;
}