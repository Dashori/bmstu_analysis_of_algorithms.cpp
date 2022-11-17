#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>

#include <stdio.h>

using namespace std;

class Graph
{
    public:
        Graph() = default;
        Graph(const Graph &tempGraph);

        int inputMatrix();
        void printMatrix();
        void drawGraph();
        void simpleFWA();   // FWA = Floyd–Warshall algorithm
        void parallelFWA();
   
    private:
        int size;
        vector<vector<int>> matrix;
        // vector<vector<int>> matrixForSimple;

};


#endif // GRAPH_H