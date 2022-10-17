#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>
#include <iostream>
#include <algorithm>

#include "structs.h"

using namespace std;


// битонная подсчетом слиянием 


void mergeSort(myStruct *array, int indexStart, int indexEnd);
void bitonicSort(myStruct *array, int start, int end, int flag);
// int* merge_sort(int *up, int *down, int left, int right);
myStruct* merge_sort(myStruct *up, myStruct *down, int left, int right);

#endif