#include "matrix.h"
#include "multiplicationMatrix.h"

#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

#define REPEAT 200 

int main()
{
    ofstream out("result.txt");
    int myConst = 1;

    for (int i = 2; i <= 502; i += myConst)
    {
        if (i == 102)
            myConst = 100;

        auto start = steady_clock::now();
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

            start = steady_clock::now();
            Matrix a  = temp.standartMultiplication();
            auto end = steady_clock::now();
            auto elapsed = duration_cast<microseconds>(end - start);
            res1 += duration_cast<microseconds>(end - start);

            start = steady_clock::now();
            temp.grapeMultiplication();
            end = steady_clock::now();
            elapsed = duration_cast<microseconds>(end - start);
            res2 += duration_cast<microseconds>(end - start);

            start = steady_clock::now();
            temp.grapeMultiplicationPro();
            end = steady_clock::now();
            elapsed = duration_cast<microseconds>(end - start);
            res3 += duration_cast<microseconds>(end - start);
        }

        out << i << " " << res1.count()/REPEAT << " " << res2.count()/REPEAT << " " << res3.count()/REPEAT << " \n" << flush;
    }

    return 0;
}