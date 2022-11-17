#include "graph.h"


int main()
{
    Graph testGraph;
    testGraph.inputMatrix();
    cout << "Матрица смежности:\n";
    testGraph.printMatrix();

    Graph parallelGraph(testGraph);
    
    testGraph.drawGraph();

    parallelGraph.simpleFWA();
    cout << "Матрица кратчайших путей:\n";
    parallelGraph.printMatrix();

    // parallelGraph.drawGraph();

    return 0;
}