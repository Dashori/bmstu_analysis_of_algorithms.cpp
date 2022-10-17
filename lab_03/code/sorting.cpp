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

    int *lBuff = mergeSort(up, down, left, middle);
    int *rBuff = mergeSort(up, down, middle + 1, right);

    // int *target = lBuff;

    // if (target == up)
    //     target = down;
    // else
    //     target = up;
    int *target = lBuff == up ? down : up;

    int lIndex = left, rIndex = middle + 1;

    for (int i = left; i <= right; i++)
    {
        if (lIndex <= middle && rIndex <= right)
        {
            if (lBuff[lIndex] < rBuff[rIndex])
            {
                target[i] = lBuff[lIndex];
                lIndex++;
            }
            else
            {
                target[i] = rBuff[rIndex];
                rIndex++;
            }
        }
        else if (lIndex <= middle)
        {
            target[i] = lBuff[lIndex];
            lIndex++;
        }
        else
        {
            target[i] = rBuff[rIndex];
            rIndex++;
        }
    }

    return target;
}

// counting

void countingSort(int *array, int size)
{
    int minEl = *min_element(array , array + size);
    int maxEl = *max_element(array, array + size);

    if (minEl >= 0)
    {
        int newSize = maxEl + 1;

        int *newArray = new int[newSize]();

        for (int i = 0; i < size; i++)
            newArray[array[i]]++;

        int index = 0;

        for (int i = 0; i < newSize; i++)
            for (int j = 0; j < newArray[i]; j++)
                array[index++] = i;

        delete[] newArray;
        
        return;
    }

    int newSize = maxEl - minEl + 1;

    int *newArray = new int[newSize]();

    for (int i = 0; i < size; i++)
        newArray[array[i] - minEl]++;;

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
        int k = end / 2;

        for (int i = start; i < start + k; i++)
            if (flag == (array[i] > array[i + k]))
                swap(array[i], array[i + k]);

        bitonicMerge(array, start, k, flag);
        bitonicMerge(array, start + k, k, flag);
    }
}

void bitonicSort(int *array, int start, int end, int flag)
{
    if (end > 1)
    {
        int k = end / 2;

        bitonicSort(array, start, k, 0);
        bitonicSort(array, start + k, k, 1);
        
        bitonicMerge(array, start, end, flag);
    }
}
