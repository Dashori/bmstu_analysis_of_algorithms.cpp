#ifndef GEN_CARDS
#define GEN_CARDS

#include "card.h"

#include <algorithm>
#include <queue>

#include <chrono>
#include <fstream>
#include <thread>

using namespace std::chrono;

void linearGenerate(vector<shared_ptr<Card> > &cards, ofstream &fout);
void parallelGenerate(vector<shared_ptr<Card> > &cards, ofstream &fout);

#endif // GEN_CARDS