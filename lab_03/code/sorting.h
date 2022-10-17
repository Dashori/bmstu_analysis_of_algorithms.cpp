#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "limits.h"

using namespace std;


// битонная подсчетом слиянием 


void mergeSort(int *array, int indexStart, int indexEnd);
void countingSort(int *array, int size);
void bitonicSort(int *array, int start, int end, int flag);
int* mergeSort(int *up, int *down, int left, int right);
void bitonicsort(int* l, int* r);
void bitonic_sort_iter(int *arr, int n);

void merge_sort_iter(int *arr, int n);

#endif