#include <cstring>

#include "array.h"
#include "sorting.h"
#include "time.h"

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

    uint64_t start, end;

    

    cout << "\nСортировка слиянием:\n";
    start = tick();
    mergeSort(array, buffer, 0, size - 1);
    end = tick();
    cout << "Время: " << end - start << " (в тиках)\n";
    printArray(array, size);

    cout << "\nСортировка слиянием:\n";
    start = tick();
    mergeSort(array, 0, size - 1);
    end = tick();
    cout << "Время: " << end - start << " (в тиках)\n";
    printArray(array, size);

    cout << "\nСортировка посчетом:\n";
    start = tick();
    countingSort(array1, size);
    end = tick();
    cout << "Время: " << end - start << " (в тиках)\n";
    printArray(array1, size);
    
    // if (size & (size - 1) != 0 )
    // {
    //     cout << "Битонная сортировка может работать только с массивами,\n размеры которых являются степенью 2.\n";
    //     return 0;
    // }

    cout << "\nБитонная сортировка:\n";
    start = tick();
    bitonic_sort_iter(array2, size);
    // bitonicSort(array2, 0, size, 1);
    end = tick();
    cout << "Время: " << end - start << " (в тиках)\n";
    printArray(array2, size);

    delete[] array;
    delete[] array1;
    delete[] array2;

    return 0;
}

