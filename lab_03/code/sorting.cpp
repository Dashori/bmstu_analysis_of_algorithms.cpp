#include "sorting.h"
#include "utils.h"

void merge(int *array, int indexStart, int middle, int indexEnd)
{
    int sizeArrayLeft = middle - indexStart + 1;
    int sizeArrayRight = indexEnd - middle;

    int *leftArray = new int[sizeArrayLeft];
    int *rightArray = new int[sizeArrayRight];

    for (int i = 0; i < sizeArrayLeft; i++)
        leftArray[i] = array[indexStart + i];

    for (int i = 0; i < sizeArrayRight; i++)
        rightArray[i] = array[middle + 1 + i];

    int indexArrayRight = 0;
    int indexArrayLeft = 0;
    int indexArrayRes = indexStart;

    while(indexArrayLeft < sizeArrayLeft && indexArrayRight < sizeArrayRight)
    {
        if (leftArray[indexArrayLeft] <= rightArray[indexArrayRight])
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

void mergeSort(int *array, int indexStart,  int indexEnd)
{
    if (indexStart >= indexEnd)
        return;

    int middle = indexStart + (indexEnd - indexStart) / 2;

    mergeSort(array, indexStart, middle);
    mergeSort(array, middle + 1, indexEnd);

    int sizeArrayLeft = middle - indexStart + 1;
    int sizeArrayRight = indexEnd - middle;

    int *leftArray = new int[sizeArrayLeft];
    int *rightArray = new int[sizeArrayRight];

    for (int i = 0; i < sizeArrayLeft; i++)
        leftArray[i] = array[indexStart + i];

    for (int i = 0; i < sizeArrayRight; i++)
        rightArray[i] = array[middle + 1 + i];

    int indexArrayRight = 0;
    int indexArrayLeft = 0;
    int indexArrayRes = indexStart;

    while(indexArrayLeft < sizeArrayLeft && indexArrayRight < sizeArrayRight)
    {
        if (leftArray[indexArrayLeft] <= rightArray[indexArrayRight])
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

    // merge(array, indexStart, middle, indexEnd);
}

int* mergeSort(int *up, int *down, int left, int right)
{
    if (left == right)
    {
        down[left] = up[left];

        return down;
    }

    int middle = left + (right - left) / 2;

    int *lBuff = mergeSort(up, down, left, middle);
    int *rBuff = mergeSort(up, down, middle + 1, right);

    int *target = lBuff;

    if (target == up)
        target = down;
    else
        target = up;

    int lCur = left, rCur = middle + 1;

    for (int i = left; i <= right; i++)
    {
        if (lCur <= middle && rCur <= right)
        {
            if (lBuff[lCur] < rBuff[rCur])
            {
                target[i] = lBuff[lCur];
                lCur++;
            }
            else
            {
                target[i] = rBuff[rCur];
                rCur++;
            }
        }
        else if (lCur <= middle)
        {
            target[i] = lBuff[lCur];
            lCur++;
        }
        else
        {
            target[i] = rBuff[rCur];
            rCur++;
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


void bitseqsort(int* l, int* r, bool inv) 
{
	if (r - l <= 1) return;

	int *m = l + (r - l) / 2;

	for (int *i = l, *j = m; i < m && j < r; i++, j++) 
    {
		if (inv ^ (*i > *j)) swap(*i, *j);
	}

	bitseqsort(l, m, inv);
	bitseqsort(m, r, inv);
}

void makebitonic(int* l, int* r) 
{
	if (r - l <= 1) return;
	int *m = l + (r - l) / 2;

	makebitonic(l, m);
	bitseqsort(l, m, 0);
	makebitonic(m, r);
	bitseqsort(m, r, 1);
}

void bitonicsort(int* l, int* r) 
{
	int n = 1;
	int inf = *max_element(l, r) + 1;

	while (n < r - l) n *= 2;
	int* a = new int[n];
	int cur = 0;

	for (int *i = l; i < r; i++)
		a[cur++] = *i;

	while (cur < n) a[cur++] = inf;

	makebitonic(a, a + n);
	bitseqsort(a, a + n, 0);
	cur = 0;
	for (int *i = l; i < r; i++)
		*i = a[cur++];
        
	delete a;
}



void bitonic_sort_iter(int *arr, int n)
{

    // https://en.wikipedia.org/wiki/Bitonic_sorter#/media/File:BitonicSort1.svg

    // printf("Sorting array with bitonic sort...\n\n");
    statistics_t ret = {0};
    // uint64_t start_time = microsSinceEpoch();

    // Let's make the array have 2^x elements
    int max_n = 1;

    do
        max_n *= 2;
    while(max_n < n);


    if(max_n != n)
        for(int i = n; i < max_n; i++)
            *(arr + i) = INT_MAX;

    // Divide the array into chunks of 'block' size
    for (int block = 2; block <= max_n; block *= 2)
    {
        // Determine the gap size, starting at block / 2
        for (int gap = block / 2; gap > 0; gap /= 2)
        {
            for (int i = 0; i < max_n; ++i)
            {

                int j = i ^ gap; //xor
                if (i < j)
                {
                    // Ascending sequence
                    if ( (i & block) != 0)
                    {
                        ret.comparisons++;
                        ret.array_accesses += 2;
                        if (*(arr + i) < * (arr + j))
                        {
                            ret.array_accesses += 4;
                            swap(arr + i, arr + j);
                        }
                    }
                    // Descending sequence
                    else
                    {
                        ret.comparisons++;
                        ret.array_accesses += 2;
                        if (*(arr + i) > *(arr + j))
                        {
                            ret.array_accesses += 4;
                            swap(arr + i, arr + j);
                        }
                    }
                }
            }
        }
    }


    // ret.time = microsSinceEpoch() - start_time;
    // return ret;
}


void _merge_sort(int *arr, int l, int r, statistics_t * ret);
void _merge(int *arr, int l, int m, int r, statistics_t * ret);

void merge_sort_iter(int *arr, int n)
{
	// printf("Sorting array with merge sort...\n\n");
    statistics_t ret = {0};
    // uint64_t start_t = microsSinceEpoch();
    _merge_sort(arr, 0, n - 1, &ret);
    // ret.time = microsSinceEpoch() - start_t;

    // return ret;
}

void _merge_sort( int *arr, int l, int r, statistics_t * ret)
{
    if (r > l)
    {
        int m = (l + r) / 2;

        // Divide and conquer!
        _merge_sort(arr, l, m, ret);
        _merge_sort(arr, m + 1, r, ret);
        _merge(arr, l, m, r, ret);
    }

}

void _merge(int *arr, int l, int m, int r, statistics_t * ret)
{
	// Create temporary arrays
    int left_arr [m + 1 - l] = {0};
    int right_arr [r - m] = {0};

    // Fill them
    for (int i = 0; i < m + 1 - l; i++)
    {
        left_arr[i] = *(arr + l + i);
        ret->array_accesses++;
    }
    for (int i = 0; i < r - m; i++)
    {
        right_arr[i] = *(arr + m + 1 + i);
        ret->array_accesses++;
    }

    // Merge the two arrays sorted from low to high
    int i = 0;
    int j = 0;
    int k = l;
    while((i < m + 1 - l) && (j < r - m))
    {
        ret->comparisons++;
        if(left_arr[i] < right_arr[j])
        {
            *(arr + k) = left_arr[i];
            i++;
            ret->array_accesses++;
        }
        else
        {
            *(arr + k) = right_arr[j];
            j++;
            ret->array_accesses++;
        }
        k++;
    }

    // There is usually one number hanging, place it into the merged array as well
    while(i < m + 1 - l)
    {
        *(arr + k) = left_arr[i];
        i++;
        k++;
        ret->array_accesses++;
    }
    while(j < r - m)
    {
        *(arr + k) = right_arr[j];
        j++;
        k++;
        ret->array_accesses++;
    }

}