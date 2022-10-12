

// 
// recursive Damerau -- Levenshtein without cache
//


//
// recursive Damerau -- Levenshtein with cache
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

    for (size_t i = 0; i < row; i++)
        cache[i][0] = i;

    for (size_t i = 0; i < column; i++)
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
