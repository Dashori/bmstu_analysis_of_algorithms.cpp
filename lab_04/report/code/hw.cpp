
void Graph::parallelWA(int index)
{                                       
    int step = size / countThreads;                                                     # 1                                                                 
    int start = index * step;                                                           # 2                                                   
                                                                                                                
    if (index + 1 == countThreads)                                                      # 3                                                         
    {                                                                                                                
        step += + (size - step * countThreads);                                         # 4                                                                       
    }                                                                                                                
                                                                                                                
    for (int k = start; k < start + step; k++)                                          # 5                                                                      
    {                                                                                                               
        for (int i = 0; i < size; i++)                                                  # 6                                                             
        {                                                                                                                
            for (int j = 0; j < size; j++)                                              # 7                                                                 
            {                                                                                                                
                if (i != j && matrix[i][k] != 0 && matrix[k][j] != 0)                   # 8                                                                                             
                {                                                                                                               
                    if (matrix[i][j] == 0)                                              # 9                                                                  
                        matrix[i][j] = matrix[i][k] + matrix[k][j];                     # 10                                                                                          
                    else                                                                # 11                                              
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);  # 12                                                                                                             
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
