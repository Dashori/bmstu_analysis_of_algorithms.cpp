#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <thread>

#include <stdio.h>

using namespace std;

class Graph
{
    public:
        Graph() = default;
        Graph(const Graph &tempGraph);

        int inputMatrix();
        int inputThreads();
        void printMatrix();
        void drawGraph();
        void simpleFWA();   // FWA = Floyd–Warshall algorithm
        void parallelFWA(int index);
        void doParallel();
   
    private:
        int size;
        int countThreads;
        vector<vector<int>> matrix;
};


#endif // GRAPH_H