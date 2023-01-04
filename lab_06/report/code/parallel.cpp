void parallelGenerate(vector<shared_ptr<Card> > &cards,
                      ofstream &fout)
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
    threads[1] = thread(second, std::ref(q1), 
                        std::ref(q2), std::ref(q3));
    threads[2] = thread(third, std::ref(q1), std::ref(q2),
                        std::ref(q3), std::ref(fout));
    threads[0].join();
    threads[1].join();
    threads[2].join();
}
