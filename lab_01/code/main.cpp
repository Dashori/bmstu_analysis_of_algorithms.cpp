#include "algorithm.h"
#include "time.h"

#ifdef TEST
#define REPEAT 100
void testing();
#endif

int main()
{
    #ifdef TEST
    testing();
    return 0;
    #endif

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


#ifdef TEST
// a.out >> result.txt
// python3 result_graph.py

const int MAX_SIZE = 26;
 
string createString(int n)
{
    char letters[MAX_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
    'r','s','t','u','v','w','x',
    'y','z'};

    string result = "";

    for (int i = 0; i < n; i++) 
    result += letters[rand() % MAX_SIZE];

    return result;
}

void testing()
{
    distanceSolver test;

    uint64_t start, end;

    srand(time(NULL));

    int constN = 1;

    for (int i = 1; i <= 100; i += constN)
    {
        if (i == 20)
            constN = 10;

        int t1 = 0, t2 = 0, t3 = 0, t4 = 0;

        for (int j = 0; j < REPEAT; j++)
        {
            string first = createString(i);
            string second = createString(i);

            test.setStrings(first, second);

            start = tick();
            test.iterativeLevenshtein();
            end = tick();

            t1 += end - start;

            start = tick();
            test.iterativeDamerauLevenshtein();
            end = tick();

            t2 += end - start;

            start = tick();
            test.recursiveCacheDamerauLevenshtein();
            end = tick();

            t3 += end - start;

            if (i < 10)
            {
                start = tick();
                test.recursiveDamerauLevenshtein();
                end = tick();

                t4 += end - start;
            }

        }

        cout << i << " " << t1/REPEAT << " " << t2/REPEAT << " " << t3/REPEAT << " " << t4/REPEAT << "\n";
    }
}

#endif
