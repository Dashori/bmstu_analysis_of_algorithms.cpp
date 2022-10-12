#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <iostream>
#include <limits.h>
#include "time.h"

using namespace std;

class distanceSolver
{
    public:
        distanceSolver() = default;

        void inputStrings();
        void setStrings(string first, string second);

        void allocateMatrix();
        void printMatrix();
        
        int checkAdjacentSymb(int firstIndex, int secondIndex);
        
        // Нерекурсивный метод поиска Левенштейна = итерационный 
        int iterativeLevenshtein();
        void fillMatrixLevenshtein();

        // Нерекурсивный метод поиска Дамерау-Левенштейна = итерационный 
        int iterativeDamerauLevenshtein();
        void fillMatrixDamerauLevenshtein();

        // рекурсивный метод поиска Дамерау-Левенштейна
        int recursiveDamerauLevenshtein();
        int recursive(int firstLen, int secondLen);

        // рекурсивный с кешированием метод поиска Дамерау-Левенштейна
        int recursiveCacheDamerauLevenshtein();
        void allocateCache();
        int recursiveCache(int firstLen, int secondLen);

        void testing();

    private:
        string firstString;
        string secondString;

        int **matrix;
        int **cache;

        size_t row;
        size_t column;
};


#endif // ALGORITHM_H