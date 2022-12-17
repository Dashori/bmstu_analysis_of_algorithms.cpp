#ifndef CARD
#define CARD

#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

enum gender {male, female};

class Card
{
    private:
        string ownerName;
        string ownerSurname;
        string ownerGender;

        string cartType;
        string cartNumber;
        int CVV;
    public:
        Card(/* args */);
        ~Card() = default;

        void generateOwner();
        void generateCard();
        void dumpFile(ofstream &fout);
};


#endif // CARD