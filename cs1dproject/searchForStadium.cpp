#include "mainwindow.h"


vector<QString> MainWindow::searchForStadium(string searchKey)
{
    qDebug() << "Entered Search For Stadium" << endl;

    searchPair *                    newPair;
    QMap<QString,stadium>::iterator stadiumIt; //Used to iterate through the hash table
    //Used for levenshteins algorithm
    vector<searchPair>           differenceArray;
    vector<searchPair>::iterator diffIt;
    vector<string>               stadiumNameArray;
    vector<string>::iterator     nameIt;
    vector<QString>               finalList;
    vector<int>::iterator        differenceIt;
    int                          smallestDifferenceIndex = 999;
    string                       temp;


    //Loads all stadium names into vector
    for(stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
    {

        stadiumNameArray.push_back(((*stadiumIt).getStadiumName()).toStdString());
    }

    nameIt = stadiumNameArray.begin();

//    LevenshteinDistance(const string &s1, const string &s2)
    while(nameIt != stadiumNameArray.end())
    {
        newPair = new searchPair;

        newPair->stadiumName = (*nameIt);
        newPair->difference  = LevenshteinDistance(searchKey, (*nameIt));


        differenceArray.push_back((*newPair));
        nameIt++;

        newPair = NULL;
    }


    sort(differenceArray.begin(), differenceArray.end(), less_than_key());

    string stringTemp;
    int     intTemp;



//    diffIt = differenceArray.begin();
//    QMessageBox::information(this, "Search Result", QString::fromStdString((*diffIt).stadiumName));
    for(diffIt = differenceArray.begin(); diffIt != differenceArray.end(); diffIt++)
    {
        stringTemp = (*diffIt).stadiumName;
        intTemp    = (*diffIt).difference;

        finalList.push_back(QString::fromStdString(stringTemp));
        qDebug() << QString::number(intTemp);
        qDebug() << QString::fromStdString(stringTemp) <<  endl;
    }

    return finalList;

 }
