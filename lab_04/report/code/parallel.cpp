
void Graph::parallelWA(int index)
{                                       
    int step = size / countThreads;                                                                                                                    
    int start = index * step;                                                                                                            
                                                                                            
    if (index + 1 == countThreads)                                                                                                             
    {                                                                                                           
        step += + (size - step * countThreads);                                                                                                              
    }                                                                                                           
                                                                                            
    for (int k = start; k < start + step; k++)                                                                                                              
    {                                                                                                          
        for (int i = 0; i < size; i++)                                                                                                             
        {                                                                                                           
            for (int j = 0; j < size; j++)                                                                                                             
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

void Graph::doParallel()
{
    std::vector<std::thread> threads(countThreads);

    for (int i = 0; i < countThreads; i++)
    {
        threads[i] = std::thread(&Graph::parallelWA, this, i);
    }

    for (int i = 0; i < countThreads; i++)
    {
        threads[i].join(); 
    }
}
