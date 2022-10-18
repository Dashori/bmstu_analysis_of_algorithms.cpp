#include "algorithm.h"
#include "time.h"

int main()
{
    distanceSolver test;

    test.inputStrings();
    uint64_t start, end;
    int n;

    cout << "\nIterative Levenshtein\n";
    start = tick();
    n = test.iterativeLevenshtein();
    end = tick();
    cout << "Matrix:\n";
    test.printMatrix();
    cout << "Result: " << n << endl;
    cout << "Time: " << end - start << " (ticks)\n\n";


    cout << "Iterative Damerau-Levenshtein" << endl;
    start = tick();
    n = test.iterativeDamerauLevenshtein();
    end = tick();
    cout << "Matrix:\n";
    test.printMatrix();
    cout << "Result: " << n << endl;
    cout << "Time: " << end - start << " (ticks)\n\n";


    cout << "Recursive Damerau-Levenshtein without cache\n";
    start = tick();
    n = test.recursiveDamerauLevenshtein();
    end = tick();
    cout << "Result: " << n << endl;
    cout << "Time: " << end - start << " (ticks)\n\n";

    cout << "Recursive Damerau-Levenshtein with cache\n";
    start = tick();
    n = test.recursiveCacheDamerauLevenshtein();
    end = tick();
    cout << "Result: " << n << endl;
    cout << "Time: " << end - start << " (ticks)\n";

    return 0;
}
