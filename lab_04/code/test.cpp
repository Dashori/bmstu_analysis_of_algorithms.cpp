#include "graph.h"

#include <chrono>
#include <memory>
#include <fstream>

#define REPEAT 100

using namespace std;
using namespace std::chrono;


int main()
{
    ofstream out("result.txt");
    ofstream out4("result4.txt");
    
    int plus = 10;

    for (int size = 1; size <= 201; size += plus) 
    {   
        if (size == 51)
        {
            size = 50;
            plus = 50;
        }

        auto start = high_resolution_clock::now();
        auto end = high_resolution_clock::now();
        auto resultSimple = duration_cast<microseconds>(start - start);
        auto resultParallel = duration_cast<microseconds>(start - start);
        
        for (int i = 0; i < REPEAT; i++)
        {
            shared_ptr<Graph> temp ( new Graph(size));
            (*temp).setThreads(4);

            start = high_resolution_clock::now();
            (*temp).simpleFWA();
            end = high_resolution_clock::now();
            resultSimple += duration_cast<microseconds>(end - start);

            shared_ptr<Graph> tempParallel ( new Graph(*temp));
            
            start = high_resolution_clock::now();
            (*tempParallel).doParallel();
            end = high_resolution_clock::now();
            resultParallel += duration_cast<microseconds>(end - start);
        }

        out4 << size << " " <<  resultSimple.count() / REPEAT  << " " << resultParallel.count() / REPEAT << endl;
        
    }


    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto resultSimple = duration_cast<microseconds>(start - start);
    auto resultParallel = duration_cast<microseconds>(start - start);

    int size = 150;
    
    for (int thread = 1; thread <= 16; thread += 1)
    {   
        for (int i = 0; i < REPEAT; i++)
        {
            shared_ptr<Graph> temp ( new Graph(size));
            (*temp).setThreads(thread);

            start = high_resolution_clock::now();
            (*temp).simpleFWA();
            end = high_resolution_clock::now();
            resultSimple += duration_cast<microseconds>(end - start);

            shared_ptr<Graph> tempParallel ( new Graph(*temp));
            
            start = high_resolution_clock::now();
            (*tempParallel).doParallel();
            end = high_resolution_clock::now();
            resultParallel += duration_cast<microseconds>(end - start);
        }

        out << thread << " " << " "  <<  resultSimple.count() / REPEAT  << " " << resultParallel.count() / REPEAT << endl;
            
    }


    return 0;
}