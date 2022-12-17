#include "genCards.h"

double cur_time;

std::vector<double> cur_time1;
std::vector<double> cur_time2;
std::vector<double> cur_time3;


void linearGenerate(vector<shared_ptr<Card> > &cards, ofstream &fout)
{
    queue<shared_ptr<Card> > q1;
    queue<shared_ptr<Card> > q2;
    queue<shared_ptr<Card> > q3;
    cout << "\nПОСЛЕДОВАТЕЛЬНАЯ ОБРАБОТКА\n";

    for (int i = 0; i < cards.capacity(); i++)
        q1.push(cards[i]);

    cout << "\nЛОГ:\n";
    
    for (int i = 0; i < cards.capacity(); i++)
    {  
        double result = 0;

        shared_ptr<Card> tempCard = q1.front();

        auto start = high_resolution_clock::now();
        tempCard->generateOwner();
        auto end = high_resolution_clock::now();

        q2.push(tempCard);
        q1.pop();
        
        result = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
        printf("Заявка: %d  Этап: 1  Начало: %g  Конец: %g\n", i + 1, cur_time, cur_time + result);
        cur_time += result;

        tempCard = q2.front();
        start = high_resolution_clock::now();
        tempCard->generateCard();
        end = high_resolution_clock::now();
        
        q3.push(tempCard);
        q2.pop();

        result = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
        printf("Заявка: %d  Этап: 2  Начало: %g  Конец: %g\n", i + 1, cur_time, cur_time + result);
        cur_time += result;

        tempCard = q3.front();
        start = high_resolution_clock::now();
        tempCard->dumpFile(fout);
        end = high_resolution_clock::now();

        q3.pop();

        result = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
        printf("Заявка: %d  Этап: 3  Начало: %g  Конец: %g\n", i + 1, cur_time, cur_time + result);
        cur_time += result;
    }
}

void first(queue<shared_ptr<Card> > &q1, queue<shared_ptr<Card> > &q2)
{
    int i = 1;
    double result = 0, start_time;

    while (!q1.empty())
    {

        shared_ptr<Card> tempCard = q1.front();

        auto start = high_resolution_clock::now();
        tempCard->generateOwner();
        auto end = high_resolution_clock::now();
        result = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

        q2.push(tempCard);
        q1.pop();

        start_time = cur_time1[i - 1];
        cur_time1[i] = start_time + result;
        cur_time2[i - 1] = cur_time1[i];
        
        printf("Заявка: %d  Этап: 1  Начало: %g  Конец: %g\n", i, start_time, start_time + result);
        cur_time += result;

        i++;
    }
}


void second(queue<shared_ptr<Card> > &q1, queue<shared_ptr<Card> > &q2, queue<shared_ptr<Card> > &q3)
{
    int i = 1;
    double result = 0, start_time;
    
    do
    {
        if (!q2.empty())
        {
            shared_ptr<Card> tempCard = q2.front();

            auto start = high_resolution_clock::now();
            tempCard->generateCard();
            auto end = high_resolution_clock::now();
            result = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());


            q3.push(tempCard);
            q2.pop();

            start_time = cur_time2[i - 1];
            cur_time2[i] = start_time + result;
            cur_time3[i - 1] = cur_time2[i];

            printf("Заявка: %d  Этап: 2  Начало: %g  Конец: %g\n", i, start_time, start_time + result);

            i++;
        } 
    } while (!q2.empty()|| !q1.empty());   
}

void third(queue<shared_ptr<Card> > &q1, queue<shared_ptr<Card> > &q2, queue<shared_ptr<Card> > &q3, ofstream &fout)
{
    int i = 1;
    double result = 0, start_time;
    std::mutex m;
    do
    {
        if (!q3.empty() != 0)
        {
            shared_ptr<Card> tempCard = q3.front();

            auto start = high_resolution_clock::now();
            tempCard->dumpFile(fout);
            auto end = high_resolution_clock::now();
            result = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

            q3.pop();
            
            start_time = cur_time3[i - 1];
            cur_time3[i] = start_time + result;;

            printf("Заявка: %d  Этап: 3  Начало: %g  Конец: %g\n", i, start_time, start_time + result);

            i++;
        } 
    } while (!q3.empty() || !q2.empty()|| !q1.empty());   
}


void parallelGenerate(vector<shared_ptr<Card> > &cards, ofstream &fout)
{
    queue<shared_ptr<Card> > q1;
    queue<shared_ptr<Card> > q2;
    queue<shared_ptr<Card> > q3;
    cout << "\nПАРАЛЛЕЛЬНАЯ ОБРАБОТКА\n";

    for (int i = 0; i < cards.capacity(); i++)
        q1.push(cards[i]);

    cout << "\nЛОГ:\n";

    for (int i = 0; i < cards.capacity() + 1; i++)
    {
        cur_time1.push_back(0);
        cur_time2.push_back(0);
        cur_time3.push_back(0);
    }

    vector<thread> threads(3);

    threads[0] = thread(first, std::ref(q1), std::ref(q2));
    threads[1] = thread(second, std::ref(q1), std::ref(q2), std::ref(q3));
    threads[2] = thread(third, std::ref(q1), std::ref(q2), std::ref(q3), std::ref(fout));

    threads[0].join();
    threads[1].join();
    threads[2].join();
}
