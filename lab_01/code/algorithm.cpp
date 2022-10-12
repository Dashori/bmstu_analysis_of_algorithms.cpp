#include "algorithm.h"

void distanceSolver::inputStrings()
{
    cout << "Input first string: ";
    cin >> firstString;

    cout << "Input secong string: ";
    cin >> secondString;
}

void distanceSolver::setStrings(string first, string second)
{
    firstString = first;
    secondString = second;
}

void distanceSolver::allocateMatrix()
{
    row = firstString.length() + 1;
    column = secondString.length() + 1;

    matrix = new int *[row];

    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];
}

void distanceSolver::printMatrix()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << matrix[i][j] << " ";
        
        cout << " \n"; 
    }
}

//
// Нерекурсивный метод поиска Левенштейна = итерационный 
//

void distanceSolver::fillMatrixLevenshtein()
{
    for (int i = 0; i < row; i++)
        matrix[i][0] = i;

    for (int i = 0; i < column; i++)
        matrix[0][i] = i;

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < column; j++)
        {
            if (firstString[i - 1] == secondString[j - 1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]);
        }
    }
}

int distanceSolver::iterativeLevenshtein()
{
    allocateMatrix();
    fillMatrixLevenshtein();

    return matrix[row - 1][column - 1];
}

int distanceSolver::checkAdjacentSymb(int firstIndex, int secondIndex)
{
    if (firstIndex > 1 && secondIndex > 1)
        if (firstString[firstIndex - 1] == secondString[secondIndex - 2] &&
            firstString[firstIndex - 2] == secondString[secondIndex - 1])

            return 1;

    return 0;
}

//
// Нерекурсивный метод поиска Дамерау-Левенштейна = итерационный 
//

void distanceSolver::fillMatrixDamerauLevenshtein()
{
    for (int i = 0; i < row; i++)
        matrix[i][0] = i;

    for (int i = 0; i < column; i++)
        matrix[0][i] = i;

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < column; j++)
        {
            int matchFlag = (firstString[i - 1] == secondString[j - 1]) ? 0 : 1; 

            matrix[i][j] = min(min(matrix[i-1][j] + 1, matrix[i][j-1] + 1), matrix[i-1][j-1] + matchFlag);

            if (checkAdjacentSymb(i, j))
                matrix[i][j] = min(matrix[i][j], matrix[i - 2][j - 2] + 1);
 
        }
    }

}

int distanceSolver::iterativeDamerauLevenshtein()
{
    allocateMatrix();
    fillMatrixDamerauLevenshtein();

    return matrix[row - 1][column - 1];
}

// 
// рекурсивный метод поиска Дамерау-Левенштейна
//

int distanceSolver::recursive(int firstLen, int secondLen)
{
    if (firstLen == 0 && secondLen == 0)
        return 0;

    if (firstLen == 0)
        return secondLen;

    if (secondLen == 0)
        return firstLen;

    int adjacentEdit = INT_MAX;

    if (checkAdjacentSymb(firstLen, secondLen))
        adjacentEdit = recursive(firstLen - 2, secondLen - 2) + 1;

    int matchFlag = (firstString[firstLen - 1] == secondString[secondLen - 1]) ? 0 : 1; 

    return min(min(recursive(firstLen - 1, secondLen) + 1, 
                recursive(firstLen - 1, secondLen - 1) + matchFlag),
                min(recursive(firstLen, secondLen - 1) + 1, adjacentEdit));
}

int distanceSolver::recursiveDamerauLevenshtein()
{
    return recursive(firstString.length(), secondString.length());
}

//
// рекурсивный с кешированием метод поиска Дамерау-Левенштейна
//

void distanceSolver::allocateCache()
{
    cache = new int *[row];

    for (int i = 0; i < row; i++)
    {
        cache[i] = new int[column];

        for (int j = 0; j < column; j++)
            cache[i][j] = INT_MAX;
    }

    for (int i = 0; i < row; i++)
        cache[i][0] = i;

    for (int i = 0; i < column; i++)
        cache[0][i] = i;

}

int distanceSolver::recursiveCache(int firstLen, int secondLen)
{
    if (cache[firstLen][secondLen] != INT_MAX)
        return cache[firstLen][secondLen];

    int matchFlag = (firstString[firstLen - 1] == secondString[secondLen - 1]) ? 0 : 1; 

    cache[firstLen][secondLen] = min(min(recursiveCache(firstLen - 1, secondLen) + 1, 
                recursiveCache(firstLen - 1, secondLen - 1) + matchFlag),
                recursiveCache(firstLen, secondLen - 1) + 1);

    if (checkAdjacentSymb(firstLen, secondLen))
            cache[firstLen][secondLen] = min(cache[firstLen][secondLen], 
                                             recursiveCache(firstLen - 2, secondLen - 2) + 1);
        
    return cache[firstLen][secondLen];
}

int distanceSolver::recursiveCacheDamerauLevenshtein()
{
    allocateCache();

    return recursiveCache(firstString.length(), secondString.length());
}

