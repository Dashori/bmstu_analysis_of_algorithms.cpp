#include "graph.h"

#include <chrono>

using namespace std::chrono;

int main()
{
    Graph simpleGraph;

    simpleGraph.inputMatrix();
    cout << "Матрица смежности:\n";
    simpleGraph.printMatrix();

    auto start = high_resolution_clock::now();
    simpleGraph.simpleFWA();
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);  

    cout << "Матрица кратчайших путей:\n";
    simpleGraph.printMatrix();
    cout << "Время: " << elapsed.count() << " (микросекунды)\n";


    cout << "\nPARALLEL\n";
    Graph parallelGraph(simpleGraph);
    
    // simpleGraph.drawGraph();

    parallelGraph.inputThreads();

    start = high_resolution_clock::now();
    parallelGraph.doParallel();
    end = high_resolution_clock::now();
    elapsed = duration_cast<microseconds>(end - start);  
   
    // cout << "Матрица кратчайших путей:\n";
    // parallelGraph.printMatrix();
    cout << "Время: " << elapsed.count() << " (микросекунды)\n";



    // parallelGraph.drawGraph();

    return 0;
}