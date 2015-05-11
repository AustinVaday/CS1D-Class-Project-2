#include "mainwindow.h"



stadium MainWindow::searchForStadium(QString searchKey)
{

    QHash<QString,stadium>::iterator stadiumIt; //Used to iterate through the hash table
    //Used for levenshteins algorithm
    vector<int>     differenceArray;
    vector<QString> stadiumNameArray;
    vector<QString>::iterator nameIt;

    //Loads all stadium names into vector
    for(stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
    {
        stadiumNameArray.push_back((*stadiumIt).getStadiumName());
    }

    nameIt = stadiumNameArray;

//    LevenshteinDistance(const string &s1, const string &s2)
    while(nameIt != stadiumArray.end())
    {

        differenceArray.push_back(LevenshteinDistance(searchKey, (*nameIt)));

        nameIt++;
    }


}
