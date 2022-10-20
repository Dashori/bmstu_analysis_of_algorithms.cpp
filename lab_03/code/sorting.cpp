#include "sorting.h"

// merge

int *mergeSort(int *up, int *down, int left, int right)
{
    if (left == right)
    {
        down[left] = up[left];

        return down;
    }

    int middle = left + (right - left) / 2;

    int *lBuffer = mergeSort(up, down, left, middle);
    int *rBuffer = mergeSort(up, down, middle + 1, right);

    int *target;

    if (lBuffer == up)
        target = down;
    else
        target = up;

    int lIndex = left, rIndex = middle + 1;

    for (int i = left; i <= right; i++)
    {
        if (lIndex <= middle && rIndex <= right)
        {
            if (lBuffer[lIndex] < rBuffer[rIndex])
                target[i] = lBuffer[lIndex++];
            else
                target[i] = rBuffer[rIndex++];
        }
        else if (lIndex <= middle)
        {
            target[i] = lBuffer[lIndex++];
        }
        else
        {
            target[i] = rBuffer[rIndex++];
        }
    }

    return target;
}

// counting

void countingSort(int *array, int size)
{
    // int minEl = *min_element(array , array + size);
    // int maxEl = *max_element(array, array + size);

    int minEl = array[0];
    int maxEl = array[0];

    for (int i = 0; i < size; i++)
        if (array[i] > maxEl)
            maxEl = array[i];
    
    for (int i = 0; i < size; i++)
        if (array[i] < minEl)
            minEl = array[i];
    

    int newSize = maxEl - minEl + 1;
    int *newArray = new int[newSize]();

    for (int i = 0; i < size; i++)
        newArray[array[i] - minEl]++;

    int index = 0;

    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newArray[i]; j++)
            array[index++] = i + minEl;

    delete[] newArray;
}

// bitonic

void bitonicMerge(int *array, int start, int end, int flag)
{
    if (end > 1)
    {
        int middle = end / 2;

        for (int i = start; i < start + middle; i++)
            if (flag == (array[i] > array[i + middle]))
                swap(array[i], array[i + middle]);

        bitonicMerge(array, start, middle, flag);
        bitonicMerge(array, start + middle, middle, flag);
    }
}

void bitonicSort(int *array, int start, int end, int flag)
{
    if (end > 1)
    {
        int middle = end / 2;

        bitonicSort(array, start, middle, 0);
        bitonicSort(array, start + middle, middle, 1);
        
        bitonicMerge(array, start, end, flag);
    }
}
