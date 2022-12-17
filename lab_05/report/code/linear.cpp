void linearGenerate(vector<shared_ptr<Card> > &cards,
                    ofstream &fout)
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
        
        result = chrono::duration_cast<chrono::nanoseconds>
                (end - start).count();
        printf("Заявка: %d  Этап: 1  Начало: %g  Конец: %g\n",
        i + 1, cur_time, cur_time + result);
        cur_time += result;

        tempCard = q2.front();
        start = high_resolution_clock::now();
        tempCard->generateCard();
        end = high_resolution_clock::now();
        
        q3.push(tempCard);
        q2.pop();

        result =
        chrono::duration_cast<chrono::nanoseconds>
        (end - start).count();
        printf("Заявка: %d  Этап: 2  Начало: %g  Конец: %g\n",
        i + 1, cur_time, cur_time + result);
        cur_time += result;

        tempCard = q3.front();
        start = high_resolution_clock::now();
        tempCard->dumpFile(fout);
        end = high_resolution_clock::now();

        q3.pop();

        result = (chrono::duration_cast<chrono::nanoseconds>
        (end - start).count());
        printf("Заявка: %d  Этап: 3  Начало: %g  Конец: %g\n",
        i + 1, cur_time, cur_time + result);
        cur_time += result;
    }
}
