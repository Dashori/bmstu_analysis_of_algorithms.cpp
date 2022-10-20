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
