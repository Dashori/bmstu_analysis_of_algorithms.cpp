#include "graph.h"

Graph::Graph(const Graph &tempGraph)
{
    this->size = tempGraph.size;
    this->matrix = tempGraph.matrix;
}

int Graph::inputMatrix()
{
    cout << "Введите количество вершин графа:";
    cin >> size;

    matrix.resize(size + 1);

    for (int i = 0; i < size; i++)
    {
        matrix[i].resize(size + 1);
        cout << "Введите " << i + 1 << " строчку матрицы смежности:\n";

        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] < 0)
            {
                cout << "Неверный вес дуги\n";
                return 1;
            }
        }
    }

    return 0;
}

void Graph::printMatrix()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";

        cout << endl;    
    }
}

void Graph::drawGraph()
{
    ofstream graphFile;
    graphFile.open("graph.gv");
    graphFile << "digraph graph_pic {\n";

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (matrix[i][j] != 0)
                graphFile << i << " -> " << j <<  "[label=\"" << matrix[i][j] << "\"]\n";

    graphFile << "}\n";
    graphFile.close();

    system("dot -Tpng graph.gv > graph.png");
    system("xdg-open graph.png");
}

void Graph::simpleFWA()
{
    for (int i =  0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if (i != j && matrix[i][k] != 0 && matrix[k][j] != 0)
                {
                    if (matrix[i][j] == 0)
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    else
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

}