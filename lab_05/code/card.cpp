#include "card.h"

#include <thread>
#include <chrono>

Card::Card()
{
    // cout << "consttuct\n";
    // a блин тут же лу
}


void Card::generateOwner()
{
    string alphabet("abcdefghijklmnopqrstuvwxyz");
    int len = rand() % 15 + 5;

    string surname;
    for (int i = 0; i < len; i++)
        surname += alphabet[rand() % 26];


    this->ownerSurname = surname;

    len = rand() % 10 + 5;

    string name;
    for(int i = 0; i < len; i++)
        name += alphabet[rand() % 26];

    this->ownerName = name;

    if (name.size() % 2 == 0)
        this->ownerGender = "male";
    else
        this->ownerGender = "female";

}


void Card::generateCard()
{
    int i = rand() % 4;

    switch (i)
    {
        case (0): // MIR
        {
            cartType = "MIR";
            string newNumber("2200-2204");

            for (int j = 0; j < 8; j++)
            {
                if (j % 4 == 0)
                    newNumber += '-';
                
                newNumber += to_string(rand() % 10);
            }

            cartNumber = newNumber;

            break;
        }
        case (1): // VISA
        {
            cartType = "VISA";

            string newNumber("4276");
            for (int j = 0; j < 12; j++)
            {
                if (j % 4 == 0)
                    newNumber += '-';
                
                newNumber += to_string(rand() % 10);
            }

            cartNumber = newNumber;
            break;
        }

        case (2): // MASTERCARD
        {
            cartType = "MASTERCARD";
            string newNumber("5469");
            for (int j = 0; j < 12; j++)
            {
                if (j % 4 == 0)
                    newNumber += '-';
                
                newNumber += to_string(rand() % 10);
            }

            cartNumber = newNumber;
            break;
        }

        case (3):
        {
            cartType = "MAESTRO";
            string newNumber("676");
            for (int j = 3; j < 16; j++)
            {
                if (j % 4 == 0)
                    newNumber += '-';
                
                newNumber += to_string(rand() % 10);
            }

            cartNumber = newNumber;

            break;
        }
    
        default:
            break;
    }


    CVV = rand() % 1000;

}


void Card::dumpFile(ofstream &fout)
{
    fout << ownerSurname << "," << ownerName << "," << ownerGender << "," << 
    cartType << "," << cartNumber << "," << CVV << "\n"; 
}