void countingSort(int *array, int size)
{
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
