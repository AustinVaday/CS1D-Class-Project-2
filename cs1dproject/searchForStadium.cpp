#include "mainwindow.h"



stadium MainWindow::searchForStadium(string searchKey)
{



    QHash<QString,stadium>::iterator stadiumIt; //Used to iterate through the hash table
    //Used for levenshteins algorithm
    vector<int>               differenceArray;
    vector<string>            stadiumNameArray;
    vector<string>::iterator  nameIt;
    vector<int>::iterator     differenceIt;
    int                       smallestDifferenceIndex = 999;
    string                    temp;

    //Loads all stadium names into vector
    for(stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
    {
        stadiumNameArray.push_back(((*stadiumIt).getStadiumName()).toStdString());
    }

    nameIt = stadiumNameArray.begin();

//    LevenshteinDistance(const string &s1, const string &s2)
    while(nameIt != stadiumNameArray.end())
    {

        differenceArray.push_back(LevenshteinDistance(searchKey, (*nameIt)));
        nameIt++;
    }

    for(differenceIt  = differenceArray.begin(), nameIt = stadiumNameArray.begin();
        differenceIt != differenceArray.end(),   nameIt != stadiumNameArray.end();
        differenceIt++ , nameIt++)
    {

    }
}
