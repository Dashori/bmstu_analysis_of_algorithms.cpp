#include "sortMyStruct.h"


void merge(myStruct *array, int indexStart, int middle, int indexEnd)
{
    int sizeArrayLeft = middle - indexStart + 1;
    int sizeArrayRight = indexEnd - middle;

    myStruct *leftArray = new myStruct[sizeArrayLeft];
    myStruct *rightArray = new myStruct[sizeArrayRight];

    for (int i = 0; i < sizeArrayLeft; i++)
        leftArray[i].num = array[indexStart + i].num;

    for (int i = 0; i < sizeArrayRight; i++)
        rightArray[i].num = array[middle + 1 + i].num;

    int indexArrayRight = 0;
    int indexArrayLeft = 0;
    int indexArrayRes = indexStart;

    while(indexArrayLeft < sizeArrayLeft && indexArrayRight < sizeArrayRight)
    {
        if (leftArray[indexArrayLeft].num <= rightArray[indexArrayRight].num)
            array[indexArrayRes++] = leftArray[indexArrayLeft++];
        else
            array[indexArrayRes++] = rightArray[indexArrayRight++];
    }

    while (indexArrayLeft < sizeArrayLeft)
        array[indexArrayRes++] = leftArray[indexArrayLeft++];

    while (indexArrayRight < sizeArrayRight)
        array[indexArrayRes++] = rightArray[indexArrayRight++];

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(myStruct *array, int indexStart,  int indexEnd)
{
    if (indexStart >= indexEnd)
        return;

    int middle = indexStart + (indexEnd - indexStart) / 2;

    mergeSort(array, indexStart, middle);
    mergeSort(array, middle + 1, indexEnd);

    merge(array, indexStart, middle, indexEnd);
}

myStruct* merge_sort(myStruct *up, myStruct *down, int left, int right)
{
    if (left == right)
    {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = left + (right - left) / 2;

    myStruct *l_buff = merge_sort(up, down, left, middle);
    myStruct *r_buff = merge_sort(up, down, middle + 1, right);

    myStruct *target = l_buff == up ? down : up;

    unsigned int l_cur = left, r_cur = middle + 1;
    for (unsigned int i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            if (l_buff[l_cur].num < r_buff[r_cur].num)
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}


// bitonic

void bitonicMerge(myStruct *array, int start, int end, int flag)
{
    if (end > 1)
    {
        int k = end / 2;

        for (int i = start; i < start + k; i++)
            if (flag == (array[i].num > array[i + k].num))
                swap(array[i], array[i + k]);

        bitonicMerge(array, start, k, flag);
        bitonicMerge(array, start + k, k, flag);
    }
}

void bitonicSort(myStruct *array, int start, int end, int flag)
{
    if (end > 1)
    {
        int k = end / 2;

        bitonicSort(array, start, k, 0);
        bitonicSort(array, start + k, k, 1);
        
        bitonicMerge(array, start, end, flag);
    }
}
