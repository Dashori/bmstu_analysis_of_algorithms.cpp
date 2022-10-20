#include <cstring>
#include <cmath>

#include "array.h"
#include "sorting.h"
#include "time.h"
#include <climits>

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
    array = mergeSort(array, buffer, 0, size - 1);
    end = tick();
    cout << "Время: " << end - start << " (в тиках)\n";
    printArray(array, size);

    cout << "Сортировка посчетом:\n";
    start = tick();
    countingSort(array1, size);
    end = tick();
    cout << "Время: " << end - start << " (в тиках)\n";
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

        start = tick();
        bitonicSort(newArray, 0, newSize, 1);
        end = tick();
        cout << "Время: " << end - start << " (в тиках)\n";
        printArray(newArray, size);

        delete[] newArray;
    }
    else
    {
        
        bitonicSort(array2, 0, size, 1);
        end = tick();
        cout << "Время: " << end - start << " (в тиках)\n";
        printArray(array2, size);
    }

    delete[] array;
    delete[] array1;
    delete[] array2;

    return 0;
}

