#include <stdio.h>
#include <vector>

#include "card.h"
#include "genCards.h"

int main()
{
    int numbers;

    cout << "Введите количество карт для изготовления: ";

    if (scanf("%d", &numbers) != 1 || numbers < 1)
    {
        cout << "Ошибка при вводе количества карт.\n";
        return 1;
    }

    ofstream fout;
    ofstream pout;

    fout.open("result_linerial.csv");
    pout.open("result_parallel.csv");

    vector<shared_ptr<Card> > cards(numbers);
    vector<shared_ptr<Card> > cardsParallel(numbers);

    for (int i = 0; i < numbers; i++)
    {
        cards[i] = shared_ptr<Card>(new Card);
        cardsParallel[i] = shared_ptr<Card>(new Card);
    }

    linearGenerate(cards, fout);

    parallelGenerate(cardsParallel, pout);
    
    fout.close();
    pout.close();

    return 0;
}