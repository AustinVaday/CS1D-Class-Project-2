#ifndef STADIUM_H
#define STADIUM_H

#include <QString>
#include "souvenirs.h"
#include "MainHeader.h"
#include <vector>

class stadium
{
public:
    //Constructor
    stadium();
    //Destructor
    ~stadium();
    stadium (int stadiumNum,
             QString stadiumName,
             QString teamName,
             QString street,
             QString city,
             QString state,
             int zipCode,
             QString boxOfficeNum,
             QString dateOpened,
             QString capacity,
             QString league,
             QString surface,
             vector<vertexEdgeStruct> vertexEdgeVector
             );

    //Accessors
    QString getStadiumName();
    QString getTeamName();
    QString getCity();
    QString getState();
    QString getPlayingSurface();
    int getStadiumNumber();
    vector<vertexEdgeStruct> getVertexEdgeStructVector();
    //getDate()
    //    bool getVisited();

    // should pass by const reference, but does
    // not work with this implementation because
    // the accessors are not const.....
    bool operator==(stadium& otherStadium);

    // overloaded extraction operator to display some data..
    friend QDebug operator<<(QDebug out, stadium& displayStadium);

    //Mutators
    void setStadiumName(QString stadiumName);
    void setStadiumNumber(int number);
    void setTeamName(QString teamName);
    //void setDateOpened();
    void setPlayingSurface(QString grassType);
    void setCity(QString city);
    void setState(QString state);
    //    void setVisited(bool visited);
    //void resetTrip()

private:
    int               stadiumNumber;
    QString           stadiumName;
    QString           teamName;
    QString           street;
    QString           city;
    QString           state;
    int               zip;
    QString           boxOfficeNum;
    QString           dateOpened;
    QString           capacity;
    QString           league;
    QString           surface;
    vector<vertexEdgeStruct> vertexEdgeVector;

    //    vector<souvenirs> souvenirList;




    //    bool              visited;


};



#endif // STADIUM_H
