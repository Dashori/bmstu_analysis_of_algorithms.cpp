#include <algorithm>
#include <iterator>
#include <cstring>

#include "array.h"
#include "sorting.h"
#include "time.h"
// #include "structs.h"
// #include "sortMyStruct.h"

#define REPEAT 20
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
    int constMy = 1;
    for (int i = 2; i <= 1000; i++)
    {
        // if (i > 1000)
            // i += 100;
        int t1 = 0, t2 = 0, t3 = 0, t4 = 0;

        for (int j = 0; j < REPEAT; j++)
        {
            // myStruct *array = new myStruct[i];
            // // myStruct *array1 = new myStruct[i];
            // myStruct *array2 = new myStruct[i];
            // myStruct *buffer = new myStruct[i];
            int *array = new int[i];
            int *array1 = new int[i];
            int *array2 = new int[i];
            int *buffer = new int[i];

            int *array3 = new int[i];

            for (int k = 0; k < i; k++)
            {
                int num = Random(-100000, 100000);
                // string newString = createString(2);

                // myStruct temp = {num, newString};
                // myStruct temp1 = {num, newString};
                // myStruct temp2 = {num, newString};

                // array[k] = temp;
                // array1[k] = temp1;
                // array2[k] = temp2;

                array[k] = num;
                array1[k] = num;
                array2[k] = num;
                array3[k] = num;
            }

            uint64_t start, end;

            // start = tick();
            // // bitonicSort(array2, 0, i, 1);
            // // bitonicsort(NULL, array2);
            // bitonic_sort_iter(array3, i);
            // end = tick();
            // t3 += end - start;

            start = tick();
            // mergeSort(array, 0, i - 1);
            merge_sort_iter(array, i);
            end = tick();
            t1 += end - start;


            start = tick();
            countingSort(array1, i);
            end = tick();
            t2 += end - start;

            start = tick();
            merge_sort(array2, buffer, 0, i - 1);
            end = tick();
            t4 += end - start;


            delete[] array;
            delete[] array1;
            delete[] array2;
            delete[] array3;
        }

        cout << i << " " << t1/REPEAT << " " << t2/REPEAT << " " << t3/REPEAT  << " " << t4/REPEAT << "\n" << std::flush;
    }
}


// #endif