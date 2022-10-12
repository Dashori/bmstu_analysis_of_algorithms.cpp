void distanceSolver::fillMatrixDamerauLevenshtein()
{
    for (size_t i = 0; i < row; i++)
        matrix[i][0] = i;

    for (size_t i = 0; i < column; i++)
        matrix[0][i] = i;

    for (size_t i = 1; i < row; i++)
    {
        for (size_t j = 1; j < column; j++)
        {
            if (firstString[i - 1] == secondString[j - 1])
            {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j] = 1 + min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]);

                if (checkAdjacentSymb(i, j))
                    matrix[i][j] = min(matrix[i][j], matrix[i - 2][j - 2] + 1);
            }    
        }
    }

}

int distanceSolver::iterativeDamerauLevenshtein()
{
    allocateMatrix();
    fillMatrixDamerauLevenshtein();

    return matrix[row - 1][column - 1];
}