#include "matrix.h"
#include "multiplicationMatrix.h"

#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

#define REPEAT 100 

int main()
{
    ofstream out("resultEven.txt");
    int myConst = 2;

    for (int i = 1; i <= 302; i += myConst)
    {
        if (i == 103)
            myConst = 100;

        auto start = high_resolution_clock::now();
        auto res1 = duration_cast<microseconds>(start - start);
        auto res2 = duration_cast<microseconds>(start - start);
        auto res3 = duration_cast<microseconds>(start - start);
        
        for (int r = 0; r < REPEAT; r++)
        {
            Matrix first(i, i);
            Matrix second(i, i);
            first.fillRandom();
            second.fillRandom();

            MultiplicatoinMatrix temp(first, second);

            start = high_resolution_clock::now();
            Matrix a  = temp.standartMultiplication();
            auto end = high_resolution_clock::now();
            // auto elapsed = duration_cast<microseconds>(end - start);
            res1 += duration_cast<microseconds>(end - start);

            start = high_resolution_clock::now();
            temp.grapeMultiplication();
            end = high_resolution_clock::now();
            // elapsed = duration_cast<microseconds>(end - start);
            res2 += duration_cast<microseconds>(end - start);

            start = high_resolution_clock::now();
            temp.grapeMultiplicationPro();
            end = high_resolution_clock::now();
            // elapsed = duration_cast<microseconds>(end - start);
            res3 += duration_cast<microseconds>(end - start);
        }

        out << i << " " << res1.count()/REPEAT << " " << res2.count()/REPEAT << " " << res3.count()/REPEAT << " \n" << flush;
    }

    return 0;
}