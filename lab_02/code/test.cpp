#include "matrix.h"
#include "multiplicationMatrix.h"

#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    Matrix first;
    Matrix second;

    MultiplicatoinMatrix temp(first, second);

    auto start = steady_clock::now();
    Matrix resultBasic = temp.standartMultiplication();
    auto end = steady_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);

    return 0;
}