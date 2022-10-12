int distanceSolver::recursive(int firstLen, int secondLen)
{
    if (firstLen == 0 && secondLen == 0)
        return 0;

    if (firstLen == 0)
        return secondLen;

    if (secondLen == 0)
        return firstLen;

    int matchFlag = (firstString[firstLen - 1] == secondString[secondLen - 1]) ? 0 : 1; 
    int adjacentEdit = INT_MAX;

    if (checkAdjacentSymb(firstLen, secondLen))
        adjacentEdit = recursive(firstLen - 2, secondLen - 2) + 1;

    return min(min(recursive(firstLen - 1, secondLen) + 1, 
                recursive(firstLen - 1, secondLen - 1) + matchFlag),
                min(recursive(firstLen, secondLen - 1) + 1, adjacentEdit));
}

int distanceSolver::recursiveDamerauLevenshtein()
{
    return recursive(firstString.length(), secondString.length());
}
