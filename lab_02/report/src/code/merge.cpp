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
            target[i] = lBuffer[lIndex++];
        else
            target[i] = rBuffer[rIndex++];
    }

    return target;
}
