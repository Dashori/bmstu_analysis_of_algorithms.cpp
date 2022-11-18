#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <random>

#include <stdio.h>

using namespace std;

class Graph
{
    public:
        Graph() = default;
        Graph(int tempSize);
        Graph(const Graph &tempGraph);

        int inputMatrix();
        int inputThreads();
        void setThreads(int threadsTemp);
        void printMatrix();
        void drawGraph();
        void simpleFWA();   // FWA = Floyd–Warshall algorithm
        void parallelFWA(int index);
        void doParallel();
   
    private:
        int size;
        int countThreads = 4;
        vector<vector<int>> matrix;
};


#endif // GRAPH_H