#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>
#include <iostream>
#include <algorithm>

#include "limits.h"

using namespace std;

int *mergeSort(int *up, int *down, int left, int right);
void countingSort(int *array, int size);
void bitonicSort(int *array, int start, int end, int flag);

#endif