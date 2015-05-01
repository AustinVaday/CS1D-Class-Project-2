#include "MainHeader.h"


//findHashKey
string findHashKey(string stadiumNames[], string searchKey, const int SIZE)
{

    unsigned int difference;     //difference is used to store the difference in which the
                                 //levenshtein algorithm produces
    unsigned int minimum = 9999; //Initialized to 9999 so that the first difference computed
                                 //will be replaced
    string hashKey;              //

    for(int index = 0; index < SIZE; index++)
    {
        difference = LevenshteinDistance(stadiumNames[index], searchKey);

        if(difference < minimum)
        {
            hashKey = stadiumNames[index];
            minimum = difference;
        }
        else if(difference == minimum)
        {
                qDebug() << "There was a match in difference" << endl;
        }
    }
    return hashKey;
}
