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

    auto start = steady_clock::now();
    Matrix resultBasic = temp.standartMultiplication();
    auto end = steady_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);

    cout << "Стандартное умножение.\nВремя: " << elapsed.count() << " (микросекунды)\n";
    cout << "Матрица:\n";
    resultBasic.printMatrix();

    start = steady_clock::now();
    Matrix resultGrape = temp.grapeMultiplication();
    end = steady_clock::now();
    elapsed = duration_cast<microseconds>(end - start);
    cout << "Алгоритм Винограда.\nВремя: " << elapsed.count() << " (микросекунды)\n";
    cout << "Матрица:\n";
    resultGrape.printMatrix();

    start = steady_clock::now();
    Matrix resultGrapePro = temp.grapeMultiplicationPro();
    end = steady_clock::now();
    elapsed = duration_cast<microseconds>(end - start);

    cout << "Оптимизированный алгоритм Винограда.\nВремя: " << elapsed.count() << " (микросекунды)\n";
    cout << "Матрица:\n";
    resultGrapePro.printMatrix();

    return 0;
}