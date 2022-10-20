#include <cstring>
#include <cmath>
#include <chrono>

#include "array.h"
#include "sorting.h"
#include <climits>

using namespace std::chrono;

int main()
{
    int size;

    if (inputSize(size))
        return 1;

    int *array = new int[size];
    int *array1 = new int[size];
    int *array2 = new int[size];
    int *buffer = new int[size];

    inputArray(array, size);
    memcpy(array1, array, size * sizeof(int));
    memcpy(array2, array, size * sizeof(int));

    cout << "\nСортировка слиянием:\n";
    auto start = high_resolution_clock::now();
    array = mergeSort(array, buffer, 0, size - 1);
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);
    cout << "Время: " << elapsed.count() << " (микросекунды)\n";
    printArray(array, size);

    cout << "Сортировка подсчетом:\n";
    start = high_resolution_clock::now();
    countingSort(array1, size);
    end = high_resolution_clock::now();
    elapsed = duration_cast<microseconds>(end - start);
    cout << "Время: " << elapsed.count() << " (микросекунды)\n";
    printArray(array1, size);


    int newSize;
    
    if ((size & (size - 1)) != 0 )
    {
        newSize = log2(size) + 1;
        newSize = pow(2, newSize);

        int *newArray = new int[newSize];

        for (int i = 0; i < newSize; i++)
        {
            if (i < size)
                newArray[i] = array2[i];
            else
                newArray[i] = INT_MAX;
        }
        cout << "Битонная сортировка:\n";
        start = high_resolution_clock::now();
        bitonicSort(newArray, 0, newSize, 1);
        end = high_resolution_clock::now();
        elapsed = duration_cast<microseconds>(end - start);
        cout << "Время: " << elapsed.count() << " (микросекунды)\n";
        printArray(newArray, size);

        delete[] newArray;
    }
    else
    {
        cout << "Битонная сортировка:\n";
        start = high_resolution_clock::now();
        bitonicSort(array2, 0, size, 1);
        end = high_resolution_clock::now();
        elapsed = duration_cast<microseconds>(end - start);
        cout << "Время: " << elapsed.count() << " (микросекунды)\n";
        printArray(array2, size);
    }

    delete[] array;
    delete[] array1;
    delete[] array2;

    return 0;
}

