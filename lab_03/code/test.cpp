#include <algorithm>
#include <iterator>
#include <cstring>
#include <cmath>
#include <chrono>

#include "array.h"
#include "sorting.h"

#include <iostream>
#include <fstream>

#define REPEAT 2000

using namespace std::chrono;

void testing();

int main()
{
    testing();

    return 0;
}

// Возвращает псевдослучайное число из диапазона [min, max)
int Random(int min, int max) 
{
  return min + rand() % (max - min);
}

string createString(int n)
{
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
    'r','s','t','u','v','w','x',
    'y','z'};

    string result = "";

    for (int i = 0; i < n; i++) 
        result += letters[rand() % 26];

    return result;
}


void testing()
{   
    ofstream out("resultDegree.txt");
    int constMy = 1;

    for (int i = 1; i <= 66000; i*=2)
    {
        auto start = high_resolution_clock::now();
        auto res1 = duration_cast<microseconds>(start - start);
        auto res2 = duration_cast<microseconds>(start - start);
        auto res3 = duration_cast<microseconds>(start - start);

        for (int j = 0; j < REPEAT; j++)
        {
            int *array = new int[i];
            int *array1 = new int[i];
            int *array2 = new int[i];
            int *buffer = new int[i];

            for (int k = 0; k < i; k++)
            {
                int num = Random(-INT_MAX, INT_MAX);

                array[k] = num;
                array1[k] = num;
                array2[k] = num;
            }

            auto start = high_resolution_clock::now();
            mergeSort(array2, buffer, 0, i - 1);
            auto end = high_resolution_clock::now();
            res1 += duration_cast<microseconds>(end - start);

            start = high_resolution_clock::now();
            countingSort(array1, i);
            end = high_resolution_clock::now();
            res2 += duration_cast<microseconds>(end - start);

            int size = i;

            start = high_resolution_clock::now();

            if ((size & (size - 1)) != 0)
            {
                int newSize = log2(size) + 1;
                newSize = pow(2, newSize);

                int *newArray = new int[newSize];

                for (int i = 0; i < newSize; i++)
                {
                    if (i < size)
                        newArray[i] = array[i];
                    else
                        newArray[i] = INT_MAX;
                }

                bitonicSort(newArray, 0, newSize, 1);
            }
            else
            {
                bitonicSort(array, 0, size, 1);
            }

            end = high_resolution_clock::now();
            res3 += duration_cast<microseconds>(end - start);


            delete[] array;
            delete[] array1;
            delete[] array2;
        }

        out << i << " " << res1.count()/REPEAT << " " << res2.count()/REPEAT << " " << res3.count()/REPEAT << "\n" << std::flush;

    }
}


// #endif