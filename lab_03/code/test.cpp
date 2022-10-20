#include <algorithm>
#include <iterator>
#include <cstring>
#include <cmath>

#include "array.h"
#include "sorting.h"
#include "time.h"

#include <iostream>
#include <fstream>

#define REPEAT 1000
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
    ofstream out("out.txt");
    int constMy = 1;

    for (int i = 2; i <= 30; i++)
    {
        long long int t1 = 0, t2 = 0, t3 = 0;

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

            uint64_t start, end;

            start = tick();
            mergeSort(array2, buffer, 0, i - 1);
            end = tick();
            t1 += end - start;

            start = tick();
            countingSort(array1, i);
            end = tick();
            t2 += end - start;

            int size = i;

            start = tick(); 

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

            end = tick();
            t3 += end - start;


            delete[] array;
            delete[] array1;
            delete[] array2;
        }

        out << i << " " << t1/REPEAT << " " << t2/REPEAT << " " << t3/REPEAT << "\n" << std::flush;

    }
}


// #endif